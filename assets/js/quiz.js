// Quiz de compréhension à la fin d'un document (questions de _data/quiz/<document>.yml,
// placées dans la page par _layouts/default.html). Vrai ou faux et choix multiple; le résultat
// et les bonnes réponses s'affichent à la fin. Le résultat est gardé dans le navigateur du poste
// (localStorage, clé « ve2cuy-quiz:<chemin de la page> ») : la page d'accueil le lit pour
// marquer la vignette du document.
(() => {
  const donnees = document.getElementById("quiz-donnees");
  const zone = document.getElementById("quiz");
  if (!donnees || !zone) return;
  let quiz;
  try { quiz = JSON.parse(donnees.textContent); } catch (e) { return; }
  const questions = (quiz.questions || []).filter((q) => q && q.question);
  if (!questions.length) return;

  const cle = "ve2cuy-quiz:" + location.pathname.replace(/\.html$/, "").replace(/\/$/, "/index");
  const lire = () => { try { return JSON.parse(localStorage.getItem(cle)) || null; } catch (e) { return null; } };
  const ecrire = (v) => { try { localStorage.setItem(cle, JSON.stringify(v)); } catch (e) {} };

  const el = (tag, cls, texte) => { const e = document.createElement(tag); if (cls) e.className = cls; if (texte != null) e.textContent = texte; return e; };
  const dateCourte = (iso) => { try { return new Date(iso).toLocaleDateString("fr-CA", { day: "numeric", month: "long", year: "numeric" }); } catch (e) { return iso; } };

  // Choix d'une question : « vf » (vrai ou faux) ou une liste « choix »; « reponse » est
  // « vrai »/« faux » ou le numéro du bon choix (à partir de 1).
  const choixDe = (q) => q.type === "vf" || !q.choix ? ["Vrai", "Faux"] : q.choix.map(String);
  const bonIndex = (q) => {
    if (q.type === "vf" || !q.choix) return String(q.reponse).toLowerCase().startsWith("v") || q.reponse === true ? 0 : 1;
    return Number(q.reponse) - 1;
  };

  const titre = el("h2", null, quiz.titre || "Quiz de compréhension");
  const intro = el("p", "quiz-intro");
  const nbVf = questions.filter((q) => q.type === "vf" || !q.choix).length;
  intro.textContent = `${questions.length} questions` +
    (nbVf && nbVf < questions.length ? " · vrai ou faux et choix multiple" : nbVf ? " · vrai ou faux" : " · choix multiple") +
    ". Répondez à toutes les questions : votre résultat et les bonnes réponses s'affichent à la fin.";
  const deja = el("p", "quiz-deja");
  const form = el("form", "quiz-form");
  form.noValidate = true;
  const resultat = el("div", "quiz-resultat");
  resultat.setAttribute("role", "status");
  resultat.tabIndex = -1;
  resultat.hidden = true;

  const blocs = questions.map((q, i) => {
    const fs = el("fieldset", "quiz-q");
    const lg = el("legend");
    lg.append(el("span", "quiz-num", `Question ${i + 1} / ${questions.length}`), el("span", "quiz-texte", q.question));
    fs.append(lg);
    const opts = el("div", "quiz-choix" + (q.type === "vf" || !q.choix ? " vf" : ""));
    choixDe(q).forEach((c, j) => {
      const lab = el("label", "quiz-option");
      const inp = el("input");
      inp.type = "radio"; inp.name = "q" + i; inp.value = String(j);
      lab.append(inp, el("span", null, c));
      opts.append(lab);
    });
    const corr = el("p", "quiz-correction");
    corr.hidden = true;
    fs.append(opts, corr);
    form.append(fs);
    return { q, fs, corr };
  });

  const pied = el("div", "quiz-pied");
  const compte = el("span", "quiz-compte");
  const envoyer = el("button", "quiz-bouton", "Voir mon résultat");
  envoyer.type = "submit";
  const recommencer = el("button", "quiz-bouton secondaire", "Recommencer le quiz");
  recommencer.type = "button";
  recommencer.hidden = true;
  pied.append(compte, envoyer, recommencer);
  form.append(pied);

  const repondues = () => blocs.filter((b, i) => form.querySelector(`input[name="q${i}"]:checked`)).length;
  const majCompte = () => {
    const n = repondues();
    compte.textContent = `${n} / ${questions.length} répondues`;
    envoyer.disabled = n < questions.length;
  };
  const majDeja = () => {
    const r = lire();
    deja.hidden = !r;
    if (r) deja.textContent = `Quiz déjà fait sur ce poste le ${dateCourte(r.date)} : ${r.score} / ${r.total}` +
      (r.meilleur != null && r.meilleur !== r.score ? ` (meilleur résultat : ${r.meilleur} / ${r.total})` : "") + ".";
  };

  form.addEventListener("change", majCompte);
  form.addEventListener("submit", (ev) => {
    ev.preventDefault();
    if (repondues() < questions.length) return;
    let score = 0;
    blocs.forEach(({ q, fs, corr }, i) => {
      const choisi = Number(form.querySelector(`input[name="q${i}"]:checked`).value);
      const bon = bonIndex(q);
      const juste = choisi === bon;
      if (juste) score++;
      fs.classList.add(juste ? "juste" : "faux");
      fs.querySelectorAll(".quiz-option").forEach((lab, j) => {
        if (j === bon) lab.classList.add("bonne");
        else if (j === choisi) lab.classList.add("mauvaise");
      });
      fs.querySelectorAll("input").forEach((inp) => { inp.disabled = true; });
      corr.replaceChildren(
        el("strong", null, juste ? "Bonne réponse." : `Réponse attendue : ${choixDe(q)[bon]}.`),
        ...(q.explication ? [" ", q.explication] : []),
      );
      corr.hidden = false;
    });
    const total = questions.length;
    const avant = lire();
    ecrire({ score, total, meilleur: Math.max(score, avant && avant.total === total ? avant.meilleur ?? avant.score : 0), date: new Date().toISOString() });
    const pc = Math.round((100 * score) / total);
    resultat.className = "quiz-resultat " + (pc >= 80 ? "fort" : pc >= 60 ? "moyen" : "faible");
    resultat.replaceChildren(
      el("span", "quiz-score", `${score} / ${total}`),
      el("span", "quiz-message", pc === 100 ? "Parfait! Toutes les réponses sont bonnes." :
        pc >= 80 ? "Très bien! Revoyez les questions en rouge ci-dessous." :
        pc >= 60 ? "Pas mal. Relisez les sections liées aux questions en rouge." :
        "Relisez le document, puis recommencez le quiz."),
    );
    resultat.hidden = false;
    envoyer.hidden = true;
    compte.hidden = true;
    recommencer.hidden = false;
    majDeja();
    deja.hidden = true;
    resultat.scrollIntoView({ behavior: "smooth", block: "center" });
    resultat.focus({ preventScroll: true });
  });
  recommencer.addEventListener("click", () => {
    form.reset();
    blocs.forEach(({ fs, corr }) => {
      fs.classList.remove("juste", "faux");
      fs.querySelectorAll(".quiz-option").forEach((lab) => lab.classList.remove("bonne", "mauvaise"));
      fs.querySelectorAll("input").forEach((inp) => { inp.disabled = false; });
      corr.hidden = true;
    });
    resultat.hidden = true;
    envoyer.hidden = false;
    compte.hidden = false;
    recommencer.hidden = true;
    majCompte();
    majDeja();
    titre.scrollIntoView({ behavior: "smooth", block: "start" });
  });

  zone.replaceChildren(titre, intro, deja, resultat, form);
  majCompte();
  majDeja();
})();
