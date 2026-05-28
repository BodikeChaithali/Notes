set terminal pdfcairo size 20cm,14cm font "Times New Roman,12"
set output "stock_prices_12months.pdf"

set title "Monthly Stock Price Comparison (4 Items)"
set xlabel "Month"
set ylabel "Price ($)"

# Define x-axis as months
set xtics rotate by -45
set xtics ("Jan" 1,"Feb" 2,"Mar" 3,"Apr" 4,"May" 5,"Jun" 6,"Jul" 7,"Aug" 8,"Sep" 9,"Oct" 10,"Nov" 11,"Dec" 12)

# Define styles (force color + dash type + line width)
set style line 1 lc rgb "blue"   lw 2 dashtype solid      # Blue solid
set style line 2 lc rgb "red"    lw 2 dashtype 2          # Red dashed
set style line 3 lc rgb "green"  lw 2 dashtype 3          # Green dotted
set style line 4 lc rgb "orange" lw 2 dashtype 4          # Orange dash-dot

set key left top box

plot \
    "item1.dat" using ($0+1):2 with lines ls 1 title "Item 1 (Blue - Solid)", \
    "item2.dat" using ($0+1):2 with lines ls 2 title "Item 2 (Red - Dashed)", \
    "item3.dat" using ($0+1):2 with lines ls 3 title "Item 3 (Green - Dotted)", \
    "item4.dat" using ($0+1):2 with lines ls 4 title "Item 4 (Orange - Dash-dot)"

set output
