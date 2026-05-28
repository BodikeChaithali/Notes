set style data histograms
set style histogram cluster gap 1
set style fill solid 0.7 border -1
set boxwidth 0.9 relative
set title "Monthly Stock Price Comparison"
set xlabel "Month"
set ylabel "Price ($)"
set key outside top center
set xtics rotate by -45
plot "stock.dat" using 2:xtic(1) title "Item 1" lc rgb "blue", \
"" using 3 title "Item 2" lc rgb "red", \
"" using 4 title "Item 3" lc rgb "green", \
"" using 5 title "Item 4" lc rgb "orange"
pause -1
