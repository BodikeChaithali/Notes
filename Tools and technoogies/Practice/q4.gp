set style data histograms
set style fill pattern 2 border 1 lc rgb "black"
set style fill empty
# control bar width
set title "Item 1 Stock Prices"
set xlabel "Month"
set ylabel "Price ($)"
set xtics rotate by -45
set yrange [100:145]
plot "file2.dat" using 2:xtic(1) title "Item 1"
pause -1
