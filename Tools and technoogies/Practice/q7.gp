set terminal pdfcairo size 20cm,14cm enhanced font 'Times New Roman,12'
set output 'quake_heatmap.pdf'
set title "Earthquake Intensity Map"
set xlabel "Longitude"
set ylabel "Latitude"
set cblabel "Magnitude (Richter scale)“
set cbrange[0:7]
set palette defined (0 "#0000ff", 2 "#00ffff", 3.5 "#00ff00", 5 "#ffff00", 6.5 "#ff8000", 7 "#ff0000" )
set xrange [28:52]
set yrange [8:32]
set pm3d map
unset key
set border lw 1.5
splot 'quake_data.dat' using 1:2:3 with pm3d
unset output
unset terminal
