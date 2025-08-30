# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra

# Target executable
TARGET = pizza

# Source files
SOURCES = main.cpp \
          PizzaComponent.cpp \
          BeefSausage.cpp \
          Cheese.cpp \
          Dough.cpp \
          Feta.cpp \
          GreenPeppers.cpp \
          Mushrooms.cpp \
          Olives.cpp \
          Onions.cpp \
          Pepperoni.cpp \
          Salami.cpp \
          TomatoSauce.cpp \
          ToppingGroup.cpp \
          Pizza.cpp \
          BasePizza.cpp \
          PizzaDecorator.cpp \
          StuffedCrust.cpp \
          ExtraCheese.cpp 

# Object files (automatically generated from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency checking)
HEADERS = PizzaComponent.h \
          BeefSausage.h \
          Cheese.h \
          Dough.h \
          Feta.h \
          GreenPeppers.h \
          Mushrooms.h \
          Olives.h \
          Onions.h \
          Pepperoni.h \
          Salami.h \
          TomatoSauce.h \
          ToppingGroup.h \
          Pizza.h \
          BasePizza.h \
          PizzaDecorator.h \
          StuffedCrust.h \
          ExtraCheese.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything from scratch
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug with valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Debug with gdb
debug: $(TARGET)
	gdb ./$(TARGET)
