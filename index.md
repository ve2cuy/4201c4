---
title: "420-1C4 · Objets connectés"
---

<nav class="tiles" aria-label="Sections du cours">
  <a class="tile" href="#plan">
    <div class="art c-cyan"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" role="img" aria-label="Plan de cours"><rect x="72" y="14" width="56" height="74" rx="5"/><rect x="88" y="8" width="24" height="12" rx="3"/><path d="M84 36h32M84 48h32M84 60h20M84 72h26"/></svg></div>
    <div class="body"><span class="letter c-cyan">A</span><span class="heading">Plan de cours</span><span class="desc">Le plan officiel de la session</span></div>
  </a>
  <a class="tile" href="#bases">
    <div class="art c-violet"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" role="img" aria-label="Microcontrôleur"><rect x="62" y="28" width="64" height="48" rx="6"/><rect x="80" y="42" width="28" height="20" rx="3"/><path d="M72 28v-8M84 28v-8M96 28v-8M108 28v-8M120 28v-8M72 76v8M84 76v8M96 76v8M108 76v8M120 76v8"/><circle cx="148" cy="52" r="5"/><path d="M148 57v14"/></svg></div>
    <div class="body"><span class="letter c-violet">B</span><span class="heading">Documents 1 à 12</span><span class="desc">Arduino, PlatformIO, C, affichage</span></div>
  </a>
  <a class="tile" href="#capteurs">
    <div class="art c-green"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" role="img" aria-label="Capteur sans fil"><rect x="68" y="34" width="44" height="44" rx="6"/><circle cx="90" cy="56" r="8"/><path d="M124 40a16 16 0 0 1 0 32M134 30a30 30 0 0 1 0 52"/></svg></div>
    <div class="body"><span class="letter c-green">C</span><span class="heading">Documents 20 à 28</span><span class="desc">Capteurs, horloge, UART, Wi-Fi</span></div>
  </a>
  <a class="tile" href="#projet">
    <div class="art c-amber"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" role="img" aria-label="Projet de session"><path d="M78 88V14M78 18h46l-8 12 8 12H78"/><path d="M66 88h28"/></svg></div>
    <div class="body"><span class="letter c-amber">D</span><span class="heading">Projet de session</span><span class="desc">Partie A et partie B</span></div>
  </a>
  <a class="tile" href="#ressources">
    <div class="art c-red"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" role="img" aria-label="Ressources"><rect x="76" y="24" width="44" height="56" rx="5"/><path d="M68 70V20a6 6 0 0 1 6-6h36"/><path d="M86 42h24M86 54h24M86 66h14"/></svg></div>
    <div class="body"><span class="letter c-red">E</span><span class="heading">98 et 99</span><span class="desc">Copier/coller et solutions</span></div>
  </a>
</nav>

<section class="bloc" id="presentation">
  <h2>Présentation sommaire du cours</h2>
  <p>Le cours <strong>Objets connectés</strong> initie l'étudiant aux capteurs d'environnement, aux différentes technologies d'affichage (écran ACL, diode lumineuse, etc.) et aux notions de base en électronique pour réaliser des objets connectés. À l'aide d'un microcontrôleur (Arduino Uno), il met en pratique des notions de base en programmation pour développer des applications simples. Finalement, l'étudiant est sensibilisé aux données générées par les objets connectés et aux manières de les sauvegarder et de les échanger de manière sécuritaire.</p>
  <dl class="faits">
    <div><dt>Programme</dt><dd>420.B0 · Techniques de l'informatique</dd></div>
    <div><dt>Famille</dt><dd>Mobiles et objets connectés</dd></div>
    <div><dt>Pondération</dt><dd>1-3-2</dd></div>
    <div><dt>Préalable</dt><dd>Aucun</dd></div>
  </dl>
  <p class="outils">Outils : <a href="https://wokwi.com/">Wokwi</a> et <a href="https://www.tinkercad.com/circuits">TinkerCad</a> (émulateurs Arduino en ligne), PlatformIO et l'Arduino IDE.</p>
</section>

<section class="bloc" id="enseignant">
  <h2>Horaire et disponibilités de l'enseignant</h2>
  <div class="enseignant">
    <img src="images/moi.jpg" width="120" height="120" alt="Alain Boudreault">
    <div>
      <p class="nom">Alain Boudreault</p>
      <p>Enseignant au département de Techniques de l'informatique, Cégep de Saint-Jérôme</p>
      <ul class="contact">
        <li><span>Courriel</span> <a href="mailto:Aboudrea@cstj.qc.ca">Aboudrea@cstj.qc.ca</a></li>
        <li><span>Téléphone</span> poste 6516</li>
        <li><span>Local</span> D125e</li>
      </ul>
    </div>
  </div>
  <div class="liens-horaire">
    <a class="btn-lien" href="images/Horaire-H26.png">Disponibilités pour la session H26</a>
    <a class="btn-lien" href="Documents/Calendriers_H26_CSTJ.pdf">Calendrier scolaire H26 (PDF)</a>
  </div>
