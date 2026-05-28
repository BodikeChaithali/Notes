set terminal pdfcairo size 20cm,14cm font "Times New Roman,12"
set output "stock_prices_12months.pdf"
set title "Montly Stock Price Comparison (4 Items)"
set xlabel "Month"
set ylabel "Price ($)"
set xtics rotate by -45
set xtics ("Jan" 1,"Feb" 2,"Mar" 3,"Apr" 4,"May" 5,"Jun" 6,"Jul" 7,"Aug" 8,"Sep" 9,"Oct" 10,"Nov" 11,"Dec" 12)

set style line 1 lc rgb "blue" lw 2 dt 1
set style line 2 lc rgb "red" lw 2 dt 2
set style line 3 lc rgb "green" lw 2 dt 3
set style line 4 lc rgb "orange" lw 2 dt 4

set key left top box
plot "item1.dat" using 2:xtic(1) with lines ls 1 title "Item1 with blue color and solid", \
"item2.dat" using 2:xtic(1) with lines ls 2 title "Item2 with red color and dashed", \
"item3.dat" using 2:xtic(1) with lines ls 3 title "Item3 with green color and dotted", \
"item4.dat" using 2:xtic(1) with lines ls 4 title "Item4 with orange color and dashed-dotted"

unset output
