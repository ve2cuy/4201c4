# 27 - La mémoire EEPROM

*Révision du 2026.11.07*

## Objectif de la lecture

À la fin de cette lecture, nous devrions être capable d'expliquer à quoi sert la mémoire **EEPROM** d'un microcontrôleur, d'en connaître les **limites**, et d'utiliser la librairie **EEPROM.h** pour **conserver** des données (compteurs, réglages, configuration) même lorsque l'Arduino est éteint.

*A.B. aka ve2cuy*

---

## Contenu

1. **Qu'est-ce que l'EEPROM?**
2. **Les limites de l'EEPROM**
3. **La librairie EEPROM.h**
4. **Lire et écrire un octet – le compteur de démarrages**
5. **EEPROM.update() – ménager l'EEPROM**
6. **EEPROM.put() et EEPROM.get() – conserver une variable ou une structure**
7. **Parcourir et effacer l'EEPROM**
8. **Laboratoires**

---

## 1 – Qu'est-ce que l'EEPROM?

Rappel du document [Introduction aux microcontrôleurs](Introduction-microcontroleurs.md): l'ATmega328P possède trois types de mémoire.

| Mémoire | Taille (ATmega328P) | Contenu | Conservée sans alimentation? |
|---------|---------------------|---------|------------------------------|
| **Flash** | 32 Ko | Le programme | Oui |
| **SRAM** | 2 Ko | Les variables, pendant l'exécution | **Non** |
| **EEPROM** | 1 Ko | Les données à conserver | **Oui** |

*Tableau 01*

**EEPROM** veut dire *Electrically-Erasable Programmable Read-Only Memory*, une mémoire non volatile effaçable électriquement.

Les variables de nos programmes sont placées en **SRAM**. À chaque redémarrage de l'Arduino (bouton RESET, téléversement, coupure de courant), elles sont perdues et reprennent leur valeur de départ.

L'EEPROM agit comme un **tout petit disque dur**: les valeurs qui y sont écrites restent en place lorsque l'Arduino est éteint. Elle sert, par exemple, à conserver:

* le nombre de fois qu'un appareil a été utilisé,
* les réglages choisis par l'utilisateur (volume, intensité, langue, etc.),
* un code d'accès ou un numéro de série,
* la configuration d'un objet connecté (le nom du réseau Wi-Fi, l'adresse d'une API, etc.).

La taille de l'EEPROM varie selon le microcontrôleur:

| Carte | Microcontrôleur | Taille de l'EEPROM |
|-------|-----------------|--------------------|
| Arduino Uno | ATmega328P | 1 Ko (1024 octets) |
| Arduino Mega | ATmega2560 | 4 Ko (4096 octets) |
| Arduino Duemilanove | ATmega168 | 512 octets |

*Tableau 02*

L'EEPROM est organisée en **cases d'un octet**, numérotées à partir de 0. Le numéro d'une case est son **adresse**. Sur le Uno, les adresses vont donc de 0 à 1023.

> Note: Une case d'EEPROM jamais écrite contient habituellement la valeur **255** (0xFF), la valeur d'une mémoire effacée.

---

## 2 – Les limites de l'EEPROM

**1 – Le nombre d'écritures est limité**

Chaque case de l'EEPROM supporte environ **100 000 écritures**. Au-delà, elle peut ne plus conserver correctement sa valeur. Les **lectures**, elles, sont illimitées.

100 000, c'est beaucoup? Faisons le calcul pour un programme qui écrit dans la même case à chaque passage dans `loop()`, aux 100 ms:

```
100 000 écritures x 0,1 seconde = 10 000 secondes, soit moins de 3 heures!
```

**Il ne faut donc jamais écrire dans l'EEPROM à chaque tour de loop()**. On y écrit seulement lorsqu'une valeur **change** ou lors d'un événement précis (un bouton, un changement de réglage, etc.).

**2 – L'écriture est lente**

Une écriture prend environ **3.3 ms** par octet. Écrire 1024 octets prend donc plus de 3 secondes.

**3 – La taille est petite**

