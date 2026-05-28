set terminal qt font "Arial,12" size 800,600
set xrange[-10:10]
set yrange[-2:2]
set lmargin 10
set rmargin 5
set tmargin 3
set xlabel "X-Axis (units)" font "Times-Bold,14"
set ylabel "Y-Axis (units)" font "Times-Italic,14"
set title "Customized Plot in Gnuplot" font "Helvetica-BoldItalic,16"
set grid
set key top left
plot sin(x) lt 1 lc rgb "red" lw 2 title "sinx(x)", \
     cos(x) lt 2 lc rgb "blue" lw 2 title "cos(x)", \
     tan(x) lt 3 lc rgb "#008000" lw 1 title "tan(x)"
pause -1
