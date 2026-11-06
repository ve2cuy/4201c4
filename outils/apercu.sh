#!/usr/bin/env bash
# Aperçu local du site, comme sur GitHub Pages : http://127.0.0.1:4000/4201c4/
# Les pages se reconstruisent à chaque fichier enregistré et le fureteur se recharge seul.
# Arrêt : Ctrl+C.
#
#   outils/apercu.sh            aperçu (port 4000)
#   outils/apercu.sh 4001       autre port
#   outils/apercu.sh --build    construire seulement, dans _site/ (vérifier qu'il n'y a pas d'erreur)
set -euo pipefail
cd "$(dirname "$0")/.."

RUBY_DIR="$(brew --prefix ruby 2>/dev/null || true)"
if [[ -z "$RUBY_DIR" || ! -x "$RUBY_DIR/bin/ruby" ]]; then
  echo "Ruby de Homebrew introuvable : brew install ruby" >&2
  exit 1
fi
export GEM_HOME="$HOME/.gem/pages"
export PATH="$GEM_HOME/bin:$RUBY_DIR/bin:$PATH"
export BUNDLE_GEMFILE="$PWD/outils/Gemfile"
export RUBYOPT="-r$PWD/outils/ruby4-compat.rb"
export PAGES_REPO_NWO="ve2cuy/4201c4"   # évite à jekyll-github-metadata d'interroger git

if ! bundle check >/dev/null 2>&1; then
  echo "Première fois : installation des gemmes de GitHub Pages (quelques minutes)…"
  bundle install --quiet
fi

OPTIONS=(--config _config.yml,outils/apercu.yml --baseurl /4201c4)
if [[ "${1:-}" == "--build" ]]; then
  exec bundle exec jekyll build "${OPTIONS[@]}"
fi
PORT="${1:-4000}"
echo "Aperçu : http://127.0.0.1:$PORT/4201c4/"
exec bundle exec jekyll serve "${OPTIONS[@]}" --host 127.0.0.1 --port "$PORT" --livereload
