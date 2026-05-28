if [ $# -ne 2 ]; then
	echo "please provide exactly 2 arguments."
	exit 1
fi
x=$1
y=$2
sum=`expr $x + $y`
if [ $? -ne 0 ]; then
	echo "Please provide valid integer numbers."
	exit 2
else
	echo "The sum:$sum"
fi
