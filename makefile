hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/ArrayList.o -c ./src/ArrayList.cpp
	g++ -I ./include -o ./bin/Test ./lib/ArrayList.o ./src/Test.cpp
	
calistir:
	./bin/Test