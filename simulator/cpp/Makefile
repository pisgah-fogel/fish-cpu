SHELL = /bin/bash
GPP = /usr/bin/g++
#ARGS = -DDEBUG -Wall -g
ARGS = -Wall -g
OPT = 

all: precomp
	$(GPP) $(OPT) build/*.o -o fish-simulator

precomp:
	if [ -d build ]; then echo ""; else mkdir build; fi
	cd build && $(GPP) $(ARGS) -c ../*.cpp
	cd ..

.PHONY : clean
clean:
	rm fish-simulator
	rm -r build

