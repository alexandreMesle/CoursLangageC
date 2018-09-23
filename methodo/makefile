all : eMails eMails.tgz

util.o:	util.c util.h
	gcc -Wall -c util.c

tableau.o: tableau.c tableau.h util.h
	gcc -Wall -c tableau.c

eMails.o: eMails.c tableau.h util.h
	gcc -Wall -c eMails.c

eMails: util.o tableau.o eMails.o
	gcc -o eMails -Wall util.o tableau.o eMails.o

eMails.tgz: util.h util.c tableau.h tableau.c eMails.c makefile
	tar cvfz eMails.tgz util.h util.c tableau.h tableau.c eMails.c makefile