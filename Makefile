CXX = g++
CXXFLAGS = -std=c++14
EXEC = straights
OBJECTS = straight.o cards.o deck.o table.o strategy.o human.o player.o computer.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
