set terminal pdfcairo size 20cm,14cm font "Times New Roman,14"
set output 'multiplot_2d.pdf'

f1(x)=sin(x)+cos(x)+1
f2(x)=x**2+x**3
a=2
f3(x)=4*a*x**2
f4(x)=sin(x)/exp(-x)

set multiplot layout 2,2 title "Plots with 4 Functions" font ",16"

set title "f1(x) = sin(x) + cos(x) + 1"
set xlabel "x"
set ylabel "f1(x)"
set xrange [-10:10]
set yrange [-2:3.5]
set key top right
plot f1(x) title "sin(x)+cos(x)+1" with lines lw 2 lt rgb "blue"

set title "f2(x) = x^2 + x^3"
set xlabel "x"
set ylabel "f2(x)"
set xrange [-2:2]
set yrange [-1:10]
set key top left
plot f2(x) title "x^2 + x^3" with lines lw 2 lt rgb "red"

set title "f3(x) = 4·a·x^2  (a = 2)  => 8 x^2"
set xlabel "x"
set ylabel "f3(x)"
set xrange [-5:5]
set yrange [0:220]
set key top left
plot f3(x) title "4·a·x^2 (a=2)" with lines lw 2 lt rgb "green"

set title "f4(x) = sin(x) / e^{-x}"
set xlabel "x"
set ylabel "f4(x)"
set xrange [-15:10]
set yrange [-15:10]
set key top right
plot f4(x) title "sin(x)/e^{-x}" with lines lw 2 lt rgb "black"

unset multiplot
set output
