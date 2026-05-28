set terminal pdfcairo size 20cm,14cm font "Times New Roman,14"
set output "multiplot_2d.pdf"
set multiplot layout 2,2 title "Plots with 4 Functions"
f1(x)=sin(x)+cos(x)+1
f2(x)=x**2+x**3
a=2
f3(x)=4*a*x**2
f4(x)=sin(x)/exp(-x)

set title "f1(x)=sin(x)+cos(x)+1"
set xlabel "x"
set ylabel "f1(x)"
set key top left
plot f1(x) title "sin(x)+cos(x)+1" lw 2 dt 1 lt rgb "blue"

set title "f2(x)=x^2+x^3"
set xlabel "x"
set ylabel "f2(x)"
set key top left
plot f2(x) title "x^2+x^3" lw 2 dt 2 lt rgb "red"

set title "f3(x)=4ax^2(a=2)"
set xlabel "x"
set ylabel "f3(x)"
set key top left
plot f3(x) title "4.a.x^2(a=2)" lw 2 dt 3 lt rgb "green"

set title "f4(x)=sin(x)/e^{-x}"
set xlabel "x"
set ylabel "f4(x)"
set key top left
plot f4(x) title "sin(x)/e^{-x}" lw 2 dt 4 lt rgb "black"
unset multiplot
unset output
