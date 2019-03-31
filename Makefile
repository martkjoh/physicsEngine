EXECUTABLE = PhysicsEngine

CPP = g++
LINK = $(CPP)

SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
CXXFLAGS = `fltk-config --ldflags`


%.o: %.cpp
	$(CPP) -c $<

$(EXECUTABLE): $(OBJECTS)
	$(LINK) $(OBJECTS) -o $(EXECUTABLE) $(CXXFLAGS)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: .clean
clean:
	$(RM) $(EXECUTABLE)
	$(RM) $(OBJECTS)
