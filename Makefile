OUTPUT = out
CPP_FILES = $(wildcard src/*.cpp)
O_FILES = $(patsubst src/%.cpp, obj/%.o, $(CPP_FILES))

$(OUTPUT): $(O_FILES)
	g++ $^ -o bin/$(OUTPUT)

obj/%.o: src/%.cpp
	g++ -c $< -o $@

run: $(OUTPUT)
	./bin/$(OUTPUT)

clean: 
	rm obj/* bin/*