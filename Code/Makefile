XX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = bb7k.o building.o academic.o computer.o gameboard.o gym.o human.o nonproperty.o player.o residence.o RUTRCup.o square.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = bb7k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm *.o *.d
