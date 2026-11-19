# Simulateur d'Arduino pour VS Code

*Révision du 2026.11.19*

<p align="center">
  <img src="../images/simulateur-arduino.png" alt="Le panneau du simulateur : un Arduino UNO et son hat Grove, un relais, un bouton, une DEL, un écran LCD, un capteur de température et le moniteur série" width="600" />
</p>

## Contenu

- [**Définition**](#section-definition)
- [**1 – Installer l'extension**](#section-1)
  - [1.1 – Ce qu'il faut déjà avoir](#section-1-1)
  - [1.2 – Télécharger l'extension](#section-1-2)
  - [1.3 – L'installer dans VS Code](#section-1-3)
  - [1.4 – Vérifier l'installation](#section-1-4)
  - [1.5 – Mettre à jour ou désinstaller](#section-1-5)
- [**2 – Premier essai**](#section-2)
  - [2.1 – Les exemples du cours](#section-2-1)
- [**3 – Brancher des modules**](#section-3)
  - [3.1 – Les modules disponibles](#section-3-1)
  - [3.2 – Les ports du hat Grove](#section-3-2)
  - [3.3 – Avec ou sans le hat](#section-3-3)
- [**4 – Le panneau du simulateur**](#section-4)
- [**5 – L'oscilloscope**](#section-5)
  - [5.1 – Observer un signal](#section-5-1)
  - [5.2 – Décoder UART, I2C et PWM](#section-5-2)
  - [5.3 – Le déclenchement](#section-5-3)
  - [5.4 – Mesurer et explorer](#section-5-4)
- [**6 – Deux Arduino reliés par UART**](#section-6)
- [**7 – Le Wi-Fi et l'API du projet de session**](#section-7)
- [**8 – Les fichiers ajoutés au projet**](#section-8)
- [**9 – Limites et dépannage**](#section-9)

---

## Définition {#section-definition}

Le **simulateur d'Arduino** est une extension de VS Code. Il fait tourner le programme compilé par PlatformIO dans un Arduino virtuel, affiché dans un panneau à côté du code : une carte **UNO** ou **MEGA**, son hat Grove, les modules qu'on y branche et le moniteur série. Les cartes et les modules y sont dessinés d'après les vrais : on peut comparer son montage à celui de l'écran.

Le code du projet reste tel quel : c'est le même programme qui sera téléversé dans la vraie carte.

Le simulateur sert à travailler **sans le kit**, à la maison par exemple. Il ne remplace pas le matériel : un montage se valide toujours sur la vraie carte, avec les vrais modules.

---

## 1 – Installer l'extension {#section-1}

### 1.1 – Ce qu'il faut déjà avoir {#section-1-1}

- **VS Code**, version 1.85 ou plus récente.
- L'extension **PlatformIO IDE**, installée comme dans le document [Introduction à PlatformIO](PlatformIO-Hello-world.md) : c'est elle qui compile les projets.

### 1.2 – Télécharger l'extension {#section-1-2}

👉 [**simulateur-arduino-grove-1.1.0.vsix**](../telechargements/simulateur-arduino-grove-1.1.0.vsix) (version 1.1.0, environ 230 Ko)

Enregistrer le fichier dans un dossier facile à retrouver, par exemple `Téléchargements`. Un fichier `.vsix` est une extension de VS Code remise sous forme de fichier, plutôt que par la boutique d'extensions.

### 1.3 – L'installer dans VS Code {#section-1-3}

1. Ouvrir VS Code.
2. Ouvrir la vue des extensions : **Ctrl+Maj+X**.
3. Cliquer sur les trois points **…** en haut à droite de cette vue.
4. Choisir **Install from VSIX…** (« Installer à partir d'un VSIX… » si VS Code est en français).
5. Choisir le fichier `simulateur-arduino-grove-1.1.0.vsix` téléchargé.

VS Code confirme l'installation par un message en bas à droite.

**Autres façons d'arriver au même résultat :**

- Par la palette de commandes : **Ctrl+Maj+P**, puis taper `Extensions: Install from VSIX`.
- Dans un terminal, à partir du dossier où se trouve le fichier :

  ```bash
  code --install-extension simulateur-arduino-grove-1.1.0.vsix
  ```

### 1.4 – Vérifier l'installation {#section-1-4}

1. Dans la vue des extensions, **Simulateur Arduino Grove** apparaît dans la liste des extensions installées.
2. Ouvrir un projet PlatformIO, c'est-à-dire un dossier qui contient le fichier `platformio.ini`.
3. L'icône du simulateur, un petit circuit imprimé, apparaît **en haut à droite de l'éditeur**.

💡 L'icône n'apparaît que si le dossier ouvert contient un fichier `platformio.ini`.

### 1.5 – Mettre à jour ou désinstaller {#section-1-5}

- **Mettre à jour** : télécharger la nouvelle version sur cette page et refaire l'étape 1.3. La nouvelle version remplace l'ancienne. Le numéro de la version installée est affiché dans la vue des extensions.
- **Désinstaller** : dans la vue des extensions, cliquer sur la roue dentée de **Simulateur Arduino Grove**, puis sur **Uninstall** (« Désinstaller »).

---

## 2 – Premier essai {#section-2}

1. Ouvrir le projet du document [Introduction à PlatformIO](PlatformIO-Hello-world.md#section-5), celui qui fait clignoter la DEL de la broche 13.
2. **Compiler** le projet : **Ctrl+Alt+B**.
3. Cliquer sur l'**icône du simulateur**, en haut à droite de l'éditeur.

Le panneau s'ouvre à côté du code :

- le voyant **L** de la carte clignote, comme la DEL de la broche 13 de la vraie carte;
- le **moniteur série**, au bas du panneau, affiche ce que le programme envoie par `Serial.print()`. On peut aussi y taper : les touches sont envoyées au programme.

👉 Modifier le délai dans le code, recompiler (**Ctrl+Alt+B**) et observer : la carte **redémarre toute seule** avec le nouveau programme. Il n'y a rien à téléverser.

💡 Le bouton **Reset** relance le programme **déjà compilé** : il ne recompile pas. Après une modification du code, le bouton **Recompiler** apparaît dans l'en-tête de la carte pour le rappeler.

Les mêmes actions se trouvent dans la palette de commandes (**Ctrl+Maj+P**), sous « Simulateur Arduino » :

| Commande | Effet |
|----------|-------|
| Afficher le simulateur | Ouvre le panneau |
| Démarrer la simulation | Lance le programme déjà compilé |
| Compiler et simuler | Enregistre les fichiers, compile, puis lance la simulation |
| Ouvrir un exemple du cours… | Crée le projet d'un exemple de ces notes, avec son montage, et l'ouvre dans le simulateur |

### 2.1 – Les exemples du cours {#section-2-1}

Les exemples des notes de cours sont livrés avec le simulateur, **montage compris** :

1. lancer la commande **Simulateur Arduino : Ouvrir un exemple du cours…** de la palette (**Ctrl+Maj+P**), ou cliquer sur le bouton **Exemples…** du panneau;
2. choisir l'exemple dans la liste;
3. choisir le dossier où créer le projet, par exemple `Documents/PlatformIO/Projects`.

Le projet s'ouvre et la simulation démarre aussitôt : le programme est fourni déjà compilé. C'est un projet PlatformIO ordinaire, à modifier et à recompiler à votre guise.

| Exemple | Dans les notes |
|---------|----------------|
| Hello World avec une DEL | [Introduction à PlatformIO, section 5.1](PlatformIO-Hello-world.md#section-5-1) |
| Hello World avec des macros | [Introduction à PlatformIO, section 5.2](PlatformIO-Hello-world.md#section-5-2) |

💡 Un dossier qui existe déjà n'est jamais remplacé : le simulateur propose de l'ouvrir, ou de créer une copie.

---

## 3 – Brancher des modules {#section-3}

Dans la barre du haut du panneau :

1. choisir un module dans la liste **Ajouter un module…**;
2. choisir le **port** du hat où le brancher;
3. cliquer sur **Ajouter**.

Le module apparaît sur le canevas, relié par un câble au connecteur choisi. Le **×** de son en-tête le retire.

### 3.1 – Les modules disponibles {#section-3-1}

| Module | Port | Dans le simulateur |
|--------|------|--------------------|
| DEL rouge, verte, bleue | D | S'allume selon la sortie; son intensité suit `analogWrite()` |
| Bouton | D | Bouton-poussoir : enfoncé tant qu'on tient son capuchon avec la souris |
| Détecteur de mouvement | D | Tenir le dôme du capteur enfoncé simule un mouvement; la sortie reste active 2 secondes |
| Relais, buzzer | D | Le voyant du relais s'allume quand son contact est fermé; le buzzer indique qu'il sonne (sans faire de son) |
| Potentiomètre | A | Un curseur règle la tension lue par `analogRead()`; l'axe du potentiomètre tourne avec lui |
| Afficheur 4-Digit | D | Affiche les chiffres envoyés par la librairie TM1637 |
| RGB LED Stick | D | Les 10 DEL prennent les couleurs envoyées par la librairie NeoPixel |
| LCD RGB | I2C | Le texte et la couleur du rétroéclairage |
| LCD 20x4 I2C | I2C | Écran de 4 lignes de 20 caractères pour la librairie LiquidCrystal_I2C; son adresse (0x27 par défaut) et son contraste se règlent sous l'écran |
| Capteur SHT31 | I2C | Des curseurs règlent la température et l'humidité |
| Capteur BME280 | I2C | Des curseurs règlent la température, l'humidité et la pression |
| Horloge RTC | I2C | Donne l'heure de l'ordinateur, ou celle que le programme a réglée |
| Module Wi-Fi | UART | Se connecte réellement au réseau de l'ordinateur |
| Lecteur RFID | UART | Le bouton « Présenter » passe une carte devant l'antenne du lecteur |

### 3.2 – Les ports du hat Grove {#section-3-2}

Comme sur le vrai hat, un connecteur **Dn** porte deux broches : **Dn** et **Dn+1**. Par exemple, le connecteur D6 porte les broches 6 et 7.

- Un module série branché sur **Dn** se programme avec `SoftwareSerial(Dn, Dn+1)`.
- Les modules I2C partagent le même bus : ils se branchent sur n'importe quel connecteur **I2C**.
- Sur le MEGA, les connecteurs **UART1**, **UART2** et **UART3** correspondent à `Serial1`, `Serial2` et `Serial3`.
- Le hat du MEGA (Grove Mega Shield) a une prise pour deux broches : « D2-D3 », « D4-D5 »… et « A0-A1 », « A2-A3 »… Dans le simulateur comme sur le vrai hat, on choisit donc **D2, D4, D6, D8, D10 ou D12**, et **A0, A2… A14** : il n'y a pas de prise D3 ou A1.

💡 Pour le **LCD 20x4 I2C**, l'adresse choisie sous l'écran doit être celle du programme : `LiquidCrystal_I2C lcd(0x27, 20, 4);`. Sans `lcd.backlight()`, le rétroéclairage reste éteint, comme sur le vrai module.

### 3.3 – Avec ou sans le hat {#section-3-3}

<p align="center">
  <img src="../images/simulateur-sans-hat.png" alt="Un Arduino UNO sans son hat : un bouton avec sa résistance de rappel et deux DEL avec leur résistance, reliés aux broches par des fils; les pistes du circuit s'illuminent" width="420" />
</p>

Le bouton **Hat**, dans l'en-tête de chaque carte, pose ou retire son hat Grove.

- **Avec le hat**, chaque module est relié à sa prise par un câble Grove.
- **Sans le hat**, on voit la carte seule, telle qu'elle sort de sa boîte, et les modules s'y branchent par des **fils** : un pour chaque signal, un rouge pour le 5 V et un gris pour la masse (GND).

Sans le hat, la DEL et le bouton sont dessinés comme des composants nus, avec la **résistance** qu'il leur faut :

| Composant | Résistance | Pourquoi |
|-----------|------------|----------|
| DEL | 220 Ω en série | Elle limite le courant; sans elle, la DEL et la broche de l'Arduino s'abîment |
| Bouton | 10 kΩ entre la broche et la masse (résistance de rappel, *pull-down*) | Elle garde la broche à LOW tant que le bouton est relâché |

Les modules Grove portent déjà ces résistances sur leur circuit : c'est pourquoi on ne les voit pas avec le hat.

Sur la carte seule, les **pistes** du circuit sont tracées, de chaque broche jusqu'à la patte du microcontrôleur. Pendant la simulation, une piste **s'illumine** quand son signal est à HIGH : avec le programme de la section 2, on voit le signal de la broche 13 aller du microcontrôleur à la DEL **L**. Ce tracé est simplifié : le vrai circuit a deux faces et plus de détours.

💡 Les modules gardent leur place quand on pose ou qu'on retire le hat.

---

## 4 – Le panneau du simulateur {#section-4}

| Élément | Rôle |
|---------|------|
| **Pause** | Arrête le temps de la simulation, puis le reprend |
| **Réinitialiser** | Redémarre le programme, comme le bouton RESET de la carte |
| **−**, **%**, **+**, **Tout voir** | Le zoom du canevas; « Tout voir » montre tout le montage. La molette de la souris, au-dessus du canevas, zoome aussi |
| **Ranger…** | Replace tous les modules autour de leur carte, sans chevauchement : à l'horizontale (au-dessus et au-dessous) ou à la verticale (à gauche et à droite). La disposition faite à la main est remplacée |
| **Exemples…** | Ouvre un exemple des notes de cours (section 2.1) |
| **Hat** (dans l'en-tête d'une carte) | Pose ou retire le hat Grove (section 3.3) |
| **☾ Sombre** / **☀ Clair** | Change les couleurs du panneau |
| En-tête d'une carte ou d'un module | Le tenir avec la souris pour déplacer l'élément; les câbles se retracent tout seuls |
| Voyants **ON**, **L**, **TX**, **RX** | Les mêmes que ceux de la vraie carte |
| Sous la carte | L'état de la mémoire EEPROM, et le bouton « Effacer » pour la remettre à neuf |
| **Moniteur série** | Un onglet par carte; le débit est celui de `Serial.begin()` |
| **Côte à côte** | Affiche tous les moniteurs série en même temps |
| **Oscilloscope** | Affiche ou masque l'oscilloscope, à droite du canevas (section 5) |
| La poignée entre le canevas et le moniteur série | La glisser vers le haut ou le bas pour changer la hauteur des deux zones; un double-clic revient au réglage d'origine |
| **Recompiler** (dans l'en-tête d'une carte) | N'apparaît que si le code a été enregistré sans être recompilé : un clic compile le projet et relance la simulation |

La mémoire **EEPROM** garde son contenu d'une simulation à l'autre, comme celle de la vraie carte : voir le document [La mémoire EEPROM](EEPROM.md).

---

## 5 – L'oscilloscope {#section-5}

<p align="center">
  <img src="../images/simulateur-oscilloscope.png" alt="L'oscilloscope du simulateur : la ligne TX décodée en caractères et un signal PWM à 50 %" width="700" />
</p>

Le bouton **Oscilloscope** de la barre du haut affiche, à droite du canevas, un oscilloscope numérique à **quatre voies**. Il montre les signaux tels qu'ils circulent sur les fils : on y voit ce que `Serial.print()`, `analogWrite()` ou la librairie d'un module I2C envoient réellement.

### 5.1 – Observer un signal {#section-5-1}

Sous l'écran, chaque voie a deux listes :

1. la première choisit le **signal** : une broche (`D3`, `A0`…), une ligne série (`TX`, `RX`) ou une ligne du bus I2C (`SDA`, `SCL`);
2. la seconde choisit le **décodeur**, ou « Sans décodage ».

L'échelle verticale est de **1 V par division** : un signal de 5 V couvre cinq divisions. La base de temps (le temps par division) se règle avec les boutons **−** et **+**, ou avec la molette de la souris au-dessus de l'écran.

### 5.2 – Décoder UART, I2C et PWM {#section-5-2}

| Décodeur | Sur quels signaux | Ce qu'il affiche sous la trace |
|----------|-------------------|--------------------------------|
| **UART** | `TX`, `RX`, ou une broche utilisée par SoftwareSerial | Chaque octet : son caractère et sa valeur en hexadécimal. Le débit est trouvé automatiquement, ou choisi dans la liste |
| **I2C** | `SDA` et `SCL` | Le départ (`S`), l'adresse et le sens (`3E W`, `44 R`), les octets, les refus (`NACK`) et l'arrêt (`P`) |
| **PWM** | Une broche pilotée par `analogWrite()` | Le rapport cyclique en %, la valeur d'`analogWrite()` et la fréquence |

Le même décodage est écrit en texte sous l'écran, par exemple `UART 9600 bauds : Bonjour`.

### 5.3 – Le déclenchement {#section-5-3}

Le déclenchement fixe l'image : l'écran se cale sur un événement du signal, repéré par un triangle orange.

- **Front montant**, **front descendant** ou **tout front** : pour un signal ordinaire.
- **Début de transmission UART** : le premier bit de départ après un silence. L'écran montre alors le début de chaque message.
- **Départ I2C** : le début de chaque échange sur le bus.

Le bouton **Auto / Normal** choisit ce que fait l'écran en attendant : en **Auto**, il défile; en **Normal**, il garde la dernière image. **UNIQUE** capture le prochain événement, puis arrête l'acquisition.

### 5.4 – Mesurer et explorer {#section-5-4}

- **MARCHE / ARRÊT** gèle l'écran. À l'arrêt, la molette agrandit le signal **autour de la souris** et les flèches **◀ ▶** le font défiler.
- **Glisser** la souris sur l'écran pose deux curseurs et affiche le temps qui les sépare (ΔT) et la fréquence correspondante. Un double-clic les efface.
- **AUTO** choisit une base de temps adaptée au signal.
- Sous l'écran : le nombre de fronts, la période, la fréquence et la largeur d'impulsion de la voie de déclenchement.

👉 Essayer avec le programme de la section 2 : voie 1 sur `TX` pour lire ce qu'envoie `Serial.print()`, voie 2 sur `D13` pour voir la DEL clignoter.

---

## 6 – Deux Arduino reliés par UART {#section-6}

Le simulateur peut faire tourner **deux cartes en même temps**, par exemple le UNO et le MEGA du projet de session.

1. Réunir les deux projets dans un même **espace de travail** de VS Code : *Fichier → Ajouter un dossier à l'espace de travail…*, puis *Fichier → Enregistrer l'espace de travail sous…*
2. Compiler les deux projets.
3. Ouvrir le simulateur sur le premier projet.
4. Cliquer sur **Ajouter une carte…** et choisir le second projet.
5. Dans la liste **Relier deux cartes…**, choisir le câble, par exemple *UNO D8 ↔ MEGA UART2*.

Pour un câble entre deux cartes branché sur le connecteur **Dn**, le programme utilise `SoftwareSerial(Dn+1, Dn)`. Avec le câble *UNO D8 ↔ MEGA UART2* :

```cpp
// Sur le UNO
SoftwareSerial lienAvecRecepteur(9, 8);   // RX, TX

// Sur le MEGA : le port matériel Serial2
```

Voir le document [Communication UART](Communication-UART-entre-2-arduino.md).

---

## 7 – Le Wi-Fi et l'API du projet de session {#section-7}

Le **module Wi-Fi** simulé ouvre de vraies connexions à partir de votre ordinateur. Le programme du MEGA peut donc envoyer ses requêtes à une vraie API, comme avec le vrai module.

Pour l'API du projet de session lancée sur votre ordinateur avec Docker ([épreuve synthèse, section 7.3](ES-H26-Volet-A.md#section-7-3)), l'adresse à utiliser dans le simulateur est `127.0.0.1` :

```cpp
char server[] = "127.0.0.1";   // Mon ordinateur (Docker), avec le simulateur
```

Quand le montage contient un module Wi-Fi, un onglet **API** s'ajoute à côté des moniteurs série. Il affiche la page de la centrale de surveillance qui tourne dans le conteneur. Si le conteneur ne tourne pas, l'onglet propose de télécharger l'image et de le démarrer; il faut pour cela que **Docker Desktop** soit installé et démarré.

💡 Avec la **carte réelle**, `127.0.0.1` ne fonctionne pas : il faut l'adresse IP de l'ordinateur, comme l'explique la section 7.3.

---

## 8 – Les fichiers ajoutés au projet {#section-8}

Le simulateur enregistre le montage dans le projet, pour le retrouver à la prochaine ouverture :

| Fichier | Contenu |
|---------|---------|
| `circuit.json` | Les modules de la carte, leur port et leur position sur le canevas; le hat, posé ou retiré |
| `montage.json` | Avec deux cartes : les cartes, leur position et le câble qui les relie. Il est à côté du fichier de l'espace de travail |

Ces fichiers font partie du projet : les garder avec le code, dans Git aussi.

---

## 9 – Limites et dépannage {#section-9}

**Ce que le simulateur ne fait pas**

- Le **récepteur infrarouge** n'est pas simulé.
- Le **buzzer** n'émet pas de son : son module indique seulement s'il est actif.
- L'**oscilloscope** montre des signaux logiques (0 V ou 5 V) : il ne trace pas une tension analogique, comme celle du potentiomètre.
- Le module Wi-Fi accepte n'importe quel nom de réseau et n'importe quel mot de passe.
- Sur un ordinateur lent, le temps simulé peut avancer moins vite que le temps réel.

**En cas de problème**

| Ce qui se passe | Quoi faire |
|-----------------|------------|
| L'icône du simulateur n'apparaît pas | Ouvrir le **dossier** du projet (celui qui contient `platformio.ini`), pas seulement un fichier |
| La carte indique « projet non compilé » | Compiler le projet (**Ctrl+Alt+B**) |
| Le programme ne change pas après une modification, même avec **Reset** | Enregistrer et recompiler (**Ctrl+Alt+B**, ou le bouton **Recompiler** de la carte) : le simulateur exécute le programme **compilé** |
| Un module ne réagit pas | Vérifier que son port dans le simulateur est le même que la broche utilisée dans le code |
| Les modules se chevauchent après une mise à jour du simulateur | Choisir **Ranger…** dans la barre du haut : les modules de la version 1.1 sont dessinés plus grands |
| Un module du MEGA a disparu après une mise à jour | Le rebrancher sur une prise qui existe sur le vrai hat : D2, D4… D12 ou A0, A2… A14 (section 3.2) |
| Le MEGA ne joint pas l'API | Vérifier que le conteneur tourne (onglet **API**) et que l'adresse est `127.0.0.1` |

---

## Crédits

**Document rédigé par Alain Boudreault © 2021-2027**

**Version 2026.11.19.01 - Révision 2026.11.19.4**

*Contenu par [VE2CUY](https://ve2cuy.github.io/blog/)*
