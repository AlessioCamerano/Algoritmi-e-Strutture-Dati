package graph;

import java.util.Collection;

/**
 * Interface representing a generic graph structure.
 * 
 * @param <V> the type of the nodes (vertices) in the graph
 * @param <L> the type of the edge labels in the graph
 */
public interface AbstractGraph<V, L> {

    /**
     * Checks if the graph is directed.
     * 
     * @return {@code true} if the graph is directed; {@code false} otherwise
     */
    public boolean isDirected();

    /**
     * Checks if the graph is labelled.
     * 
     * @return {@code true} if the graph has labelled edges; {@code false} otherwise
     */
    public boolean isLabelled();

    /**
     * Adds a node to the graph.
     * 
     * @param a the node to add
     * @return {@code true} if the node was successfully added; {@code false} if the node already exists
     */
    public boolean addNode(V a);

    /**
     * Adds an edge between two nodes with an optional label.
     * 
     * @param a the starting node of the edge
     * @param b the ending node of the edge
     * @param l the label of the edge (can be {@code null} for unlabelled graphs)
     * @return {@code true} if the edge was successfully added; {@code false} if the edge already exists or the nodes do not exist
     */
    public boolean addEdge(V a, V b, L l);

    /**
     * Checks if a specific node is present in the graph.
     * 
     * @param a the node to check
     * @return {@code true} if the node exists in the graph; {@code false} otherwise
     */
    public boolean containsNode(V a);

    /**
     * Checks if an edge exists between two nodes.
     * 
     * @param a the starting node of the edge
     * @param b the ending node of the edge
     * @return {@code true} if the edge exists; {@code false} otherwise
     */
    public boolean containsEdge(V a, V b);

    /**
     * Removes a node and all its associated edges from the graph.
     * 
     * @param a the node to remove
     * @return {@code true} if the node was successfully removed; {@code false} if the node does not exist
     */
    public boolean removeNode(V a);

    /**
     * Removes an edge between two nodes.
     * 
     * @param a the starting node of the edge
     * @param b the ending node of the edge
     * @return {@code true} if the edge was successfully removed; {@code false} if the edge does not exist
     */
    public boolean removeEdge(V a, V b);

    /**
     * Returns the total number of nodes in the graph.
     * 
     * @return the number of nodes
     */
    public int numNodes();

    /**
     * Returns the total number of edges in the graph.
     * 
     * @return the number of edges
     */
    public int numEdges();

    /**
     * Retrieves all nodes in the graph.
     * 
     * @return a collection containing all nodes
     */
    public Collection<V> getNodes();

    /**
     * Retrieves all edges in the graph.
     * 
     * @return a collection containing all edges as objects implementing {@link AbstractEdge}
     */
    public Collection<? extends AbstractEdge<V, L>> getEdges();

    /**
     * Retrieves all adjacent nodes (neighbors) for a given node.
     * 
     * @param a the node whose neighbors are to be retrieved
     * @return a collection containing all neighbors of the node
     */
    public Collection<V> getNeighbours(V a);

    /**
     * Retrieves the label of the edge between two nodes.
     * 
     * @param a the starting node of the edge
     * @param b the ending node of the edge
     * @return the label of the edge, or {@code null} if the edge does not exist
     */
    public L getLabel(V a, V b);
}