</section>

<div id="documents"></div>

<section class="bloc" id="plan">
  <h2><span class="lettre c-cyan">A</span> Plan de cours</h2>
  <div class="docs c-cyan">
    <a class="doc" href="Documents/420-1C4-JR_ab_pc_H26.pdf"><span class="vignette dessin c-cyan"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M72 14h56a5 5 0 0 1 5 5v64a5 5 0 0 1-5 5H72a5 5 0 0 1-5-5V19a5 5 0 0 1 5-5z"/><rect x="88" y="8" width="24" height="12" rx="3"/><path d="M80 36h40M80 48h40M80 60h26M80 72h32"/></svg></span><span class="info"><span class="n">01</span><span class="titre">Plan de cours H26 (PDF)</span></span></a>
    <a class="doc" href="Documents/Plan-de-cours.html"><span class="vignette dessin c-cyan"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M72 14h56a5 5 0 0 1 5 5v64a5 5 0 0 1-5 5H72a5 5 0 0 1-5-5V19a5 5 0 0 1 5-5z"/><rect x="88" y="8" width="24" height="12" rx="3"/><path d="M80 36h40M80 48h40M80 60h26M80 72h32"/></svg></span><span class="info"><span class="n">+</span><span class="titre">Plan de cours, version texte</span></span></a>
  </div>
</section>

