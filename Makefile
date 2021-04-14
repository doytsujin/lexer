exec = lexer
sources = $(wildcard src/*.cpp)
objects = $(sources:.c=.o)
flags = -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor -Werror -std=c++17


$(exec): $(objects)
	g++ $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	g++ -c $(flags) $< -o $@

test:
	gcc $(wildcard test/*.c) $(flags) $< -o $@

install:
	make
	cp ./hello.out /usr/local/bin/hello

clean:
	-rm lexer