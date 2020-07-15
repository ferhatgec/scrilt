# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
#

# PATHS
SRCLIBDIREC = ./Library/
SRCSYNTAXDIREC = ./src/Syntax/
SRCDIREC = ./src/
PREFIX = /bin/

INCLUDEDIR = ./include/src/
CFLAGS = -c -Wall -I$(INCLUDEDIR)

GCC = gcc
GPP = g++
COMP = g++ -c
HECOMP = g++ -c -Wall $< -std=gnu++17 -o

# CLEAN
CLEANALL = scrilt
CLEAN = *.o
HEADERFILE = CommandFunc.o GetNameFunction.o FileFunction.o RunFunction.o \
Log.o History.o Template.o Configuration.o

ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(CLEANALL)
endif


all: headersfile main clean

allp: headersfile mainc clean 

removeall: uninstall cleanall


runall: all run

gra: runall git

git:
	git add .
	git commit -a
	git push origin master

push:
	git push origin master

nall: cleanall

headersfile: $(HEADERFILE)


%.o: $(SRCSYNTAXDIREC)%.cpp
	$(GPP) $(CFLAGS) -c $< -o $@


main: $(SRCDIREC)Scrift.cpp
	$(GPP) $< $(HEADERFILE) -o scrilt
	echo Scrilt building successfully!

mainc: $(SRCDIREC)Scrift.cpp
	$(GPP) $< $(HEADERFILE) -o /bin/scrilt
	echo Scrilt building successfully in Bin Directory!

uninstall:
	rm -f /bin/scrilt
	
run:
	./scrilt
clean:
		$(CLEAN)

cleanall:
		echo Cleaning build directory!
		$(CLEANALL)
