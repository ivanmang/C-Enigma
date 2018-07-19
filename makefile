# edit this makefile so that running make compiles your enigma program

enigma: Main.o Rotors.o
	g++ -o enigma Main.o Rotors.o

Main.o: Main.cpp
	g++ -c Main.cpp

Rotors.o: Rotors.cpp
	g++ -c Rotors.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
