# Warsaw University of Technology
# The Faculty of Electronics and Information Technology
#
# Object-Oriented Programming Lab 2 - Abstract Buffer
#
# Makefile
#
# @author Michal Swietochowski 

# compiler
CXX=g++

# dirs
BINDIR=bin
BUILDDIR=build
SRCDIR=src

# target
TARGET=$(BINDIR)/buf

# settings
CXXFLAGS=-g
SOURCES=$(SRCDIR)/main.cpp $(SRCDIR)/BuffersTest.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -rf bin/*

.PHONY: all clean
