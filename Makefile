# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Executable name
TARGET = pizza_system

# Source files
SOURCES = Pizza.cpp \
          PizzaComponent.cpp \
          Topping.cpp \
          ToppingGroup.cpp \
          BasePizza.cpp \
          PizzaDecorator.cpp \
          ExtraCheese.cpp \
          StuffedCrust.cpp \
          Menus.cpp \
          PizzaMenu.cpp \
          SpecialsMenu.cpp \
          Customer.cpp \
          Website.cpp \
          TestingMain.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = Pizza.h \
          PizzaComponent.h \
          Topping.h \
          ToppingGroup.h \
          BasePizza.h \
          PizzaDecorator.h \
          ExtraCheese.h \
          StuffedCrust.h \
          Observer.h \
          Menus.h \
          PizzaMenu.h \
          SpecialsMenu.h \
          Customer.h \
          Website.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run with valgrind for memory leak detection
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TARGET)

# Run with valgrind (summary only)
valgrind-brief: $(TARGET)
	valgrind --leak-check=summary ./$(TARGET)

# Run with valgrind and save output to file
valgrind-log: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind_output.log ./$(TARGET)
	@echo "Valgrind output saved to valgrind_output.log"

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET) pizza_demo valgrind_output.log

# Clean and rebuild
rebuild: clean all

# Create a demo version (if you have DemoMain.cpp)
demo: $(filter-out TestingMain.o, $(OBJECTS)) DemoMain.o
	$(CXX) $(CXXFLAGS) -o pizza_demo $(filter-out TestingMain.o, $(OBJECTS)) DemoMain.o

# Run demo (if available)
run-demo: demo
	./pizza_demo

# Run demo with valgrind
valgrind-demo: demo
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./pizza_demo

# Install dependencies (if needed)
install:
	@echo "No external dependencies to install"

# Help target
help:
	@echo "Available targets:"
	@echo "  all           - Build the main program"
	@echo "  run           - Build and run the main program"
	@echo "  valgrind      - Build and run with full valgrind memory checking"
	@echo "  valgrind-brief- Build and run with valgrind summary"
	@echo "  valgrind-log  - Build and run with valgrind, save output to file"
	@echo "  demo          - Build the demo version (requires DemoMain.cpp)"
	@echo "  run-demo      - Build and run the demo version"
	@echo "  valgrind-demo - Build and run demo with valgrind"
	@echo "  clean         - Remove all generated files"
	@echo "  rebuild       - Clean and rebuild everything"
	@echo "  help          - Show this help message"

# Phony targets
.PHONY: all run valgrind valgrind-brief valgrind-log clean rebuild demo run-demo valgrind-demo install help