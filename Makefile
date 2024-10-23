OUTPUT = out
CPP_FILES = $(wildcard src/*.cpp)
O_FILES = $(patsubst src/%.cpp, obj/%.o, $(CPP_FILES))

$(OUTPUT): $(O_FILES) | bin
	g++ $^ -o bin/$(OUTPUT)

obj/%.o: src/%.cpp | obj
	g++ -c $< -o $@

obj:
	mkdir -p obj
bin:
	mkdir -p bin

run: $(OUTPUT)
	./bin/$(OUTPUT)

clean: 
	rm obj/* bin/*