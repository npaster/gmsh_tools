CXX = g++ -std=c++11
DEBUG_FLAG = -DDEBUG -Wall -Wextra -pedantic -Weffc++ -Wshadow -Wundef
RELEASE = -O2

PROG = gmsh_tools
SRC = gmshElement.cpp gmshMesh.cpp gmshData.cpp main.cc

debug :
			$(CXX) $(DEBUG_FLAG) $(SRC) -o $(PROG)

release :
			$(CXX) $(RELEASE) $(SRC) -o $(PROG)

clean :
			@rm *.o $(PROG)
			@echo "On a fait du nettoyage"
