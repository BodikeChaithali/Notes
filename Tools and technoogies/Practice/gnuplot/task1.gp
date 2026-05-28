set terminal pdfcairo size 20cm,14cm font "Times New Roman,14"
set output "multiplot_2d.pdf"
set multiplot layout 2,2 title "2x2 Multiplot Example"
f1(x)=sin(x)+cos(x)+1
f2(x)=x**2+x**3
a=2
f3(x)=4*a*(x**2)
f4(x)=sin(x)/exp(-x)

set title "sin(x)+cos(x)+1"
plot f1(x) with lines lw 2 lc rgb "blue"
set title "x**2+x**3"
plot f2(x) with lines lw 2 lc rgb "red"
set title "f3(x)"
plot f3(x) with lines lw 2 lc rgb "orange"
set title "f4(x)"
plot f4(x) with lines lw 2 lc rgb "black"
unset multiplot
unset output
