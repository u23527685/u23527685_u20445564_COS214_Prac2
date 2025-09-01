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

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Coverage-enabled build (reuses main object files with coverage flags)
coverage: clean-coverage $(TARGET)_coverage

$(TARGET)_coverage: CXXFLAGS += $(COVERAGE_FLAGS)
$(TARGET)_coverage: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET)_coverage $(OBJECTS) -lgcov

# Run coverage analysis
test-coverage: coverage
	@echo "Running program with coverage analysis..."
	./$(TARGET)_coverage
	@echo "Generating coverage report..."
	@if ls *.gcno 1> /dev/null 2>&1; then \
		gcov -b -c *.gcno; \
	else \
		echo "No .gcno files found. Make sure the program was built with coverage flags."; \
	fi
	@echo "Coverage files (.gcov) generated!"
	@echo "To view coverage summary, check the .gcov files or use:"
	@echo "  make coverage-html"

# Generate HTML coverage report (requires lcov)
coverage-html: test-coverage
	@echo "Generating HTML coverage report..."
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_html
	@echo "HTML coverage report generated in coverage_html/ directory"
	@echo "Open coverage_html/index.html in your browser to view the report"

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET)_coverage
	rm -f *.gcov *.gcda *.cov.o *.gcno coverage.info
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
