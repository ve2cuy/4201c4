
## 1 - Créer un nouveau projet sous PlatformIO

<img src="../images/pio-01.png" alt="platformIO" width="500" />

### Nommer le projet et choisir la platforme

<img src="../images/pio-02.png" alt="platformIO" width="500" />

### 1.1 - Examiner la structure de départ

<img src="../images/pio-02b.png" alt="platformIO" width="300" />

### 1.2 - Le fichier main.cpp

<img src="../images/pio-03.png" alt="platformIO" width="500" />

<br>

---

### 1.3 - Remplacer le code source de main.cpp par:

```c++
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Bonjour le Mode!\n");
}

void loop() {
 
}
```

## 2 - Compiler le projet:
<img src="../images/pio-build.png" alt="platformIO" width="500" />

> ou -> **CTRL+ALT+B**

<img src="../images/pio-build-action.png" alt="platformIO" width="500" />


## 3 - Téléverser l'application vers le micro-contrôleur

> ou -> **CTRL+ALT+U**

<img src="../images/pio-upload.png" alt="platformIO" width="500" />
<img src="../images/pio-build-action1.png" alt="platformIO" width="500" />
<img src="../images/pio-build-action2.png" alt="platformIO" width="500" />



## 4 - Afficher le moniteur série (Pour les traces du programme)
<img src="../images/pio-serial-monitor.png" alt="platformIO" width="500" />
<img src="../images/pio-upload-action.png" alt="platformIO" width="500" />

> ou -> **CTRL+ALT+S**

---

## 5 - Installer une librairie supplémentaire:

<img src="../images/pio-librairie-01.png" alt="platformIO" width="500" />

<img src="../images/pio-librairie-02.png" alt="platformIO" width="500" />

<img src="../images/pio-librairie-03.png" alt="platformIO" width="500" />

<img src="../images/pio-librairie-04.png" alt="platformIO" width="500" />


### 5.1 - Remplacer le code source de main.cpp par et tester l'application:

```c++
#include <Arduino.h>
#include <Streaming.h>

void setup() {
  Serial.begin(9600);
  Serial << "Bonjour le Monde!" << endl;
}

void loop() {
}
```
---

## 6 - Hello World avec une DEL (LED)

## 6.1 – Exemple avec documentation

```c
// Projet: Introduction à Arduino
// Auteur: Alain Boudreault
// Date: 2021.07.17

void setup() {
  pinMode(13, 1); // OUTPUT
}

void loop() {
  digitalWrite(13, 1); // ON
  delay(500);
  digitalWrite(13, 0); // OFF
  delay(500);
}
```

👉 Tester l'application

---

## 6.2 – Utilisation de MACROs

```c
#define DEL_ROUGE 13
#define SORTIE 1
#define ALLUMER 1
#define ETEINDRE 0
#define DELAI 500

void setup() {
  pinMode(DEL_ROUGE, SORTIE);
}

void loop() {
  digitalWrite(DEL_ROUGE, ALLUMER);
  delay(DELAI);
  digitalWrite(DEL_ROUGE, ETEINDRE);
  delay(DELAI);
}
```

👉 Tester l'application

---

## 7 – Utilisation d'un fichier d'entête (.h)

```c
// Fichier include/main.h 
// Dans main.cpp, ajouter : #include "main.h"
#define DEL_ROUGE 13
#define SORTIE 1
#define ALLUMER 1
#define ETEINDRE 0
#define DELAI 500
```


---

## Crédits

**Document rédigé par Alain Boudreault © 2021-2026**
**Version 2025.12.14.01

*Contenu par [VE2CUY](http://ve2cuy.com/blog)*
