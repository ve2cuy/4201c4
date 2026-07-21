## 1. Comprendre l'adressage physique

Au reset, le CPU x86 démarre toujours à l'adresse physique **`0xFFFFF0`** (en mode réel 16 bits, ça correspond à `CS:IP = F000:FFF0`). Le BIOS doit donc se trouver mappé de façon à ce que cette adresse contienne un saut valide vers votre code d'initialisation.

Pour une ROM de **16 Ko (0x4000 octets)** finissant exactement à `0xFFFFF`, elle occupe la plage :

```
0xFFFFF - 0x4000 + 1 = 0xFC000   →   début de la ROM
0xFFFFF                          →   fin de la ROM
```

Le vecteur de reset à `0xFFFF0` correspond donc, **à l'intérieur de votre fichier binaire**, à l'offset :

```
0xFFFF0 - 0xFC000 = 0x3FF0
```

C'est-à-dire **16 octets avant la fin du fichier** (`0x4000 - 0x3FF0 = 0x10`). C'est exactement le schéma qu'utilisent les vrais BIOS.

## 2. Structure du fichier source

```asm
.MODEL TINY
.CODE
ORG 0

;==========================================
; Point d'entrée réel du BIOS (POST)
;==========================================
POST:
    CLI
    MOV     AX, CS
    MOV     DS, AX
    MOV     ES, AX
    MOV     SS, AX
    MOV     SP, 0FFFEh

    ; ... votre code d'initialisation (contrôleurs, mémoire, etc.)

    JMP     $                       ; boucle infinie temporaire (halte)

;==========================================
; Vecteur de reset : offset 0x3FF0
; = adresse physique 0xFFFF0
;==========================================
ORG 3FF0h
Reset:
    JMP     FAR PTR POST            ; saut FAR pour forcer CS=F000

;==========================================
; Zone d'identification BIOS (optionnel,
; convention historique type date/ID)
;==========================================
ORG 3FF5h
    DB      '01/01/26', 0           ; date de build, 8 caractères + null

;==========================================
; Remplissage jusqu'à exactement 16 Ko
;==========================================
ORG 3FFFh
    DB      0FFh                    ; dernier octet, force la taille totale

END
\\\

### Points clés

- **`ORG 0`** en tête : le premier octet du fichier binaire correspond à l'offset `0x0000` = adresse physique `0xFC000`.
- **`ORG 3FF0h`** repositionne le compteur de localisation à l'offset du vecteur de reset. JWasm (comme MASM) remplit automatiquement l'écart entre le code précédent et ce nouvel offset avec des zéros.
- **`JMP FAR PTR POST`** : un saut FAR est important ici. Bien que `CS` soit déjà `F000` au reset, un saut FAR recharge explicitement `CS:IP`, ce qui est la convention BIOS standard (utile aussi si votre code fait ensuite des manipulations de segment).
- **`ORG 3FFFh` + `DB 0FFh`** : force le fichier à faire exactement `0x4000` = 16384 octets, même si JWasm tronquerait autrement les zéros de fin.

## 3. Compilation

\\\powershell
..\JWasm.exe -bin bios.asm
ren bios.BIN bios.com
\\\

## 4. Vérifiez la taille exacte

\\\powershell
(Get-Item bios.com).Length
\\\

Vous devez obtenir **16384**. Si ce n'est pas le cas (souvent parce que JWasm tronque les zéros finaux malgré le `ORG`), forcez la taille avec PowerShell :

\\\powershell
$stream = [System.IO.File]::Open("bios.com", 'Open', 'Write')
$stream.SetLength(16384)
$stream.Close()
\\\

## 5. Tester dans un émulateur

DOSBox **ne convient pas** pour tester un BIOS (il émule DOS, pas le firmware système). Il vous faut un émulateur PC complet avec ROM personnalisable, comme **Bochs** ou **QEMU**.

**Avec Bochs**, dans votre `bochsrc.txt` :
\\\
romimage: file="bios.com", address=0xfc000
\\\

**Avec QEMU** :
\\\powershell
qemu-system-i386 -bios bios.com
\\\
⚠️ QEMU exige souvent une taille de BIOS parmi certaines valeurs standard (128 Ko, 256 Ko...) selon la version — 16 Ko peut être refusé. Bochs est généralement plus permissif pour ce genre d'expérimentation.

---

# Configuration de Bochs pour tester votre BIOS

## 1. Installation de Bochs

Téléchargez la version Windows depuis le site officiel :

```
https://bochs.sourceforge.io/
```

Prenez le package d'installation Windows (`.exe`), installez-le normalement (ex. dans `C:\Program Files\Bochs-2.x`).

## 2. Structure de dossier recommandée

```
C:\bochs-test\
    bios.com          (votre BIOS compilé, renommé en .bin de préférence)
    bochsrc.txt        (fichier de configuration)