1 Ko, c'est peu. Il faut planifier l'emplacement (l'adresse) de chaque donnée.

---

## 3 – La librairie EEPROM.h

La librairie **EEPROM.h** fait partie de la plateforme Arduino. **Il n'y a rien à installer**, il suffit de l'inclure:

```cpp
#include <EEPROM.h>
```

Elle propose un objet nommé `EEPROM` avec les méthodes suivantes:

| Méthode | Description |
|---------|-------------|
| `EEPROM.read(adresse)` | Retourne l'octet (0..255) de la case *adresse* |
| `EEPROM.write(adresse, valeur)` | Écrit un octet dans la case *adresse* |
| `EEPROM.update(adresse, valeur)` | Écrit l'octet **seulement s'il est différent** de la valeur déjà en place |
| `EEPROM.put(adresse, variable)` | Écrit une variable de n'importe quel type (int, float, struct, etc.) à partir de *adresse* |
| `EEPROM.get(adresse, variable)` | Lit une variable de n'importe quel type à partir de *adresse* |
| `EEPROM[adresse]` | Accès à une case, comme dans un tableau |
| `EEPROM.length()` | Retourne la taille de l'EEPROM, en octets |

*Tableau 03*

> 💡Utiliser `EEPROM.length()` plutôt que coder 1024 en dur: le programme fonctionnera aussi sur un Mega (4096 octets).

---

## 4 – Lire et écrire un octet – le compteur de démarrages

Ce premier exemple compte le nombre de démarrages de l'Arduino. Le compteur est conservé dans la case 0 de l'EEPROM.

```cpp
/*
    Fichier:      eeprom-compteur.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    Clientèle:    Étudiant(e)s du cours 420-1C4: Objets connectés de CSTJ.
    --------------------------------------------------------------------------
    Description:  Compter le nombre de démarrages de l'Arduino.
                  Le compteur est conservé dans l'EEPROM, il survit donc
                  à un RESET ou à une coupure de courant.
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define ADRESSE_COMPTEUR    0       // La case de l'EEPROM réservée au compteur
#define VITESSE_UART        9600

void setup() {
  Serial.begin(VITESSE_UART);

  // 1 - Lire la valeur conservée dans l'EEPROM
  byte nbDemarrages = EEPROM.read(ADRESSE_COMPTEUR);

  // 2 - Augmenter le compteur
  nbDemarrages++;

  // 3 - Conserver la nouvelle valeur. Une seule écriture par démarrage.
  EEPROM.write(ADRESSE_COMPTEUR, nbDemarrages);

  Serial.print("Nombre de démarrages: ");
  Serial.println(nbDemarrages);
} // setup()

void loop() {
  // Rien à faire ici, et surtout pas d'écriture dans l'EEPROM!
} // loop()
```

👉 Tester l'application, puis appuyer quelques fois sur le bouton **RESET** de l'Arduino.

👉 Débrancher l'Arduino, le rebrancher et ouvrir de nouveau le moniteur série. La valeur du compteur n'a pas été perdue 😊.

**Questions:**

1. Au tout premier démarrage, la case 0 contient 255. Quelle valeur sera affichée? Pourquoi?
2. Que se passe-t-il après 255 démarrages? (Indice: le type `byte`)

> Note: Sur **Wokwi**, le contenu de l'EEPROM ne survit pas au redémarrage de la simulation. Les essais de conservation des données doivent être faits sur la carte.

---

## 5 – EEPROM.update() – ménager l'EEPROM

La méthode `update()` lit d'abord la case et n'écrit que si la valeur est **différente**. Elle est l'équivalent de:

```cpp
if (EEPROM.read(adresse) != valeur) {
  EEPROM.write(adresse, valeur);
}
```

Elle économise donc à la fois des écritures (la durée de vie de l'EEPROM) et du temps (3.3 ms par écriture évitée).

**En pratique, préférer `update()` à `write()`**.

Dans l'exemple suivant, l'intensité d'une DEL est réglée avec le potentiomètre. Le réglage est conservé dans l'EEPROM et la DEL reprend la même intensité au prochain démarrage.

```cpp
/*
    Fichier:      eeprom-intensite.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Régler l'intensité d'une DEL avec le potentiomètre et
                  conserver ce réglage dans l'EEPROM.
    Modules:      Potentiomètre sur A0, DEL sur D3 (PWM)
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define BROCHE_POT            A0
#define BROCHE_DEL            3
#define ADRESSE_INTENSITE     1     // La case 0 est réservée au compteur de démarrages
#define DELAI_LECTURE         100

void setup() {
  pinMode(BROCHE_DEL, OUTPUT);
  // Reprendre l'intensité conservée lors de la dernière utilisation
  analogWrite(BROCHE_DEL, EEPROM.read(ADRESSE_INTENSITE));
  delay(2000);
} // setup()

void loop() {
  // analogRead() retourne 0..1023, une case de l'EEPROM contient 0..255:
  // il faut diviser par 4 (ou utiliser map()).
  byte intensite = analogRead(BROCHE_POT) / 4;

  analogWrite(BROCHE_DEL, intensite);

  // Écrire seulement si l'intensité a changé
  EEPROM.update(ADRESSE_INTENSITE, intensite);

  delay(DELAI_LECTURE);
} // loop()
```

👉 Tester l'application: régler l'intensité, débrancher l'Arduino, puis le rebrancher.

> Note: Même avec `update()`, un potentiomètre qui « tremble » entre deux valeurs provoque des écritures. Une solution: écrire seulement si la nouvelle valeur s'éloigne de plus de 2 de la précédente, comme dans le document [Signaux analogiques](analogRead.md) (section 4.4).

---

## 6 – EEPROM.put() et EEPROM.get() – conserver une variable ou une structure

`read()` et `write()` ne traitent qu'un seul octet. Pour conserver un `int` (2 octets), un `float` (4 octets) ou une structure complète, on utilise `put()` et `get()`.

Ces méthodes écrivent et lisent **autant d'octets que la taille de la variable** (`sizeof(variable)`).

> 💡`put()` utilise `update()` pour chacun des octets: seuls les octets qui ont changé sont réécrits.

L'exemple suivant conserve la **configuration** d'un système dans une structure (voir le document [Structures de données](Structures-de-donnees.md)).

Comment savoir si l'EEPROM contient une configuration valide ou seulement des 255? Une technique courante consiste à placer une **signature** (un nombre choisi) dans la structure. Si la signature lue n'est pas la bonne, on utilise la configuration par défaut.

```cpp
/*
    Fichier:      eeprom-configuration.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Conserver la configuration d'un système dans l'EEPROM,
                  avec EEPROM.put() et EEPROM.get().
                  Un 'c' dans le moniteur série change la configuration,
                  un 'r' la remet aux valeurs par défaut.
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define ADRESSE_CONFIGURATION   16      // Après le compteur (0) et l'intensité (1)
#define SIGNATURE               0x1C4A    // Pour reconnaître une configuration valide
#define VITESSE_UART            9600

struct Configuration {
  uint16_t signature;
  char     nomDuSysteme[10];
  byte     volume;                // 0..10
  float    seuilTemperature;      // En degrés Celsius
};

const Configuration CONFIGURATION_PAR_DEFAUT = { SIGNATURE, "E0000001", 5, 28.5 };

Configuration config;             // La configuration en mémoire vive (SRAM)

void afficherConfiguration() {
  Serial.print("Système: ");      Serial.println(config.nomDuSysteme);
  Serial.print("Volume: ");       Serial.println(config.volume);
  Serial.print("Seuil: ");        Serial.print(config.seuilTemperature);
  Serial.println(" C");
  Serial.print("Taille de la structure: ");
  Serial.print(sizeof(config));
  Serial.println(" octets\n");
} // afficherConfiguration()

void setup() {
  Serial.begin(VITESSE_UART);

  // 1 - Lire toute la structure d'un seul coup
  EEPROM.get(ADRESSE_CONFIGURATION, config);

  // 2 - Signature absente: l'EEPROM n'a jamais reçu de configuration
  if (config.signature != SIGNATURE) {
    Serial.println("Aucune configuration, utilisation des valeurs par défaut.");
    config = CONFIGURATION_PAR_DEFAUT;
    EEPROM.put(ADRESSE_CONFIGURATION, config);
  }
  afficherConfiguration();
} // setup()

void loop() {
  switch (Serial.read()) {
    case 'c':   // Changer la configuration et la conserver
      config.volume = (config.volume + 1) % 11;
      config.seuilTemperature += 0.5;
      EEPROM.put(ADRESSE_CONFIGURATION, config);
      Serial.println("Configuration modifiée et conservée:");
      afficherConfiguration();
      break;
    case 'r':   // Revenir aux valeurs par défaut
      config = CONFIGURATION_PAR_DEFAUT;
      EEPROM.put(ADRESSE_CONFIGURATION, config);
      Serial.println("Valeurs par défaut:");
      afficherConfiguration();
      break;
  } // switch
} // loop()
```

👉 Tester l'application: modifier la configuration avec **c**, appuyer sur **RESET**, et constater que la configuration modifiée est relue au démarrage.

**Explication du code:**

- `EEPROM.get(adresse, config)`: Lit `sizeof(config)` octets à partir de *adresse* et les place dans la variable `config`.
- `EEPROM.put(adresse, config)`: Écrit la variable `config`, octet par octet, à partir de *adresse*.
- `sizeof(config)`: La taille de la structure. Pour placer une deuxième donnée après la configuration, il faut utiliser l'adresse `ADRESSE_CONFIGURATION + sizeof(Configuration)`.

> **ATTENTION**: `get()` et `put()` ne vérifient rien. Lire un `float` dans une zone qui contient autre chose donne une valeur absurde (`nan`, `ovf`). D'où l'intérêt de la signature.

---

## 7 – Parcourir et effacer l'EEPROM

L'objet `EEPROM` s'utilise comme un tableau d'octets, de `EEPROM[0]` à `EEPROM[EEPROM.length() - 1]`.

### 7.1 – Afficher le contenu de l'EEPROM

```cpp
/*
    Fichier:      eeprom-afficher.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Afficher le contenu de l'EEPROM, 16 octets par ligne,
                  en hexadécimal.
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define OCTETS_PAR_LIGNE    16
#define VITESSE_UART        9600

void setup() {
  char texte[8];
  Serial.begin(VITESSE_UART);
  Serial.print("Taille de l'EEPROM: ");
  Serial.print(EEPROM.length());
  Serial.println(" octets\n");

  for (int adresse = 0; adresse < EEPROM.length(); adresse++) {
    // Au début de chaque ligne, afficher l'adresse de la première case
    if (adresse % OCTETS_PAR_LIGNE == 0) {
      sprintf(texte, "\n%04X: ", adresse);
      Serial.print(texte);
    }
    sprintf(texte, "%02X ", EEPROM.read(adresse));
    Serial.print(texte);
  }
} // setup()

void loop() {}
```

👉 Tester l'application après les exemples précédents. Repérer le compteur de démarrages, l'intensité de la DEL, la signature (1C4A, écrite à l'envers: 4A 1C) et le nom du système.

> 💡Les octets de la signature sont rangés à l'envers: l'ATmega328P range l'octet de poids faible en premier (*little-endian*).

### 7.2 – Effacer l'EEPROM

```cpp
#include <Arduino.h>
#include <EEPROM.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Remettre toutes les cases à 255, la valeur d'une EEPROM neuve
  for (int adresse = 0; adresse < EEPROM.length(); adresse++) {
    EEPROM.update(adresse, 255);
  }
  digitalWrite(LED_BUILTIN, HIGH);   // La DEL intégrée (D13) indique la fin
} // setup()

void loop() {}
```

> Note: Ce programme écrit dans toutes les cases (jusqu'à 3 secondes sur le Uno). Il ne faut l'exécuter **qu'une seule fois**, dans `setup()`.

---

## 8 – Laboratoires

### 8.1 – Laboratoire (durée 20 minutes)

<img src="../images/labo02.png" alt="" width="700" />

<br>

Modifier le compteur de démarrages (section 4) pour que le compteur soit de type `unsigned int` (2 octets), en utilisant `EEPROM.put()` et `EEPROM.get()`.

Afficher le nombre de démarrages sur l'écran LCD.

Combien de démarrages est-il maintenant possible de compter?

---

### 8.2 – Laboratoire (durée 30 minutes)

<img src="../images/labo03.png" alt="" width="700" />

<br>

Écrire un programme qui compte le nombre de fois que le bouton (D2) a été appuyé, **depuis toujours**.

* Le compteur est affiché sur l'écran LCD.
* Il est conservé dans l'EEPROM à chaque appui du bouton.
* Un appui de plus de 3 secondes remet le compteur à 0.

Sachant qu'une case supporte 100 000 écritures, combien d'appuis le système pourra-t-il compter de façon fiable?

---

### 8.3 – Laboratoire (durée 30 minutes)

<img src="../images/labo02.png" alt="" width="700" />

<br>

Ajouter au projet de session (TP01) une configuration conservée dans l'EEPROM: le **mode** de l'alarme et le **seuil de température**. Le système doit retrouver sa configuration après une coupure de courant.

Utiliser une structure, une signature et `EEPROM.put()`/`EEPROM.get()`.

---

## Défi informatique

Un journal des 10 dernières alarmes (heure du RTC et type d'alarme) conservé dans l'EEPROM. Lorsque le journal est plein, la plus vieille alarme est remplacée par la nouvelle (tableau circulaire).

Bonus: répartir les écritures sur plusieurs cases pour allonger la durée de vie de l'EEPROM.

---

## Références

- [A guide to EEPROM](https://docs.arduino.cc/learn/programming/eeprom-guide/) (Arduino) et ses exemples: Clear, CRC, Get, Iteration, Put, Read, Update et Write
- [Librairie EEPROM](https://docs.arduino.cc/learn/built-in-libraries/eeprom/) (Arduino)

---

## Crédits

*Document rédigé par Alain Boudreault © 2021-2026*  
*Version 2026.11.07.1*  

*Contenu par [VE2CUY](https://ve2cuy.github.io/blog/)*
