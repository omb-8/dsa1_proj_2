# Compiler and flags
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare

# Source files
SRC = node.cpp stack.cpp operand.cpp arithmetic-expression.cpp big-integer-arithmetic.cpp expression-reader.cpp main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Test files
TESTS = test/test-1-node test/test-2-stack test/test-3-operand test/test-4-arithmetic-expression \
        test/test-5a-big-integer-arithmetic test/test-5b-big-integer-arithmetic test/test-6-expression-reader

TEST_SRC = test/test-1-node.cpp test/test-2-stack.cpp test/test-3-operand.cpp test/test-4-arithmetic-expression.cpp \
           test/test-5a-big-integer-arithmetic.cpp test/test-5b-big-integer-arithmetic.cpp test/test-6-expression-reader.cpp

TEST_OBJ = $(TEST_SRC:.cpp=.o)

CATCH_OBJ = test/catch/catch.o

# Default target
all: $(OBJ) $(TEST_OBJ) $(TESTS)

# Compile main objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Catch2
test/catch/catch.o: test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test 1: Node
test/test-1-node: test/test-1-node.o node.o stack.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test 2: Stack
test/test-2-stack: test/test-2-stack.o node.o stack.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test 3: Operand
test/test-3-operand: test/test-3-operand.o operand.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test 4: ArithmeticExpression
test/test-4-arithmetic-expression: test/test-4-arithmetic-expression.o operand.o arithmetic-expression.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test 5a: BigIntegerArithmetic
test/test-5a-big-integer-arithmetic: test/test-5a-big-integer-arithmetic.o node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test 5b: BigIntegerArithmetic
test/test-5b-big-integer-arithmetic: test/test-5b-big-integer-arithmetic.o node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test 6: ExpressionReader
test/test-6-expression-reader: test/test-6-expression-reader.o node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o expression-reader.o $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Main program
main: main.o node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o expression-reader.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean everything
clean:
	rm -f *.o main
	rm -f test/*.o $(TESTS)
	rm -f test/catch/*.o
