CXX := g++
CXXFLAGS := -std=c++20 -Iinclude -Wall -Wextra

SRC := src/calculator.cpp
MAIN := src/main.cpp

TARGETDIR := compile
LIBDIR := lib
LIB := $(LIBDIR)/libcalculator.a
TARGET := $(TARGETDIR)/calculator_app

.PHONY: all clean

all: $(LIB) $(TARGET)

$(LIB): $(SRC)
	mkdir -p $(TARGETDIR)
	mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o calculator.o
	ar rcs $(LIB) calculator.o
	rm calculator.o

$(TARGET): $(MAIN) $(LIB)
	$(CXX) $(CXXFLAGS) $(MAIN) -L$(LIBDIR) -lcalculator -lfmt -o $(TARGET)

clean:
	rm -rf $(LIBDIR) $(TARGETDIR)
