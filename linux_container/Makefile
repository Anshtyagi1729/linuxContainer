# Makefile

CXX = g++
CXXFLAGS = -Wall -g

# Define object files
OBJS = main.o NamespaceManager.o CgroupManager.o SeccompManager.o MountManager.o

# Target executable
TARGET = container

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lseccomp

# Rule for compiling object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)
