# Compilation conditionnelle

<img src="../images/antique-clock-face-.png" alt="Horloge" width="500" />

---

Les directives `#ifdef`, `#ifndef`, `#else`, et `#endif` sont utilisées pour la **compilation conditionnelle** dans le langage C. Elles permettent d'inclure ou d'exclure certaines parties du code en fonction de conditions spécifiques. Cela peut être utile pour activer ou désactiver des sections de code selon des plateformes, des configurations de compilation, ou des environnements différents.

### 1. `#ifdef` (If Defined)

La directive `#ifdef` permet de vérifier si une macro a été définie. Si la macro a été définie avant l'utilisation de `#ifdef`, le bloc de code entre `#ifdef` et `#endif` sera compilé. Si la macro n'est pas définie, le bloc de code est ignoré.

* **Exemple** :

```c
  #define DEBUG  // Définir la macro DEBUG

  #ifdef DEBUG
      printf("Mode débogage activé\n");
  #endif
```

Dans cet exemple, puisque la macro `DEBUG` a été définie avant `#ifdef`, le code à l'intérieur de `#ifdef` sera exécuté. La sortie sera :

```
  Mode débogage activé
```

Si la ligne `#define DEBUG` est supprimée, alors la ligne `printf` sera ignorée.

### 2. `#ifndef` (If Not Defined)

La directive `#ifndef` est l'inverse de `#ifdef`. Elle permet de vérifier si une macro **n'a pas** été définie. Si la macro n'est pas définie avant `#ifndef`, le bloc de code sera compilé, sinon il sera ignoré.

* **Exemple** :

```c
  #ifndef DEBUG
      #define DEBUG 1  // Si DEBUG n'est pas déjà défini, le définir à 1
  #endif
```

Ici, si la macro `DEBUG` n'était pas définie avant ce bloc, elle serait définie à `1`. Si elle l'était déjà, le code à l'intérieur de `#ifndef` sera ignoré.

### 3. `#else`

La directive `#else` permet de spécifier un bloc de code à exécuter si la condition de la directive `#ifdef` ou `#ifndef` est fausse (si la macro n'est pas définie dans le cas de `#ifdef` ou si elle est définie dans le cas de `#ifndef`).

* **Exemple** :

```c
  #ifdef DEBUG
      printf("Mode débogage activé\n");
  #else
      printf("Mode normal activé\n");
  #endif
```

Dans cet exemple :

* Si `DEBUG` est défini, le programme affiche « Mode débogage activé ».
* Si `DEBUG` n'est pas défini, le programme affiche « Mode normal activé ».

### 4. Combinaison de `#ifdef`, `#else`, et `#endif`

Ces directives sont souvent utilisées ensemble pour gérer plusieurs configurations ou comportements dans le code en fonction des macros définies.

* **Exemple combiné** :

```c
  #ifdef DEBUG
      printf("Mode débogage activé\n");
  #else
      printf("Mode normal activé\n");
  #endif

  #ifndef VERSION
      #define VERSION "1.0"
  #endif

  printf("Version : %s\n", VERSION);
```

Dans cet exemple :

* Le premier bloc affiche un message selon que `DEBUG` est défini ou non.
* Le deuxième bloc définit une version si la macro `VERSION` n'est pas déjà définie. Si elle l'est, la ligne `#define VERSION "1.0"` sera ignorée.

---

## 5- Utilisation conditionnelle de l'affichage dans la console

```c
#ifdef DEBUG
#define AFFICHER(x) Serial.print(x)
#else
#define AFFICHER
#endif

// Utilisation:
AFFICHER("Un message ...\n");
```

## 5.1 – Exemple avec un nombre variable de paramètres:

```c
#define AFFICHER(...)  Serial.print(__VA_ARGS__)

// Utilisation:
AFFICHER(255, HEX);
AFFICHER("Test");
```

---

## 6 – MACRO de garde pour les fichiers.h

```c
#ifndef fichier_h
#define fichier_h
...

#endif

// Il est aussi possible d'utiliser la directive suivante pour s'assurer que le fichier sera inclu q'une seule fois.

#pragma once

...

// Voici une autre utilisation de #pragma
#pragma GCC poison sprintf // Produira une erreur à l'utilisation de la fonction sprintf():

Compiling .pio/build/uno/src/main.cpp.o
src/main.cpp:18:3: error: attempt to use poisoned "sprintf"
   sprintf(buffer, "Yo");
```

Référence pour [#pragma\_once](https://fr.wikipedia.org/wiki/Pragma_once)

---

### Conclusion

* **`#ifdef`** : Inclut un bloc de code si la macro est définie.
* **`#ifndef`** : Inclut un bloc de code si la macro n'est pas définie.
* **`#else`** : Permet de spécifier un bloc de code alternatif si la condition de `#ifdef` ou `#ifndef` est fausse.
* **`#endif`** : Termine un bloc de condition.

Ces directives permettent une gestion très flexible du code, particulièrement utile pour les projets multi-plateformes, pour inclure/exclure des instructions de traçage ou lors de la gestion de différentes versions d'un même programme.

---

## Crédits

**Document rédigé par Alain Boudreault © 2021-2026**
**Version 2025.03.15.01 - Révision 2025.12.12.1**

*Contenu par [VE2CUY](http://ve2cuy.com/blog)*