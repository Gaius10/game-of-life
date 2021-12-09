live: main.o FileDrawer.o Game.o Table.o
	g++ main.o FileDrawer.o Game.o Table.o -o live

main.o:
	g++ -c main.cpp -o main.o

FileDrawer.o:
	g++ -c ./src/FileDrawer.cpp -o ./FileDrawer.o

Game.o:
	g++ -c ./src/Game.cpp -o ./Game.o

Table.o:
	g++ -c ./src/Table.cpp -o ./Table.o

.PHONY:	clean
clean:
	rm -f *.o