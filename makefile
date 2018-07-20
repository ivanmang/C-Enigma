# edit this makefile so that running make compiles your enigma program

enigma: Main.o Rotors.o Reflector.o Plugboard.o
	g++ -o enigma Main.o Rotors.o Reflector.o Plugboard.o

Main.o: Main.cpp
	g++ -c Main.cpp

Rotors.o: Rotors.cpp
	g++ -c Rotors.cpp

Reflector.o: Reflector.cpp
	g++ -c Reflector.cpp

Plugboard.o: Plugboard.cpp
	g++ -c Plugboard.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
