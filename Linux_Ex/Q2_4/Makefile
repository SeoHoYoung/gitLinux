foobar : ./library/MathFuncMain.o ./library/Add.o ./library/Subtract.o ./library/Multiply.o ./library/Divide.o
	gcc -o foobar ./library/MathFuncMain.o ./library/Add.o ./library/Subtract.o ./library/Multiply.o ./library/Divide.o
./library/MathFuncMain.o : ./library/MathFuncMain.c
	gcc -c ./library/MathFuncMain.c
./library/Add.o : ./library/Add.c
	gcc -c ./library/Add.c
./library/Subtract.o : ./library/Subtract.c
	gcc -c ./library/Subtract.c
./library/Multiply.o : ./library/Multiply.c
	gcc -c ./library/Multiply.c
./library/Divide.o : ./library/Divide.c
	gcc -c ./library/Divide.c
clean :
	rm -f foobar ./library/MathFuncMain.o ./library/Add.o ./library/Subtract.o ./library/Multiply.o ./library/Divide.o
