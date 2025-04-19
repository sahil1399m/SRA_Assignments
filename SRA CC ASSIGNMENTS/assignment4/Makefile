# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -O2 `pkg-config --cflags opencv4`

# Libraries
LIBS = `pkg-config --libs opencv4`

# Target executable
TARGET = bitwise_operations

# Source files
SRC = bitwise_operations.cpp

# Rule to build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Rule to clean generated files
clean:
	rm -f $(TARGET)