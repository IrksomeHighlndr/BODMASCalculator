OBJS	= main.o parser.o operations.o token.o
OUT	= output
CC	 = g++
FLAGS	 = -g -c -Wall
LIBDIRS	 = src/headers

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++17 -I $(LIBDIRS)

parser.o: src/parser.cpp
	$(CC) $(FLAGS) src/parser.cpp -std=c++17 -I $(LIBDIRS)

operations.o: src/operations.cpp
	$(CC) $(FLAGS) src/operations.cpp -std=c++17 -I $(LIBDIRS)

token.o: src/token.cpp
	$(CC) $(FLAGS) src/token.cpp -std=c++17 -I $(LIBDIRS)


# clean house
clean:
	rm -f $(OBJS) $(OUT)