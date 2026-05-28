set terminal pdfcairo size 20cm,14cm font "Times New Roman,12"
set output "annual_sales.pdf"

set title "Annual Sales Performance by Region (4 Companies)"
set xlabel "Region"
set ylabel "Sales (in Million $)"

set style data histograms
set style histogram clustered gap 1
set style fill solid 0.7 border 
set boxwidth 0.8

set grid ytics

set xtics rotate by -30

set key outside top right horizontal box

set style line 1 lc rgb "blue" lt 1 lw 2 dashtype solid
set style line 2 lc rgb "red" lt 2 lw 2 dashtype 2
set style line 3 lc rgb "green" lt 3 lw 2 dashtype 3
set style line 4 lc rgb "orange" lt 4 lw 2 dashtype 4

set autoscale y

plot 'annual_sales.dat' using 2:xtic(1) title "Company A" ls 1, \
     '' using 3 title "Company B" ls 2, \
     '' using 4 title "Company C" ls 3, \
     '' using 5 title "Company D" ls 4
