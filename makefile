OPT = -g -Wall
OBJ = main.o Control.o Record.o ReportGenerator.o FarmRegBreakdown.o AnimalCanBreakdown.o HorsesPoniesSubreg2016.o View.o

fp:	${OBJ}
	g++ $(OPT) -o fp ${OBJ}

main.o:	main.cc
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

FarmRegBreakdown.o: FarmRegBreakdown.cc FarmRegBreakdown.h
	g++ -c FarmRegBreakdown.cc

AnimalCanBreakdown.o: AnimalCanBreakdown.cc AnimalCanBreakdown.h
	g++ -c AnimalCanBreakdown.cc

HorsesPoniesSubreg2016 .o: HorsesPoniesSubreg2016 .cc HorsesPoniesSubreg2016 .h
	g++ -c HorsesPoniesSubreg2016 .cc

View.o: View.cc
	g++ -c View.cc

valgrind: fp
	valgrind --leak-check=full ./fp

clean:
	rm -f Report*.txt *.o fp