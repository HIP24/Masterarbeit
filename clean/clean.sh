find ../ -type f \( -name "*.aux" -o -name "*.bbl" -o -name "*.blg" -o -name "*.idx" -o -name "*.ind" -o -name "*.lof" -o -name "*.lot" -o -name "*.out" -o -name "*.toc" -o -name "*.acn" -o -name "*.acr" -o -name "*.alg" -o -name "*.glg" -o -name "*.glo" -o -name "*.gls" -o -name "*.ist" -o -name "*.fls" -o -name "*.log" -o -name "*.fdb_latexmk" -o -name "*.lol" -o -name "*.synctex.gz" -o -name "*.bcf" -o -name "*.run.xml" \) -exec rm -f {} \;
