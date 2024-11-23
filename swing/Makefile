# Makefile for compiling and running Window

# Main class
MAIN = Window

# Java compiler
JAVAC = javac

# Java execution command
JAVA = java

# Source files
SOURCES = $(wildcard *.java)

# Class files
CLASSES = $(SOURCES:.java=.class)

# Default target
all: $(CLASSES)

%.class: %.java
	$(JAVAC) $<

run: all
	$(JAVA) $(MAIN)

clean:
	rm -f *.class