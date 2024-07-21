# Makefile

# Load environment variables from .env file
include .env

SRC_DIR = okx_trader
BUILD_DIR = build

# Compiler and flags
CXX = g++
CXXFLAGS =  -Wall -Wextra -Werror

# Use wildcard to find all .cpp files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Automatically create a list of .o files corresponding to the .cpp files
OBJECTS = $(SOURCES:$(BUILD_DIR)/%.o=$(SRC_DIR)/%.cpp)

EXECUTABLE = goQuant_trader

# Targets
help:
	@echo "Makefile targets:"
	@echo "  all       - Build the executable $(EXECUTABLE)"
	@echo "  clean     - Remove the executable"
	@echo "  re        - Rebuild the executable (clean and then build)"
	@echo "  help      - Show this help message"

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) -lcurl -lssl -lcrypto

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp headers.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE)

re: clean all

