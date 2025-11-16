SRC = src/board.cpp src/eval.cpp src/movegen.cpp src/search.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)

pain: $(OBJ)
	g++ $(OBJ) -o pain

%.o: %.cpp
	g++ -std=c++20 -Iinclude -c $< -o $@

all : pain

clean :
	rm -f $(OBJ) pain
