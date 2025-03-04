package graph;

import java.util.Objects;

public class Edge<V, L> implements AbstractEdge<V, L> {

    private final V start; //starting node of the edge
    private final V end; //final node of the edge
    private final L label; //label of the edge

    public Edge(V start, V end, L label){
        if (start == null || end == null){
            throw new IllegalArgumentException("start and end cannot be null.");
        }
        this.start= start;
        this.end= end;
        this.label= label;
    }

    @Override
    public V getStart(){
        return start;
    }

    @Override
    public V getEnd(){
        return end;
    }

    @Override 
    public L getLabel(){
        return label;
    }
    
    //***Utility***

    /**
     * Checks if this edge is equal to another object
     * 
     * @param obj the object to compare with this edge.
     * @return true if the edges are equal, false otherwise
     */
    @Override
    public boolean equals(Object obj){
        if (this == obj){
            return true; //if they are equal
        }

        if (obj == null || getClass() !=obj.getClass()){
            return false; //if they are different or obj is null
        }

        Edge<?, ?> edge= (Edge<?, ?>) obj; //creating edge for checking

        return Objects.equals(start, edge.start) &&
        Objects.equals(end, edge.end) &&
        Objects.equals(label, edge.label);
    }

    @Override
    public int hashCode() {
        return Objects.hash(start, end, label);
    }

    /**
     * Returns a string representation of the edge.
     *
     * @return a string in the format "start -> end [label]"
     */
    @Override
    public String toString() {
        return start + " -> " + end + (label != null ? " [" + label + "]" : "");
    }
}