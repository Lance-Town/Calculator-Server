all: server client

server: server.o calc.o
	gcc server.o calc.o -o server

client: client.o
	gcc client.o -o client

server.o: server.c
	gcc -c server.c

calc.o: calc.c calc.h
	gcc -c calc.c

client.o: client.c
	gcc -c client.c

clean:
	-rm *.o

cleanAll:
	clean
	-rm server client
