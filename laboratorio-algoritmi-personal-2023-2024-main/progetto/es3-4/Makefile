# Variables for paths and tools
JUNIT = /mnt/c/users/camer/laboratorio-algoritmi-personal-2023-2024/lib/junit-platform-console-standalone-1.11.3.jar
SRC = ./src
BIN = ./bin
GRAPH_SRC = $(SRC)/graph
PQ_SRC = $(SRC)/priorityqueue

# List of source files
GRAPH_SOURCES = $(GRAPH_SRC)/Graph.java $(GRAPH_SRC)/GraphTest.java $(GRAPH_SRC)/Prim.java $(GRAPH_SRC)/Edge.java $(GRAPH_SRC)/AbstractGraph.java $(GRAPH_SRC)/AbstractEdge.java
PQ_SOURCES = $(PQ_SRC)/AbstractQueue.java $(PQ_SRC)/PriorityQueue.java $(PQ_SRC)/PriorityTest.java

# Compiler and execution tools
JAVAC = javac
JAVA = java
JFLAGS = -cp $(BIN):$(JUNIT)  # Classpath for compilation

# Default target
all: compile

# Compile all .java files for graph and priorityqueue
compile:
	$(JAVAC) -d $(BIN) -cp $(JUNIT) $(GRAPH_SOURCES) $(PQ_SOURCES)

# Run the main program from Prim
run: $(BIN)/graph/Prim.class
	$(JAVA) $(JFLAGS) graph.Prim ./data/italian_dist_graph.csv

# Run the tests using JUnit
test: compile
	$(JAVA) -jar $(JUNIT) --class-path $(BIN) --scan-class-path

# Clean up compiled files
clean:
	rm -rf $(BIN)/*.class $(BIN)/graph/*.class $(BIN)/priorityqueue/*.class
