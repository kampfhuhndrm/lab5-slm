#Compiler Settings
CXX = g++

CXXFLAGS = -std=c++17 -Wall -g -Isrc


EXEC = slm

# List of files
SOURCES = src/main.cpp \
          src/KGram.cpp \
          src/Generator.cpp


OBJECTS = $(SOURCES:.cpp=.o)


all: $(EXEC)


$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)


src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJECTS)