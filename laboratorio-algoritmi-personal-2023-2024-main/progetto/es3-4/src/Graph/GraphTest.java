package graph;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Collection;
class GraphTest {

    private Graph<String, Integer> graph;

     //Creating a new queue for each test call.
    @BeforeEach
    public void Start(){
        graph= new Graph<>(true, true);
    }

    @Test
    void testAddNode(){
        assertTrue(graph.addNode("a"));
        assertTrue(graph.addNode("b"));
        assertFalse(graph.addNode("a")); //duplicate should return false
        assertEquals(2, graph.numNodes());
    }

    @Test
    void testAddEdge(){
        graph.addNode("a");
        graph.addNode("b");

        assertTrue(graph.addEdge("a", "b", 10));
        assertFalse(graph.addEdge("a", "c", 20)); //c doesn't exist
        assertEquals(1, graph.numEdges());
    }

    @Test
    void testContainsNode(){
        graph.addNode("a");
        assertTrue(graph.containsNode("a"));
        assertFalse(graph.containsNode("c")); //should return false (c is not in)
    }

    @Test
    void testContainsEdge(){
        graph.addNode("a");
        graph.addNode("b");
        graph.addEdge("a", "b", 10);
        assertTrue(graph.containsEdge("a", "b"));
        assertFalse(graph.containsEdge("a", "c")); //edge doesn't exist
    }

    @Test
    void testRemoveNode(){
        graph.addNode("a");
        assertTrue(graph.removeNode("a"));
        assertFalse(graph.containsNode("a")); //removed before
        assertFalse(graph.removeNode("c")); //c doesn't exist
    }

    @Test
    void testRemoveEdge(){
        graph.addNode("a");
        graph.addNode("b");
        graph.addEdge("a", "b", 10);
        assertTrue(graph.removeEdge("a", "b"));
        assertFalse(graph.containsEdge("a", "b")); //removed before
        assertFalse(graph.removeEdge("a", "c")); //this edge doesn't exist
    }

    @Test
    void testGetNodes(){
        graph.addNode("a");
        graph.addNode("b");

        Collection<String> nodes= graph.getNodes();
        assertEquals(2, nodes.size());
        assertTrue(nodes.contains("a"));
        assertTrue(nodes.contains("b"));
        assertFalse(nodes.contains("c")); //c doesn't exist
    }

    @Test 
    void testGetEdges(){
        graph.addNode("a");
        graph.addNode("b");
        graph.addEdge("a", "b", 10);

        Collection<Edge<String, Integer>> edge= graph.getEdges();
        assertEquals(1, edge.size());
        assertTrue(edge.contains(new Edge<>("a", "b", 10)));
        assertFalse(edge.contains(new Edge<>("a", "c", 20))); //doesn't exist
    }

    @Test
    void testGetNeighbours() {
        graph.addNode("a");
        graph.addNode("b");
        graph.addNode("c");

        graph.addEdge("a", "b", 10);
        graph.addEdge("a", "c", 20);

        Collection<String> neighbours = graph.getNeighbours("a");
        assertEquals(2, neighbours.size());
        assertTrue(neighbours.contains("b"));
        assertTrue(neighbours.contains("c"));
        assertFalse(neighbours.contains("e")); // e doesn't exist
    }

    @Test
    void testGetLabel() {
        graph.addNode("a");
        graph.addNode("b");

        graph.addEdge("a", "b", 10);
        assertEquals(10, graph.getLabel("a", "b"));
        assertNull(graph.getLabel("b", "a")); // Directed graph
    }

    @Test
    void testUndirectedGraph() {
        Graph<String, Integer> graph = new Graph<>(false, true); // Undirected graph
        graph.addNode("a");
        graph.addNode("b");

        graph.addEdge("a", "b", 10);
        assertTrue(graph.containsEdge("a", "b"));
        assertTrue(graph.containsEdge("b", "a"));
        assertEquals(1, graph.numEdges()); // Count undirected edges only once
    }

    @Test
    void testUnlabelledGraph() {
        Graph<String, Integer> graph = new Graph<>(true, false); // Unlabelled graph
        graph.addNode("a");
        graph.addNode("b");

        graph.addEdge("a", "b", null);
        assertTrue(graph.containsEdge("a", "b"));
        assertNull(graph.getLabel("a", "b")); // Labels should always be null
    }

}
