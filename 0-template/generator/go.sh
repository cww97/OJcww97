pandoc --template algo --filter generator/minted.py --pdf-engine=xelatex --no-highlight --pdf-engine-opt="-shell-escape" -o t.tex --from markdown -V monofont="Source Code Pro" -V secnumdepth=2 -V --number-sections --toc -V include-before="\renewcommand\labelitemi{$\bullet$}" -V header-includes="\usepackage{minted}" -V geometry="margin=2cm" *-*.md
latexmk -xelatex -shell-escape t.tex
latexmk -c
cp t.pdf template.pdf
