main: *.o
	g++	-o	main  *.o

*.o:  *.h	*.cpp
	g++	-g	-c	*.cpp

run:
	./main

clean:
	rm	*.o	main
leak:
	valgrind --leak-check=full ./main
debug:
	gdb ./main