set terminal pngcairo size 800,600 enhanced font "Times New Roman,12"
set output "population_points.png"
set title "Population in 2000 (Point Plot)"
set xlabel "Country"
set ylabel "Population (in millions)"
set xtics rotate by -45
plot "file.dat" every ::1 using 2:xtic(1) with points pt 7 lc rgb "blue" title "2000"
pause -1
