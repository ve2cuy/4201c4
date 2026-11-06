# Guide d'entretien du site 420-1C4

Le site <https://ve2cuy.github.io/4201c4/> est construit par GitHub Pages (Jekyll) à chaque
poussée sur `main`. Il n'y a rien à installer : on modifie des fichiers, on pousse, et le site se
met à jour en une ou deux minutes.

## Où se trouve quoi

| Fichier ou dossier | Rôle |
|---|---|
| `index.md` | L'accueil : présentation du cours, enseignant, titres des sections A à E |
| `_data/documents.yml` | **La liste des documents de l'accueil** (une carte par document) |
| `_includes/dessins/*.svg` | Les dessins des cartes, un fichier par dessin |
| `_includes/documents.html` | Le gabarit qui fabrique les cartes (normalement, on n'y touche pas) |
| `Documents/*.md` | Le contenu des documents, en Markdown |
| `images/` | Les images utilisées dans les documents |
| `_layouts/default.html` | L'en-tête, la bannière, le tableau de bord et le pied de page |
| `assets/css/ve2cuy.css`, `assets/css/cours.css` | Le thème (couleurs, mode clair et sombre, mise en page) |
| `assets/data/sessions.json` | Le calendrier de la session, pour le tableau de bord |
| `README.md` | La page du dépôt sur github.com; **elle n'apparaît plus sur le site** |
| `outils/` | L'aperçu local (`outils/apercu.sh`), non publié |

## Modifier le contenu d'un document

Ouvrir le fichier dans `Documents/`, par exemple `Documents/RTC-DS1307.md`, le modifier en
Markdown, puis pousser. La page garde le thème toute seule.

Pour une image, la déposer dans `images/` et y faire référence depuis le document :

```markdown
<img src="../images/mon-montage.jpg" alt="Le montage du laboratoire" width="400" />
```

ou

```markdown
![Le montage du laboratoire](../images/mon-montage.jpg)
```

Le `../` est nécessaire parce que les documents sont dans `Documents/` et les images à côté.

## Ajouter un document

1. Créer la page, par exemple `Documents/Capteur-ultrasons.md`, qui commence par son titre :

   ```markdown
   # Capteur d'ultrasons

   Le texte du document…
   ```

2. Ajouter sa carte dans `_data/documents.yml`, **à l'endroit où elle doit paraître** (les cartes
   s'affichent dans l'ordre du fichier) :

   ```yaml
   - section: "capteurs"
     numero: "29"
     titre: "Capteur d'ultrasons"
     fichier: "Documents/Capteur-ultrasons.md"
     dessin: "mouvement"
     option: "TP02"
   ```

3. Pousser. La carte apparaît dans la section C, avec le dessin `mouvement` et l'étiquette « TP02 ».

### Les champs d'une carte

