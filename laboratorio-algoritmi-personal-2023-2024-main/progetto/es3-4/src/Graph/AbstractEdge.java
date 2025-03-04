package graph;
/**
 * Interface representing a generic edge in a graph.
 *
 * @param <V> the type of the nodes (vertices) connected by the edge
 * @param <L> the type of the label associated with the edge
 */
public interface AbstractEdge<V, L> {

    /**
     * Retrieves the starting node (source) of the edge.
     *
     * @return the starting node of the edge
     */
    public V getStart();

    /**
     * Retrieves the ending node (destination) of the edge.
     *
     * @return the ending node of the edge
     */
    public V getEnd();

    /**
     * Retrieves the label associated with the edge.
     *
     * @return the label of the edge, or {@code null} if the graph is unlabelled
     */
    public L getLabel();
}
