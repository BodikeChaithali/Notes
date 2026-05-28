set term qt font "Arial,12"
set multiplot title "Sine and Cosine Functions" font "Helvetica-Bold,14"
# First plot
set origin 0.0,0.0
# (x,y) position in [0,1] scale
set size 0.5,1.0
# width=50%, height=100%
set title "sin(x)"
plot sin(x) with lines lw 2 lc rgb "blue"
# Second plot
set origin 0.5,0.0
# shift to right half
set size 0.5,1.0
set title "cos(x)"
plot cos(x) with lines lw 2 lc rgb "red"
unset multiplot
pause -1