| Champ | Obligatoire | Effet |
|---|---|---|
| `section` | oui | `plan` (A), `bases` (B), `capteurs` (C), `projet` (D) ou `ressources` (E) |
| `titre` | oui | Le texte de la carte |
| `dessin` | non | Un nom de fichier de `_includes/dessins/`, sans `.svg` (sinon : `document`) |
| `numero` | non | Le numéro affiché; sans numéro, la carte affiche « + » (document d'appoint) |
| `fichier` | non | `Documents/Nom.md`, un PDF (`Documents/plan.pdf`) ou une adresse `https://…`; sans fichier, la carte est grisée avec la mention « sans page » |
| `option` | non | Petite étiquette : `TP02`, `optionnel`, `optionnel · défi TP02`… |
| `notes` | non | Une ligne de détails en petit sous le titre |

Toujours mettre les valeurs entre guillemets doubles. Une apostrophe à l'intérieur ne pose pas de
problème (`"Capteur d'ultrasons"`); un guillemet double s'écrit `\"`.

### Exemples

Un document d'appoint sans numéro, placé juste après le document 03 :

```yaml
- section: "bases"
  titre: "Installer les pilotes USB"
  fichier: "Documents/Pilotes-USB.md"
  dessin: "carte-arduino"
```

Un document prévu, sans page pour l'instant :

```yaml
- section: "capteurs"
  numero: "30"
  titre: "Écran OLED"
  dessin: "lcd"
  option: "à venir"
```

Un lien vers une page extérieure :

```yaml
- section: "capteurs"
  numero: "22"
  titre: "Détecteur de mouvements"
  fichier: "https://ve2cuy.com/420-1c4/index.php/detecteur-de-mouvements/"
  dessin: "mouvement"
```

## Modifier, déplacer ou retirer une carte

- **Changer un titre, un numéro ou une étiquette :** modifier le bloc dans `_data/documents.yml`.
- **Changer l'ordre :** déplacer le bloc entier plus haut ou plus bas dans le fichier.
- **Changer de section :** modifier `section:`, puis déplacer le bloc parmi ceux de sa nouvelle section.
- **Retirer une carte :** supprimer son bloc. La page `Documents/…md` reste en ligne tant que le
  fichier existe; la supprimer aussi si elle ne doit plus être accessible.
- **Le projet de session (section D)** s'affiche en deux grandes cartes; ses blocs se modifient de
  la même façon (`numero: "A"`, `numero: "B"`).

## Les dessins

Dessins disponibles (`_includes/dessins/`) :

`accolades`, `bande-del`, `bits`, `bouton`, `carte-arduino`, `copier-coller`, `coupe`, `document`,
`eeprom`, `horloge`, `infrarouge`, `lcd`, `liste`, `livres`, `microcontroleur`, `minuterie`,
`mouvement`, `oeil`, `potentiometre`, `resistance-del`, `rfid`, `solutions`, `structure`,
`terminal`, `thermometre`, `uart`, `wifi`.

Les couleurs alternent d'elles-mêmes d'une carte à l'autre (cyan, mauve, ambre, vert, rouge).

### Ajouter un dessin

Créer `_includes/dessins/mon-dessin.svg` contenant **seulement les formes**, sans la balise
`<svg>` (le gabarit l'ajoute). Le dessin occupe une surface de 200 × 100, trait de 2,5, sans
remplissage, et prend la couleur de la carte :

```html
<rect x="70" y="26" width="60" height="48" rx="6"/><path d="M80 26v-9M120 26v-9"/>
```

Puis l'utiliser avec `dessin: "mon-dessin"`. Les formes simples (`rect`, `circle`, `path`) en
lignes rendent le mieux; s'inspirer des dessins existants.

## Les sections de l'accueil

Les titres et les textes de présentation et de l'enseignant sont dans `index.md`. Chaque section
de documents y appelle le gabarit, par exemple :

```liquid
{% raw %}{% include documents.html section="capteurs" couleur="c-green" %}{% endraw %}
```

Pour ajouter une section F (par exemple i86) :

1. Dans `index.md`, copier une section (`<section class="bloc" id="…">` jusqu'à `</section>`),
   lui donner un nouvel `id` (par exemple `i86`), un titre, la lettre `F`, et
   `section="i86"` dans l'appel du gabarit.
2. Dans `_data/documents.yml`, ajouter les cartes avec `section: "i86"`.
3. Facultatif : ajouter une vignette dans la rangée du haut d'`index.md` (bloc `<a class="tile">`).

## Le tableau de bord de la session

Il lit `assets/data/sessions.json` (jours de classe et numéros de semaine de chaque session). À
chaque nouvelle session, refaire ce fichier avec l'outil du site ve2cuy.com
(`ve2cuy-site/tools/calendrier.py`, voir son README) à partir du PDF du calendrier du Cégep, puis
copier le même `sessions.json` ici.

Pour vérifier une date précise : <https://ve2cuy.github.io/4201c4/?date=2027-03-31>.

## Aperçu local (valider avant de publier)

Le script `outils/apercu.sh` construit et sert le site sur le Mac avec la **même version de
Jekyll que GitHub Pages**, pour voir le résultat avant de pousser.

### Une seule fois

Installer Ruby par Homebrew (le Ruby fourni avec macOS est trop ancien) :

```bash
brew install ruby
```

Au premier lancement, le script installe lui-même les gemmes de GitHub Pages dans
`~/.gem/pages` (quelques minutes; rien n'est installé dans le système).

### À chaque séance

Depuis le dossier du dépôt :

```bash
outils/apercu.sh
```

puis ouvrir <http://127.0.0.1:4000/4201c4/>. Le `/4201c4/` est nécessaire, comme sur GitHub
Pages. À chaque fichier enregistré (un document, `_data/documents.yml`, un dessin…), le site se
reconstruit en moins d'une seconde et la page ouverte se recharge seule. **Ctrl+C** arrête
l'aperçu.

Autres usages :

| Commande | Effet |
|---|---|
| `outils/apercu.sh 4001` | Aperçu sur un autre port (si 4000 est déjà pris) |
| `outils/apercu.sh --build` | Construit seulement le site dans `_site/` et s'arrête : pratique pour vérifier qu'il n'y a pas d'erreur avant de pousser |

Le tableau de bord se teste aussi en local : <http://127.0.0.1:4000/4201c4/?date=2027-03-31>.

### Le contenu d'`outils/`

| Fichier | Rôle |
|---|---|
| `apercu.sh` | Le script : prépare Ruby, installe les gemmes au besoin, construit et sert le site |
| `Gemfile` | Les gemmes : `github-pages` (la même version de Jekyll que GitHub) et quelques bibliothèques retirées du Ruby récent |
| `apercu.yml` | Les extensions que GitHub Pages active d'office (pages Markdown sans en-tête, liens `.md` convertis en `.html`, titres tirés du premier titre) |
| `ruby4-compat.rb` | Comble l'écart entre ce Jekyll et le Ruby récent (méthodes `tainted?` et `untaint` retirées) |

### Ce qu'il faut savoir

- `_site/` (le site construit) et `.jekyll-cache/` ne vont pas dans Git (`.gitignore`).
- Une erreur dans `_data/documents.yml` ou dans un document s'affiche dans le terminal, avec le
  nom du fichier : la corriger, enregistrer, et l'aperçu repart.
- Le dossier `outils/` (le script, sa configuration et son `Gemfile`) n'est pas publié sur le site.
- Ce Jekyll est plus ancien que le Ruby de Homebrew : `outils/ruby4-compat.rb` et les gemmes
  supplémentaires du `Gemfile` comblent l'écart, pour l'aperçu seulement. GitHub, lui, construit
  le site dans son propre environnement.
- Dans de rares cas, une différence peut apparaître entre l'aperçu et le site publié : vérifier le
  site en ligne après chaque publication importante.

## Publier

```bash
git add -A
git commit -m "Ajout du document 29 : capteur d'ultrasons"
git push
```

Le site se met à jour en une ou deux minutes (onglet **Actions** du dépôt pour suivre). Faire
Cmd+Maj+R dans le fureteur pour voir la nouvelle version.

Si GitHub envoie un courriel « deploy failed » alors que l'étape **build** a réussi, c'est
presque toujours un délai dépassé de son côté : dans **Actions**, ouvrir l'exécution et cliquer
**Re-run failed jobs**, ou simplement pousser le commit suivant.

Si l'étape **build** échoue, c'est en général une erreur de syntaxe dans `_data/documents.yml`
(guillemet ou indentation) : le message de l'onglet **Actions** donne la ligne fautive.
