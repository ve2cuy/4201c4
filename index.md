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

- ![](dessins/document.svg) - · [Plan de cours H26 (PDF)](Documents/420-1C4-JR_ab_pc_H26.pdf)
- ![](dessins/document.svg) - · [Plan de cours, version texte](Documents/Plan-de-cours.md)

## B) Documents 1 à 13

![](dessins/puce-del.svg) *Arduino, PlatformIO, C, affichage*

- ![](dessins/microcontroleur.svg) 01 · [Introduction aux microcontrôleurs](Documents/Introduction-microcontroleurs.md)
  - Arduino Uno · émulateurs en ligne : Wokwi, TinkerCad
- ![](dessins/terminal.svg) 02 · [Hello World – PlatformIO](Documents/PlatformIO-Hello-world.md)
- ![](dessins/carte-arduino.svg) 03 · [Hello World – Arduino IDE](Documents/Hello-world.md)
- ![](dessins/bouton.svg) 04 · [Serial.println(val), digitalRead() et while() pour la gestion du bouton](Documents/Serial-println-et-digitalread.md)
- ![](dessins/potentiometre.svg) 05 · [Lecture/écriture d'une valeur analogique – analogRead(), analogWrite(), PWM](Documents/analogRead.md)
- ![](dessins/lcd.svg) 06 · [Grove – Module LCD-RGB i2c (sprintf, switch, #ifdef, op ternaire, i % j)](Documents/LCD-enum-ifdef.md)
- ![](dessins/accolades.svg) 07 · [Compilation conditionnelle](Documents/Compilation-conditionnelle.md)
- ![](dessins/livres.svg) 08 · [Les librairies](Documents/Utilisation-de-librairies.md)
- ![](dessins/resistance-del.svg) 09 · [Électronique – concepts de base](Documents/Electronique-concepts-de-base.md)
- ![](dessins/liste.svg) 10 · [L'instruction « enum » du langage C](Documents/Instruction-enum.md) · TP02
- ![](dessins/structure.svg) 11 · [Structures de données](Documents/Structures-de-donnees.md)
- ![](dessins/bits.svg) 12 · [Opérations sur les bits et structures de données](Documents/Operations-sur-les-bits-et-structure-de-donnees.md) · TP02
- ![](dessins/thermometre.svg) 13 · [Température, humidité et affichage sur 7 segments – 4Digit](Documents/Capteur-temperature-humidite.md)
  - Installer une librairie à la main

## C) Documents 20 à 28

![](dessins/capteur-sans-fil.svg) *Capteurs, horloge, UART, Wi-Fi*

- ![](dessins/bande-del.svg) 20 · [Buzzer et NeoPixel](Documents/NEOPixel.md)
- ![](dessins/horloge.svg) 21 · [Real Time Clock (RTC)](Documents/RTC-DS1307.md)
- ![](dessins/mouvement.svg) 22 · [Détecteur de mouvements](Documents/Detecteur-de-mouvements.md)
- ![](dessins/minuterie.svg) 23 · [Opérations non bloquantes – millis() et interruptions](Documents/Operations-non-bloquantes.md) · TP02
- ![](dessins/uart.svg) 24 · [Communication UART entre deux Arduino](Documents/Communication-UART-entre-2-arduino.md) · TP02
- ![](dessins/wifi.svg) 25 · [ESP-Wifi – accès réseau](Documents/ESP-Wifi.md) · TP02
- ![](dessins/infrarouge.svg) 26 · Détecteur infrarouge · optionnel
- ![](dessins/eeprom.svg) 27 · EEPROM · optionnel
- ![](dessins/rfid.svg) 28 · [Capteur RFID](Documents/capteur-rfid.md) · optionnel · défi TP02

## D) Projet de session

![](dessins/drapeau.svg) *Partie A et partie B*

- ![](dessins/oeil.svg) 29 · [Partie A · TP01 – Le système de surveillance H26](Documents/TP01-H26.md)
- ![](dessins/coupe.svg) 30 · [Partie B · TP02 – Épreuve synthèse, volet A](Documents/ES-H26-Volet-A.md#partie-2)
- ![](dessins/surveillance.svg) 31 · [Centrale de surveillance · événements reçus par l'API](http://esh25.ve2cuy.com/index.php)
  - Les événements envoyés par les systèmes de la classe (ES, partie 2)

## E) Documents 32 et 33

![](dessins/feuilles.svg) *Copier/coller et solutions*

- ![](dessins/copier-coller.svg) 32 · [Les copier/coller](Documents/copier-coller.md)
  - Les variables de type scalaire · gestion du bruit sur un bouton – bounce2
- ![](dessins/solutions.svg) 33 · [Solutions aux laboratoires](Documents/Solutions.md)
