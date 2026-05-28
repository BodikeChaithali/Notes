set terminal pdfcairo size 20cm, 14cm enhanced font "Times New Roman,16“
set output "surface.pdf“
set title "3D Surface Plot Example“
set xlabel "X”
set ylabel "Y”
set zlabel "Z”
set pm3d
set hidden3d
set view 60,30
splot 'surface.dat' using 1:2:3 with pm3d
unset output
unset terminal
