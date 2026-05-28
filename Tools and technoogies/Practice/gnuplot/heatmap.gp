set terminal pdfcairo enhanced color font "Arial,12" size 8,4
set output "monsoon_heatmap.pdf"
set title "Monsoon Rainfall Intensity (June–September)"
set xlabel "Region"
set ylabel "Month"
set xtics ("Region 1" 1,"Region 2" 2,"Region 3" 3,"Region 4" 4,"Region 5" 5)
set ytics ("June" 6,"July" 7,"August" 8,"September" 9)
set palette defined (0 "blue",0.5 "orange",1 "red")
set colorbox
set cblabel "Rainfall(mm)"
set dgrid3d 30,50
set view map
splot "monsoon_rainfall.dat" using 1:2:3 with pm3d notitle
unset output
