---
layout: accueil
bandeau: "420-1C4-JR · techniques de l'informatique · cégep de saint-jérôme"
titre: "Objets connectés."
accroche: "Capteurs, afficheurs et électronique de base autour d'un microcontrôleur Arduino, programmé en C avec PlatformIO et Wokwi."
image: images/arduino-robot.webp
---

## Présentation sommaire du cours

![](dessins/fiche-info.svg)

Le cours **Objets connectés** initie l'étudiant aux capteurs d'environnement, aux différentes technologies d'affichage (écran ACL, diode lumineuse, etc.) et aux notions de base en électronique pour réaliser des objets connectés. À l'aide d'un microcontrôleur (Arduino Uno), il met en pratique des notions de base en programmation pour développer des applications simples. Finalement, l'étudiant est sensibilisé aux données générées par les objets connectés et aux manières de les sauvegarder et de les échanger de manière sécuritaire.

- **Programme** : 420.B0 · Techniques de l'informatique
- **Famille** : Mobiles et objets connectés
- **Pondération** : 1-3-2
- **Préalable** : Aucun

Outils : [Wokwi](https://wokwi.com/) et [TinkerCad](https://www.tinkercad.com/circuits) (émulateurs Arduino en ligne), PlatformIO et l'Arduino IDE.

## Horaire et disponibilités de l'enseignant

![](dessins/enseignant.svg)

![Alain Boudreault](images/moi.jpg)

**Alain Boudreault**, enseignant au département de Techniques de l'informatique, Cégep de Saint-Jérôme

- **Courriel** : [Aboudrea@cstj.qc.ca](mailto:Aboudrea@cstj.qc.ca)
- **Téléphone** : poste 6516
- **Local** : D125e

[Disponibilités pour la session H26](images/Horaire-H26.png) · [Calendrier scolaire H26 (PDF)](Documents/Calendriers_H26_CSTJ.pdf)

## A) Plan de cours

![](dessins/porte-documents.svg) *Le plan officiel de la session*

- ![](dessins/document.svg) - · [Plan de cours](Documents/420-1C4-JR_ab_pc_H26.pdf)
  - Session H26 · PDF officiel
- ![](dessins/document.svg) - · [Plan de cours, version texte](Documents/Plan-de-cours.md)
  - Le même plan, lisible dans le fureteur

## B) Documents - Première étape du cours

![](dessins/puce-del.svg) *Arduino, PlatformIO, C, affichage*

- ![](dessins/microcontroleur.svg) 01 · [Introduction aux microcontrôleurs](Documents/Introduction-microcontroleurs.md)
  - Arduino Uno · émulateurs en ligne : Wokwi, TinkerCad
- ![](dessins/terminal.svg) 02 · [Introduction à PlatformIO](Documents/PlatformIO-Hello-world.md)
  - VS Code · structure d'un projet · platformio.ini · Hello World
- ![](dessins/carte-arduino.svg) 03 · [Arduino IDE](Documents/Hello-world.md)
  - Hello World · DEL sur D13 · delay() · macros
- ![](dessins/bouton.svg) 04 · [Console série et bouton](Documents/Serial-println-et-digitalread.md)
  - Serial.println(val) · digitalRead() · while() · pull-up · rebond
- ![](dessins/potentiometre.svg) 05 · [Signaux analogiques](Documents/analogRead.md)
  - analogRead() · analogWrite() · PWM · map()
- ![](dessins/lcd.svg) 06 · [Écran LCD-RGB I2C](Documents/LCD-enum-ifdef.md)
  - sprintf · switch · #ifdef · opérateur ternaire · i % j
- ![](dessins/accolades.svg) 07 · [Compilation conditionnelle](Documents/Compilation-conditionnelle.md)
  - #ifdef · #ifndef · #else · macro de garde des fichiers .h
- ![](dessins/livres.svg) 08 · [Les librairies](Documents/Utilisation-de-librairies.md)
  - Installer sous PlatformIO · Streaming · librairie locale · versions
- ![](dessins/resistance-del.svg) 09 · [Électronique](Documents/Electronique-concepts-de-base.md)
  - Concepts de base · tension, intensité, puissance, résistance
- ![](dessins/liste.svg) 10 · [L'instruction enum](Documents/Instruction-enum.md) · TP02
  - Énumérations du langage C · gestion d'un menu
- ![](dessins/structure.svg) 11 · [Structures de données](Documents/Structures-de-donnees.md)
  - struct · enum · tableau de structures
- ![](dessins/bits.svg) 12 · [Opérations sur les bits](Documents/Operations-sur-les-bits-et-structure-de-donnees.md) · TP02
  - Opérateurs ET, OU, OU exclusif et NON · décalages · structures de données
- ![](dessins/thermometre.svg) 13 · [Température et humidité](Documents/Capteur-temperature-humidite.md)
  - Capteur SHT31 · afficheur 7 segments 4-Digit (TM1637) · installer une librairie à la main

## C) Documents - Deuxième étape du cours

![](dessins/capteur-sans-fil.svg) *Capteurs, horloge, UART, Wi-Fi*

- ![](dessins/bande-del.svg) 14 · [Buzzer et NeoPixel](Documents/NEOPixel.md)
  - Buzzer · barre de DEL RGB WS2813
- ![](dessins/horloge.svg) 15 · [Horloge temps réel](Documents/RTC-DS1307.md)
  - Real Time Clock (RTC) DS1307 · I2C · heure et date
- ![](dessins/mouvement.svg) 16 · [Détecteur de mouvements](Documents/Detecteur-de-mouvements.md)
  - Capteur PIR ajustable · connexion digitale
- ![](dessins/minuterie.svg) 17 · [Opérations non bloquantes](Documents/Operations-non-bloquantes.md) · TP02
  - millis() · interruptions matérielles · interruption Timer
- ![](dessins/uart.svg) 18 · [Communication UART](Documents/Communication-UART-entre-2-arduino.md) · TP02
  - Entre deux Arduino · UART physique · SoftwareSerial
- ![](dessins/wifi.svg) 19 · [Accès Wi-Fi](Documents/ESP-Wifi.md) · TP02
  - Module UART Wifi V2 (ESP8285) · commandes AT · requêtes vers une API Web
- ![](dessins/infrarouge.svg) 20 · [Infrarouge](Documents/Infrarouge.md) · optionnel
  - Récepteur et émetteur Grove · télécommande · protocoles NEC et Sony
- ![](dessins/eeprom.svg) 21 · [La mémoire EEPROM](Documents/EEPROM.md) · optionnel
  - Conserver des données sans alimentation · read, update, put et get
- ![](dessins/rfid.svg) 22 · [Capteur RFID](Documents/capteur-rfid.md) · optionnel · défi TP02
  - Module RFID de Grove

## D) Projet de session

![](dessins/drapeau.svg) *Partie A et partie B*

- ![](dessins/oeil.svg) 23 · [Système de surveillance H26](Documents/TP01-H26.md)
  - Partie A · énoncé du TP01
- ![](dessins/coupe.svg) 24 · [Épreuve synthèse, volet A](Documents/ES-H26-Volet-A.md#partie-2)
  - Partie B · TP02 · transmission des données vers le Web
- ![](dessins/surveillance.svg) 25 · [Centrale de surveillance](http://esh25.ve2cuy.com/index.php)
  - Les événements envoyés à l'API par les systèmes de la classe (ES, partie 2)

## E) Documents - Aide-mémoire et solutions

![](dessins/feuilles.svg) *Copier/coller et solutions*

- ![](dessins/copier-coller.svg) 26 · [Les copier/coller](Documents/copier-coller.md)
  - Code de départ · séquences ANSI et boîtes · variables de type scalaire · bruit d'un bouton (bounce2)
- ![](dessins/solutions.svg) 27 · [Solutions aux laboratoires](Documents/Solutions.md)
  - NeoPixel · Real Time Clock DS1307
