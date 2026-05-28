set terminal pdfcairo size 20cm,14cm font "Times New Roman,12"
set output "monthly_expenses.pdf"
set title "Monthly Expenses"
set style data histogram
set style fill pattern 4 border 1
set boxwidth 0.8
set xtics rotate by -45
set xlabel "Month"
set ylabel "Expenses ($)"
set yrange [0:1400]
set grid
plot "expenses.dat" using 2:xtic(1) title "Expenses" lc rgb "blue"
unset output
unset terminal
