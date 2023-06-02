CC=ARMg++
FLAGS=-Wall
DEFS = ./include
CPPGPIO = ./include/cppgpio
LIB = ./lib
SRC = ./src
BIN = ./bin

all:  $(LIB)/buttons.o $(LIB)/gpio.o $(LIB)/output.o $(LIB)/tools.o $(LIB)/Moteur.o 
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/TU_moteur.cpp $(LIB)/gpio.o $(LIB)/Moteur.o $(LIB)/tools.o $(LIB)/output.o  -o $(BIN)/TU_moteur -std=c++14 -lpthread  
	@echo "Compilation success"


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

$(LIB)/Moteur.o : $(SRC)/Moteur.cpp $(DEFS)/Moteur.h
	@echo "Compilation classes de Moteur"
	$(CC) -c $(SRC)/Moteur.cpp -std=c++14 -lpthread  -o $@ $(FLAGS) 