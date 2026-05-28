set terminal pdfcairo size 20cm,14cm font "Times New Roman,12"
set output "annual_sales.pdf"
set title "Annual Sales Performance by Region (4 Companies)"
set style data histogram
set style histogram clustered gap 1
set style fill solid 0.7 border -1
set boxwidth 0.8 relative
set xlabel "Region"
set ylabel "Sales (in Million $)"
set xtics rotate by -30
set grid ytics
set key outside top right horizontal box width 2 height 0.8 spacing 1.:w2

set style line 1 lc rgb "blue" dt 1
set style line 2 lc rgb "red" dt 2
set style line 3 lc rgb "green" dt 3
set style line 4 lc rgb "orange" dt 4

set autoscale y

plot "annual_sales.dat" using 2:xtic(1) title "Company A" ls 1, \
"" using 3:xtic(1) title "Company B" ls 2, \
"" using 4:xtic(1) title "Company C" ls 3, \
"" using 5:xtic(1) title "Company D" ls 4

unset output
