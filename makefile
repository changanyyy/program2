main:main.o cmd.h cmd.o interface.h interface.o information.h information.o
	g++ -std=c++11 main.o cmd.h cmd.o interface.h interface.o information.h information.o -g -o main
main.o:main.cpp
	g++ -std=c++11 -c main.cpp -g -o main.o
cmd.o:cmd.cpp
	g++ -std=c++11 -c cmd.cpp -g -o cmd.o
interface.o:interface.cpp
	g++ -std=c++11 -c interface.cpp -g -o interface.o
information.o:information.cpp
	g++ -std=c++11 -c information.cpp -g -o information.o
clean:
	rm *.o
	rm main
