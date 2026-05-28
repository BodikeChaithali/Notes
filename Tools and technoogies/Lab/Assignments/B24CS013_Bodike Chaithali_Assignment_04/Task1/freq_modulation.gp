set terminal pngcairo size 1600,900 enhanced font "Times,14"
set output "freq_modulation.png"

set xrange [0:1]
set samples 2000
set format y "%.2f"
set format x "%.2f"

Am = 1.0
fm = 5.0
Ac = 2.0
fc = 50.0
kf = 5.0

m(t)  = Am * cos(2*pi*fm*t)
c(t)  = Ac * cos(2*pi*fc*t)
FM(t) = Ac * cos(2*pi*fc*t + kf * sin(2*pi*fm*t))

set multiplot

set origin 0,0.6667
set size 1,0.3333
set title "Message Signal: m(t)"
set xlabel ""
set ylabel "m(t)"
plot [t=0:1] m(t) with linespoints lc rgb "blue" lw 2 lt 1 pt 7 title "m(t)"

set origin 0,0.3333
set size 1,0.3333
set title "Carrier Signal: c(t)"
set xlabel ""
set ylabel "c(t)"
plot [t=0:1] c(t) with linespoints lc rgb "green" lw 2 lt 2 pt 5 title "c(t)"

set origin 0,0.0
set size 1,0.3333
set title "Frequency Modulated Signal: FM(t)"
set xlabel "Time (s)"
set ylabel "FM(t)"
plot [t=0:1] FM(t) with linespoints lc rgb "red" lw 2 lt 3 pt 9 title "FM(t)"

unset multiplot
set output

