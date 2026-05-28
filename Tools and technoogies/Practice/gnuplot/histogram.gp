set terminal pdfcairo size 18cm,12cm font "Times New Roman,12"
set output "avg_temperature_histogram.pdf"
set style data histogram
set style fill solid 0.7 border -1
set boxwidth 0.7 relative
set title "Average Monthly Temperature (°C)"
set xlabel "Month"
set ylabel "Temperature (°C)"
set xtics rotate by -30 
set grid ytics
set yrange [0:*]
plot "avg_temperature.dat" using 2:xtic(1) title "avg temp" lc rgb "blue"
