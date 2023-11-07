CC=g++-10
KEY=-std=c++20
PATH_HEADER=./
EXE=exe
SRC=HW34.cpp
OBJ=$(SRC:.cpp=.o)

#run: all
#	./$(EXE)

all: $(SRC) $(EXE) clean
 
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ -I$(PATH_HEADER) $(KEY)

%.o : %.cpp
	$(CC) -c $< -o $@ $(KEY)

clean:
	rm -rf *.o *.a