```

Astuce : renommez `bios.com` en `bios.bin` pour éviter toute confusion, puisqu'il ne s'agit plus d'un exécutable DOS mais d'une image ROM brute.

```powershell
copy bios.com bios.bin
```

## 3. Fichier de configuration `bochsrc.txt`

Voici une configuration minimale adaptée à votre BIOS 16 Ko custom :

```
# ------------------------------
# Configuration Bochs - Test BIOS custom
# ------------------------------

# CPU émulé
cpu: model=core2_duo, count=1, ips=1000000

# Mémoire RAM (en Mo)
megs: 16

# Votre BIOS personnalisé, mappé à l'adresse physique correcte
romimage: file="bios.bin", address=0xfc000

# BIOS vidéo standard (nécessaire même avec un BIOS custom,
# sauf si vous gérez vous-même l'affichage bas niveau)
vgaromimage: file=$BXSHARE/VGABIOS-lgpl-latest

# Pas de disque dur ni de disquette pour un premier test
floppya: type=none
ata0: enabled=0

# Affichage
display_library: win32

# Log des évènements (utile pour déboguer)
log: bochsout.txt
panic: action=ask
error: action=report
info: action=ignore
debug: action=ignore

# Vitesse d'exécution (optionnel, pour ralentir et observer)
clock: sync=none, time0=local
```

### Points importants

- **`romimage: file="bios.bin", address=0xfc000`** : c'est la ligne clé — elle mappe exactement votre BIOS à l'adresse physique `0xFC000`, cohérente avec les `ORG` de votre code.
- **`vgaromimage`** : Bochs a besoin d'un BIOS vidéo pour afficher quoi que ce soit à l'écran, même si votre propre BIOS ne s'en sert pas encore. Le chemin `$BXSHARE` pointe vers le dossier d'installation de Bochs (généralement rempli automatiquement si vous utilisez l'assistant de configuration).
- **`megs: 16`** : quantité de RAM émulée, ajustable selon vos besoins.

## 4. Lancer Bochs

Depuis l'invite de commandes, dans le dossier contenant `bochsrc.txt` :

```powershell
cd C:\bochs-test
"C:\Program Files\Bochs-2.x\bochs.exe" -f bochsrc.txt
```

Une fenêtre Bochs devrait s'ouvrir avec un menu de démarrage (Bochs affiche généralement un petit menu interactif au lancement — appuyez sur Entrée ou choisissez "Start" pour démarrer l'émulation).

## 5. Déboguer votre BIOS

Bochs inclut un débogueur intégré très utile pour un projet comme le vôtre :

```powershell
"C:\Program Files\Bochs-2.x\bochsdbg.exe" -f bochsrc.txt
```

Commandes utiles dans le débogueur Bochs :

```
c              → continue l'exécution
s              → step (une instruction à la fois)
r              → affiche les registres
b 0xfc000      → pose un point d'arrêt à une adresse physique
xp /10i 0xfc000  → désassemble 10 instructions à partir de 0xFC000
```

Ceci est particulièrement utile pour vérifier que votre `JMP FAR PTR POST` à `0xFFFF0` s'exécute correctement et saute bien au bon endroit.

## 6. Résultat attendu

Si tout est correctement configuré, au démarrage vous devriez voir Bochs charger votre ROM à la bonne adresse, exécuter le saut du vecteur de reset, puis entrer dans votre routine `POST`. Si votre code POST ne fait encore qu'une boucle infinie (`JMP $`), c'est normal — c'est le comportement attendu à ce stade de développement, ça confirme juste que l'exécution démarre bien au bon endroit.

---

## Exemple d'affichage via le buffer VGA

# Affichage de texte via accès direct au buffer VGA

C'est l'approche la plus "bas niveau" possible — parfaitement adaptée à un BIOS, puisqu'à ce stade du démarrage, **les interruptions BIOS vidéo (`INT 10h`) n'existent pas encore** (elles font partie du BIOS que vous êtes en train d'écrire !). Vous ne pouvez donc compter que sur l'accès direct au matériel.

## 1. Comprendre le buffer VGA en mode texte

En mode texte VGA standard (mode 3, 80x25 caractères), le contrôleur vidéo lit en permanence la mémoire à partir de l'adresse physique :

```
0xB8000
```

Chaque caractère affiché occupe **2 octets consécutifs** :

```
Octet 1 : code ASCII du caractère
Octet 2 : attribut (couleur texte + couleur fond)
```

L'attribut se décompose en un octet :

```
Bits 7-4 : couleur de fond (4 bits)
Bits 3-0 : couleur de texte (4 bits)
```

Exemple : `0x07` = texte gris clair (7) sur fond noir (0) — c'est la couleur par défaut classique.

Autres valeurs utiles :

```
0x0F = blanc vif sur noir
0x1F = blanc vif sur bleu
0x4E = jaune sur rouge (attire l'attention, utile pour erreurs)
```

## 2. Calcul de position à l'écran

Pour placer un caractère à la colonne `X`, ligne `Y` (en partant de 0,0 en haut à gauche) :

```
offset = (Y * 80 + X) * 2
```

Puisque chaque ligne fait 80 colonnes, et chaque caractère prend 2 octets.

## 3. Code assembleur complet

Voici un exemple intégré à la structure de votre BIOS, qui affiche "Hello BIOS!" en haut à gauche de l'écran :

```asm
.MODEL TINY
.CODE
ORG 0

VGA_SEG     EQU     0B800h      ; segment du buffer VGA (mode texte)
ATTR_NORM   EQU     07h         ; gris clair sur noir

;==========================================
; Point d'entrée réel du BIOS (POST)
;==========================================
POST:
    CLI
    MOV     AX, CS
    MOV     DS, AX
    MOV     SS, AX
    MOV     SP, 0FFFEh

    ; Pointer ES vers le segment du buffer VGA
    MOV     AX, VGA_SEG
    MOV     ES, AX

    ; Afficher notre message à l'écran (ligne 0, colonne 0)
    MOV     DI, 0                   ; offset de départ = (0*80+0)*2 = 0
    MOV     SI, OFFSET MSG
    CALL    PrintString

    JMP     $                       ; boucle infinie (halte)

;==========================================
; PrintString : affiche une chaîne DS:SI
; terminée par 0, à partir de ES:DI
;==========================================
PrintString:
    PUSH    AX
.next_char:
    MOV     AL, [SI]                ; charge le caractère
    CMP     AL, 0                   ; fin de chaîne ?
    JE      .done
    MOV     [ES:DI], AL             ; écrit le caractère
    MOV     BYTE PTR [ES:DI+1], ATTR_NORM  ; écrit l'attribut
    ADD     DI, 2                   ; avance de 2 octets (1 caractère)
    INC     SI
    JMP     .next_char
.done:
    POP     AX
    RET

MSG     DB      'Hello BIOS!', 0

;==========================================
; Vecteur de reset : offset 0x3FF0
; = adresse physique 0xFFFF0
;==========================================
ORG 3FF0h
Reset:
    JMP     FAR PTR POST

ORG 3FF5h
    DB      '01/01/26', 0

ORG 3FFFh
    DB      0FFh

END
```

## 4. Points techniques importants

- **Pas besoin d'initialiser la carte VGA** : au démarrage du PC, le firmware/hardware place déjà la carte graphique en mode texte 80x25 par défaut (mode 3) avant même que votre BIOS ne s'exécute — c'est géré au niveau matériel/VGA BIOS intégré à la carte elle-même, pas par votre code. Vous pouvez donc écrire directement dans `0xB8000` sans configuration préalable.

- **`ES` plutôt que `DS`** : par convention, on utilise `ES` pour le segment de destination avec les instructions type `STOSB`/`MOVSB`, mais ici avec un accès manuel `[ES:DI]`, ça reste juste une préférence de lisibilité — vous pourriez utiliser n'importe quel registre de segment.

- **Position à l'écran** : pour afficher ailleurs qu'en haut à gauche, changez simplement `DI` au départ. Par exemple pour ligne 5, colonne 10 :
```asm
  MOV     DI, (5*80+10)*2
```

## 5. Test dans Bochs

Recompilez avec JWasm comme avant :

```powershell
..\JWasm.exe -bin bios.asm
ren bios.BIN bios.bin
```

Relancez Bochs avec la même configuration `bochsrc.txt` que précédemment. Vous devriez voir apparaître **"Hello BIOS!"** en haut à gauche de l'écran émulé, dès le démarrage — c'est une confirmation visuelle très satisfaisante que tout votre pipeline (compilation → placement mémoire → exécution) fonctionne correctement de bout en bout.

