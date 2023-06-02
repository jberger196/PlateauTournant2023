CC=ARMg++
FLAGS=-Wall
DEFS = ./include
CPPGPIO = ./include/cppgpio
LIB = ./lib
SRC = ./src
BIN = ./bin

all: $(LIB)/SignalCube.o $(LIB)/PlateauTournant.o $(LIB)/buttons.o $(LIB)/gpio.o $(LIB)/output.o $(LIB)/tools.o 
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/TesteurSignalMoteurV5.cpp $(LIB)/SignalCube.o $(LIB)/PlateauTournant.o $(LIB)/buttons.o $(LIB)/gpio.o $(LIB)/tools.o  -o $(BIN)/tuSignalCube -std=c++14 -lpthread  
	@echo "Compilation success"
	$(CC) $(FLAGS) $(SRC)/simulateurMoteurCube.cpp $(LIB)/output.o  $(LIB)/gpio.o $(LIB)/tools.o  -o $(BIN)/simulateurMoteurCube -std=c++14 -lpthread  
	@echo "Compilation success"	

$(LIB)/SignalCube.o : $(SRC)/SignalCube.cpp $(DEFS)/SignalCube.hpp 
	@echo "Compilation classes de SignalCube"
	$(CC) -c $(SRC)/SignalCube.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 	

$(LIB)/PlateauTournant.o : $(SRC)/PlateauTournant.cpp $(DEFS)/PlateauTournant.h
	@echo "Compilation classe PlateauTournant"
	$(CC) -c $(SRC)/PlateauTournant.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 

$(LIB)/buttons.o : $(SRC)/buttons.cpp $(CPPGPIO)/buttons.hpp 
	@echo "Compilation classes de buttons"
	$(CC) -c $(SRC)/buttons.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 	

$(LIB)/tools.o : $(SRC)/tools.cpp $(DEFS)/tools.hpp 
	@echo "Compilation classes de tools"
	$(CC) -c $(SRC)/tools.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 	

$(LIB)/gpio.o : $(SRC)/gpio.cpp $(CPPGPIO)/gpio.hpp 
	@echo "Compilation classes de gpio"
	$(CC) -c $(SRC)/gpio.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 

$(LIB)/output.o : $(SRC)/output.cpp $(CPPGPIO)/output.hpp 
	@echo "Compilation classes de output"
	$(CC) -c $(SRC)/output.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 
