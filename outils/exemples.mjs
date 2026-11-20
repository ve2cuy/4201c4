// Prépare les exemples « Ouvrir avec VS Code » des notes de cours (dossier exemples/).
//
// L'extension Simulateur Arduino Grove télécharge un exemple à partir de ce site :
// elle lit exemples/index.json, puis chacun des fichiers listés dans « fichiers ».
// Ce script tient cette liste à jour, et compile le firmware de chaque exemple
// pour que la simulation démarre dès l'ouverture, sans attendre une compilation.
//
//   node outils/exemples.mjs                    met à jour la liste des fichiers
//   node outils/exemples.mjs --compiler         compile aussi tous les exemples
//   node outils/exemples.mjs --compiler <id>    compile seulement celui-là
//
// La compilation se fait dans une copie temporaire : le dossier de l'exemple ne
// reçoit ni dossier .pio ni fichier de logs. PlatformIO doit être installé.
//
// Pour AJOUTER un exemple :
//   1. créer exemples/<id>/ avec platformio.ini, src/main.cpp et circuit.json
//      (le montage : le plus simple est de le faire dans le simulateur, puis de
//      copier le circuit.json du projet);
//   2. ajouter son entrée dans exemples/index.json (id, titre, dossier, environnement);
//   3. node outils/exemples.mjs --compiler <id>;
//   4. dans la note de cours, ajouter le lien :
//      [Ouvrir avec VS Code](vscode://ve2cuy.simulateur-arduino-grove/exemple/<id>)

import { spawnSync } from 'node:child_process';
import { copyFileSync, cpSync, existsSync, mkdtempSync, readFileSync, readdirSync, rmSync, writeFileSync } from 'node:fs';
import { homedir, tmpdir } from 'node:os';
import { join, relative, sep } from 'node:path';

const racine = join(import.meta.dirname, '..', 'exemples');
const fichierIndex = join(racine, 'index.json');
const index = JSON.parse(readFileSync(fichierIndex, 'utf8'));

// Ce que l'extension accepte de télécharger (voir src/catalogue.ts de l'extension).
const RACINES_PERMISES = ['platformio.ini', 'circuit.json', 'montage.json', 'firmware.hex', 'src', 'include', 'lib'];

function trouverPio() {
  const windows = process.platform === 'win32';
  const coeur = process.env.PLATFORMIO_CORE_DIR ?? join(homedir(), '.platformio');
  const local = join(coeur, 'penv', windows ? 'Scripts' : 'bin', windows ? 'pio.exe' : 'pio');
  return existsSync(local) ? local : 'pio';
}

/** Les fichiers d'un exemple, en chemins relatifs avec des « / », triés. */
function listerFichiers(dossier) {
  const fichiers = [];
  const parcourir = (courant) => {
    for (const entree of readdirSync(courant, { withFileTypes: true })) {
      const chemin = join(courant, entree.name);
      if (entree.name.startsWith('.')) {
        continue; // .pio, .vscode, .gitignore : jamais téléchargés
      }
      if (entree.isDirectory()) {
        parcourir(chemin);
      } else {
        fichiers.push(relative(dossier, chemin).split(sep).join('/'));
      }
    }
  };
  parcourir(dossier);
  return fichiers.filter((f) => RACINES_PERMISES.includes(f.split('/')[0])).sort();
}

const args = process.argv.slice(2);
const compiler = args.includes('--compiler');
const demandes = args.filter((a) => a !== '--compiler');
const inconnus = demandes.filter((id) => !index.exemples.some((exemple) => exemple.id === id));
if (inconnus.length > 0) {
  console.error(`Exemple(s) inconnu(s) : ${inconnus.join(', ')}`);
  process.exit(1);
}

let echecs = 0;
for (const exemple of index.exemples) {
  const source = join(racine, exemple.id);
  if (compiler && (demandes.length === 0 || demandes.includes(exemple.id))) {
    const copie = mkdtempSync(join(tmpdir(), `exemple-${exemple.id}-`));
    try {
      cpSync(source, copie, { recursive: true, filter: (fichier) => !fichier.endsWith('firmware.hex') });
      console.log(`\n=== ${exemple.id} (${exemple.environnement}) ===`);
      const resultat = spawnSync(trouverPio(), ['run', '-d', copie, '-e', exemple.environnement], { stdio: 'inherit' });
      if (resultat.status !== 0) {
        console.error(`La compilation de « ${exemple.id} » a échoué.`);
        echecs++;
      } else {
        copyFileSync(join(copie, '.pio', 'build', exemple.environnement, 'firmware.hex'), join(source, 'firmware.hex'));
        console.log(`Firmware rangé dans exemples/${exemple.id}/firmware.hex`);
      }
    } finally {
      rmSync(copie, { recursive: true, force: true });
    }
  }
  exemple.fichiers = listerFichiers(source);
  if (!exemple.fichiers.includes('firmware.hex')) {
    console.warn(`Attention : ${exemple.id} n'a pas de firmware.hex (node outils/exemples.mjs --compiler ${exemple.id})`);
  }
}

writeFileSync(fichierIndex, `${JSON.stringify(index, null, 2)}\n`);
console.log(`exemples/index.json : ${index.exemples.length} exemple(s), liste des fichiers à jour.`);
process.exit(echecs > 0 ? 1 : 0);
