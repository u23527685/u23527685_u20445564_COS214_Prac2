# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage --coverage

# Target executable
TARGET = pizza

# Source files
SOURCES = TestingMain.cpp \
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
          ExtraCheese.cpp \
          Order.cpp \
          OrderState.cpp \
          Orderring.cpp \
          CheckOut.cpp \
          Paid.cpp \
          Menus.cpp \
          PizzaMenu.cpp \
          SpecialsMenu.cpp \
          Customer.cpp \
          Website.cpp \
          DiscountStrategy.cpp \
          RegularPrice.cpp \
          BulkDiscount.cpp \
          FamilyDiscount.cpp

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
          ExtraCheese.h \
          Order.h \
          OrderState.h \
          Orderring.h \
          CheckOut.h \
          Paid.h \
          Observer.h \
          Menus.h \
          PizzaMenu.h \
          SpecialsMenu.h \
          Customer.h \
          Website.h \
          DiscountStrategy.h \
          RegularPrice.h \
          BulkDiscount.h \
          FamilyDiscount.h

# Default target
all: $(TARGET)

# Coverage object files (with different extension)
# Coverage object files (with different extension)
COVERAGE_OBJECTS = $(SOURCES:.cpp=.cov.o)

# Coverage build rules - compile with coverage flags
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build coverage executable using coverage object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Coverage-enabled build
coverage: clean-coverage $(TARGET)_coverage

# Run tests with coverage analysis
test-coverage: coverage
	@echo "Running program with coverage analysis..."
	./$(TARGET)_coverage
	@echo "Coverage data collection complete!"

# Generate HTML coverage report (requires lcov)
coverage-html: test-coverage
	@echo "Generating HTML coverage report..."
	@mkdir -p coverage_html
	geninfo . --output-filename coverage.info --memory 0
	genhtml coverage.info --output-directory coverage_html --title "Pizza System Coverage"
	@echo "HTML coverage report generated in coverage_html/ directory"
	@echo "Open coverage_html/index.html in your browser to view the report"

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET)_coverage $(COVERAGE_OBJECTS)
	rm -f *.gcov *.gcda *.gcno coverage.info
	rm -rf coverage_html/

# Clean coverage files only
clean-coverage:
	rm -f $(TARGET)_coverage
	rm -f *.gcov *.gcda *.cov.o *.gcno coverage.info
	rm -rf coverage_html/

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