<section class="bloc" id="bases">
  <h2><span class="lettre c-violet">B</span> Documents 1 à 12</h2>
  <div class="docs c-violet">
    <a class="doc" href="Documents/Introduction-microcontroleurs.html"><span class="vignette entier"><img src="images/vignettes/intro.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">02</span><span class="titre">Introduction aux microcontrôleurs</span><span class="notes">Arduino Uno · émulateurs en ligne : Wokwi, TinkerCad</span></span></a>
    <a class="doc" href="Documents/PlatformIO-Hello-world.html"><span class="vignette entier"><img src="images/vignettes/platformio.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">03</span><span class="titre">Hello World – PlatformIO</span></span></a>
    <a class="doc" href="Documents/Hello-world.html"><span class="vignette"><img src="images/vignettes/hello-ide.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">+</span><span class="titre">Hello World – Arduino IDE</span></span></a>
    <a class="doc" href="Documents/Serial-println-et-digitalread.html"><span class="vignette"><img src="images/vignettes/serial.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">04</span><span class="titre">Serial.println(val), digitalRead() et while() pour la gestion du bouton</span></span></a>
    <a class="doc" href="Documents/analogRead.html"><span class="vignette"><img src="images/vignettes/analog.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">05</span><span class="titre">Lecture/écriture d'une valeur analogique – analogRead(), analogWrite(), PWM</span></span></a>
    <a class="doc" href="Documents/LCD-enum-ifdef.html"><span class="vignette"><img src="images/vignettes/lcd.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">06</span><span class="titre">Grove – Module LCD-RGB i2c (sprintf, switch, #ifdef, op ternaire, i % j)</span></span></a>
    <a class="doc" href="Documents/Compilation-conditionnelle.html"><span class="vignette"><img src="images/vignettes/compilation.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">07</span><span class="titre">Compilation conditionnelle</span></span></a>
    <a class="doc" href="Documents/Utilisation-de-librairies.html"><span class="vignette"><img src="images/vignettes/librairies.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">+</span><span class="titre">Les librairies</span></span></a>
    <a class="doc" href="Documents/Electronique-concepts-de-base.html"><span class="vignette entier"><img src="images/vignettes/electronique.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">+</span><span class="titre">Électronique – concepts de base</span></span></a>
    <a class="doc" href="Documents/Instruction-enum.html"><span class="vignette"><img src="images/vignettes/enum.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">08</span><span class="titre">L'instruction « enum » du langage C</span><span class="option">TP02</span></span></a>
    <a class="doc" href="Documents/Structures-de-donnees.html"><span class="vignette"><img src="images/vignettes/structures.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">09</span><span class="titre">Structures de données</span></span></a>
    <a class="doc" href="Documents/Operations-sur-les-bits-et-structure-de-donnees.html"><span class="vignette"><img src="images/vignettes/bits.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">10</span><span class="titre">Opérations sur les bits et structures de données</span><span class="option">TP02</span></span></a>
    <a class="doc" href="Documents/copier-coller.html"><span class="vignette"><img src="images/vignettes/copier-coller.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">11</span><span class="titre">Copier/coller pour ANSI et boîte</span><span class="notes">Les variables de type scalaire · gestion du bruit sur un bouton – bounce2</span></span></a>
    <a class="doc" href="Documents/Capteur-temperature-humidite.html"><span class="vignette"><img src="images/vignettes/temperature.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">12</span><span class="titre">Température, humidité et affichage sur 7 segments – 4Digit</span><span class="notes">Installer une librairie à la main</span></span></a>
  </div>
</section>

<section class="bloc" id="capteurs">
  <h2><span class="lettre c-green">C</span> Documents 20 à 28</h2>
  <div class="docs c-green">
    <a class="doc" href="Documents/NEOPixel.html"><span class="vignette"><img src="images/vignettes/neopixel.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">20</span><span class="titre">Buzzer et NeoPixel</span></span></a>
    <a class="doc" href="Documents/RTC-DS1307.html"><span class="vignette"><img src="images/vignettes/rtc.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">21</span><span class="titre">Real Time Clock (RTC)</span></span></a>
    <a class="doc" href="https://ve2cuy.com/420-1c4/index.php/detecteur-de-mouvements/"><span class="vignette dessin c-green"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><circle cx="100" cy="54" r="10"/><path d="M82 36a26 26 0 0 0 0 36M118 36a26 26 0 0 1 0 36M70 26a42 42 0 0 0 0 56M130 26a42 42 0 0 1 0 56"/></svg></span><span class="info"><span class="n">22</span><span class="titre">Détecteur de mouvements</span></span></a>
    <a class="doc" href="Documents/Operations-non-bloquantes.html"><span class="vignette dessin c-green"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><circle cx="100" cy="54" r="30"/><path d="M100 54V36M100 54l12 8M92 14h16M100 14v10"/></svg></span><span class="info"><span class="n">23</span><span class="titre">Opérations non bloquantes – millis() et interruptions</span><span class="option">TP02</span></span></a>
    <a class="doc" href="Documents/Communication-UART-entre-2-arduino.html"><span class="vignette"><img src="images/vignettes/uart.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">24</span><span class="titre">Communication UART entre deux Arduino</span><span class="option">TP02</span></span></a>
    <a class="doc" href="Documents/ESP-Wifi.html"><span class="vignette"><img src="images/vignettes/wifi.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">25</span><span class="titre">ESP-Wifi – accès réseau</span><span class="option">TP02</span></span></a>
    <div class="doc sans-lien"><span class="vignette dessin c-green"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><rect x="70" y="30" width="44" height="48" rx="6"/><circle cx="92" cy="54" r="10"/><path d="M124 44l14-6M124 54h16M124 64l14 6"/></svg></span><span class="info"><span class="n">26</span><span class="titre">Détecteur infrarouge</span><span class="option">optionnel</span></span></div>
    <div class="doc sans-lien"><span class="vignette dessin c-green"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><rect x="68" y="24" width="64" height="52" rx="5"/><path d="M80 24v-10M92 24v-10M104 24v-10M116 24v-10M80 76v10M92 76v10M104 76v10M116 76v10M84 44h32M84 56h20"/></svg></span><span class="info"><span class="n">27</span><span class="titre">EEPROM</span><span class="option">optionnel</span></span></div>
    <a class="doc" href="Documents/capteur-rfid.html"><span class="vignette"><img src="images/vignettes/rfid.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">28</span><span class="titre">Capteur RFID</span><span class="option">optionnel · défi TP02</span></span></a>
  </div>
</section>

<section class="bloc" id="projet">
  <h2><span class="lettre c-amber">D</span> Projet de session</h2>
  <div class="docs grande c-amber">
    <a class="doc" href="Documents/TP01-H26.html"><span class="vignette"><img src="images/vignettes/tp01.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">A</span><span class="titre">Partie A · TP01 – Le système de surveillance H26</span></span></a>
    <a class="doc" href="Documents/ES-H26-Volet-A.html"><span class="vignette"><img src="images/vignettes/es-volet-a.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">B</span><span class="titre">Partie B · TP02 – Épreuve synthèse, volet A</span></span></a>
  </div>
</section>

<section class="bloc" id="ressources">
  <h2><span class="lettre c-red">E</span> 98 et 99</h2>
  <div class="docs c-red">
    <a class="doc" href="Documents/copier-coller.html"><span class="vignette"><img src="images/vignettes/copier-coller.webp" alt="" loading="lazy" width="480"></span><span class="info"><span class="n">98</span><span class="titre">Les copier/coller</span></span></a>
    <a class="doc" href="Documents/Solutions.html"><span class="vignette dessin c-red"><svg viewBox="0 0 200 100" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><circle cx="100" cy="52" r="32"/><path d="M84 52l11 11 21-22"/></svg></span><span class="info"><span class="n">99</span><span class="titre">Solutions aux laboratoires</span></span></a>
  </div>
</section>
