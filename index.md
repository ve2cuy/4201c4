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
  <ol class="toc">
    <li><span class="n">01</span><a href="Documents/420-1C4-JR_ab_pc_H26.pdf">Plan de cours H26 (PDF)</a></li>
    <li><span class="n"></span><a href="Documents/Plan-de-cours.html">Plan de cours, version texte</a></li>
  </ol>
</section>

<section class="bloc" id="bases">
  <h2><span class="lettre c-violet">B</span> Documents 1 à 12</h2>
  <ol class="toc">
    <li><span class="n">02</span><a href="Documents/Introduction-microcontroleurs.html">Introduction aux microcontrôleurs</a></li>
    <li class="sous"><span class="n"></span>Arduino Uno</li>
    <li class="sous"><span class="n"></span><span>Émulateurs Arduino en ligne : <a href="https://wokwi.com/">Wokwi</a>, <a href="https://www.tinkercad.com/circuits">TinkerCad</a></span></li>
    <li><span class="n">03</span><a href="Documents/PlatformIO-Hello-world.html">Hello World – PlatformIO</a></li>
    <li class="sous"><span class="n"></span><a href="Documents/Hello-world.html">Hello World – Arduino IDE</a></li>
    <li><span class="n">04</span><a href="Documents/Serial-println-et-digitalread.html">Serial.println(val), digitalRead() et l'instruction while() pour la gestion du bouton</a></li>
    <li><span class="n">05</span><a href="Documents/analogRead.html">Lecture/écriture d'une valeur analogique – analogRead(), analogWrite(), PWM</a></li>
    <li><span class="n">06</span><a href="Documents/LCD-enum-ifdef.html">Grove – Module LCD-RGB i2c (sprintf, switch, io stream, #ifdef, op ternaire, i % j)</a></li>
    <li><span class="n">07</span><a href="Documents/Compilation-conditionnelle.html">Compilation conditionnelle</a></li>
    <li class="sous"><span class="n"></span><a href="Documents/Utilisation-de-librairies.html">Les librairies</a></li>
    <li class="sous"><span class="n"></span><a href="Documents/Electronique-concepts-de-base.html">Électronique – concepts de base</a></li>
    <li><span class="n">08</span><a href="Documents/Instruction-enum.html">L'instruction « enum » du langage C (TP02)</a></li>
    <li><span class="n">09</span><a href="Documents/Structures-de-donnees.html">Structures de données</a></li>
    <li><span class="n">10</span><a href="Documents/Operations-sur-les-bits-et-structure-de-donnees.html">Opérations sur les bits et structures de données (TP02)</a></li>
    <li><span class="n">11</span><a href="Documents/copier-coller.html">Copier/coller pour ANSI et boîte</a></li>
    <li class="sous"><span class="n"></span>Les variables de type scalaire</li>
    <li class="sous"><span class="n"></span>Gestion du bruit sur un bouton – bounce2</li>
    <li><span class="n">12</span><a href="Documents/Capteur-temperature-humidite.html">Température, humidité et affichage sur 7 segments – 4Digit (installer une librairie à la main)</a></li>
  </ol>
</section>

<section class="bloc" id="capteurs">
  <h2><span class="lettre c-green">C</span> Documents 20 à 28</h2>
  <ol class="toc">
    <li><span class="n">20</span><a href="Documents/NEOPixel.html">Buzzer et NeoPixel</a></li>
    <li><span class="n">21</span><a href="Documents/RTC-DS1307.html">Real Time Clock (RTC)</a></li>
    <li><span class="n">22</span><a href="https://ve2cuy.com/420-1c4/index.php/detecteur-de-mouvements/">Détecteur de mouvements</a></li>
    <li><span class="n">23</span><a href="Documents/Operations-non-bloquantes.html">Opérations non bloquantes – millis() et interruptions (TP02)</a></li>
    <li><span class="n">24</span><a href="Documents/Communication-UART-entre-2-arduino.html">Communication UART entre deux Arduino (TP02)</a></li>
    <li><span class="n">25</span><a href="Documents/ESP-Wifi.html">ESP-Wifi – accès réseau (TP02)</a></li>
    <li><span class="n">26</span>Détecteur infrarouge <em>– contenu optionnel</em></li>
    <li><span class="n">27</span>EEPROM <em>– contenu optionnel</em></li>
    <li><span class="n">28</span><a href="Documents/capteur-rfid.html">Capteur RFID <em>– contenu optionnel (défi : TP02)</em></a></li>
  </ol>
</section>

<section class="bloc" id="projet">
  <h2><span class="lettre c-amber">D</span> Projet de session</h2>
  <div class="parties">
    <a class="partie" href="Documents/TP01-H26.html"><span class="tag c-amber">partie A · TP01</span><span class="heading">Le système de surveillance H26</span><span class="desc">Partie A du projet de session</span></a>
    <a class="partie" href="Documents/ES-H26-Volet-A.html"><span class="tag c-amber">partie B · TP02</span><span class="heading">Épreuve synthèse – volet A</span><span class="desc">Énoncé du projet de l'épreuve synthèse du cours</span></a>
  </div>
</section>

<section class="bloc" id="ressources">
  <h2><span class="lettre c-red">E</span> 98 et 99</h2>
  <ol class="toc">
    <li><span class="n">98</span><a href="Documents/copier-coller.html">Les copier/coller</a></li>
    <li><span class="n">99</span><a href="Documents/Solutions.html">Solutions aux laboratoires</a></li>
  </ol>
</section>
