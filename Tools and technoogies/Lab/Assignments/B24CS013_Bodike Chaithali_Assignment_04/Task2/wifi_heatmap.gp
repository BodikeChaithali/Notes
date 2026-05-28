set terminal pngcairo size 1600,900 enhanced font "Times,14"
set output "wifi_heatmap.png"

set title "Wi-Fi Signal Strength Distribution (8 m × 8 m Room)"
set xlabel "X position (meters)"
set ylabel "Y position (meters)"
set xrange [0:8]
set yrange [0:8]

set samples 200
set isosamples 200

Ax = 2; Ay = 2; PA = 100
Bx = 6; By = 3; PB = 90
Cx = 4; Cy = 6; PC = 80

SA(x,y) = PA / ( (x - Ax)**2 + (y - Ay)**2 + 1 )
SB(x,y) = PB / ( (x - Bx)**2 + (y - By)**2 + 1 )
SC(x,y) = PC / ( (x - Cx)**2 + (y - Cy)**2 + 1 )

ST(x,y) = SA(x,y) + SB(x,y) + SC(x,y)

set palette defined (0 "blue", 0.25 "cyan", 0.5 "green", 0.75 "yellow", 1 "red")

set colorbox vertical
set cblabel "Signal Strength (arb. units)"

set pm3d map
set pm3d interpolate 4,4

splot ST(x,y) with pm3d notitle

unset output

