
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc


__START__: ${OBJ} ${OBJ}/main.o ${OBJ}/Wektor.o ${OBJ}/MacierzKw.o ${OBJ}/UkladRownanL.o 
	g++ -o ${TRGDIR}/uklad_rownan ${OBJ}/main.o ${OBJ}/Wektor.o ${OBJ}/MacierzKw.o ${OBJ}/UkladRownanL.o

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Wektor.hh inc/MacierzKw.hh inc/UkladRownanL.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ -c ${FLAGS} -o ${OBJ}/Wektor.o src/Wektor.cpp

${OBJ}/MacierzKw.o: src/MacierzKw.cpp inc/MacierzKw.hh  inc/Wektor.hh
	g++ -c ${FLAGS} -o ${OBJ}/MacierzKw.o src/MacierzKw.cpp

${OBJ}/UkladRownanL.o: src/UkladRownanL.cpp inc/MacierzKw.hh  inc/Wektor.hh inc/UkladRownanL.hh
	g++ -c ${FLAGS} -o ${OBJ}/UkladRownanL.o src/UkladRownanL.cpp


clean:
	rm -f ${TRGDIR}/uklad_rownan ${OBJ}/*
