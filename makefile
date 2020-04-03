main:main.o cmd.h cmd.o interface.h interface.o information.h information.o
	g++ main.o cmd.h cmd.o interface.h interface.o information.h information.o -g -o main
main.o:main.cpp
	g++ -c main.cpp -g -o main.o
cmd.o:cmd.cpp
	g++ -c cmd.cpp -g -o cmd.o
interface.o:interface.cpp
	g++ -c interface.cpp -g -o interface.o
information.o:information.cpp
	g++ -c information.cpp -g -o information.o
clean:
	rm *.o
	rm main
