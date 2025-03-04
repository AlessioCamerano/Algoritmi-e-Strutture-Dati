package graph;

import java.util.*;

public class Graph<V, L> implements AbstractGraph<V, L> {
    
    private final boolean directed; //Whether the graph is directed.
    private final boolean labelled; //Whether the graph is labelled.
    private final Map<V, List<Edge<V, L>>> edgeList; //edgeList representation
    private int edgeCount; //total number of edges in the graph.

    /**
     * Create an empty graph.
     * 
     * @param directed whether the graph is directed.
     * @param labelled whether the graph is labelled.
     */
    public Graph(boolean directed, boolean labelled){
        this.directed= directed;
        this.labelled= labelled;
        this.edgeList= new HashMap<>();
        this.edgeCount= 0;
    }

    @Override
    public boolean isDirected(){
        return directed;
    }

    @Override
    public boolean isLabelled(){
        return labelled;
    }

    @Override
    public boolean addNode(V a){
        if (edgeList.containsKey(a)){
            return false;
        }

        edgeList.put(a, new ArrayList<>());
        return true;
    }

    @Override
    public boolean addEdge(V a, V b, L l){
        if(!edgeList.containsKey(a) || !edgeList.containsKey(b)){
            return false;
        }

        boolean added= edgeList.get(a).add(new Edge<>(a, b, labelled ? l : null));

        //for undirected graphs
        if (!directed){
            added= edgeList.get(b).add(new Edge<>(b, a, labelled ? l : null));
        }

        if(added) edgeCount++;
        return added;
    }

    @Override
    public boolean containsNode(V a){
        return edgeList.containsKey(a);
    }

    @Override
    public boolean containsEdge(V a, V b){
        if(!edgeList.containsKey(a)) return false;

        for (Edge<V, L> local : edgeList.get(a)){
            if(local.getEnd().equals(b)){
                return true;
            }
        }
        return false;
    }

    @Override 
    public boolean removeNode(V a){
        if(!edgeList.containsKey(a)){
            return false;
        }

        //remove all the edges pointing to a
        for (V local : edgeList.keySet()){
            //remove the edge in both directions for undirected graphs
            removeEdge(local, a);
        }
        
        //remove the node itself
        edgeList.remove(a);

        return true;
    }

    @Override 
    public boolean removeEdge(V a, V b){
        if(!edgeList.containsKey(a)){
            return false;
        }

        boolean removed= edgeList.get(a).removeIf(edge -> edge.getEnd().equals(b));

        //for undirected graphs
        if(!directed && edgeList.containsKey(b)){
            removed= edgeList.get(b).removeIf(edge -> edge.getEnd().equals(a));
        }

        if(removed) edgeCount--;
        return removed;
    }

    @Override
    public int numNodes(){
        return edgeList.size();
    }

    @Override
    public int numEdges(){
        return edgeCount;
    }

    @Override
    public Collection<V> getNodes(){
        return edgeList.keySet();
    }

    @Override
    public Collection<V> getNeighbours(V a){
        List<V> neighbours= new ArrayList<>();
        if (edgeList.containsKey(a)){
            for (Edge<V, L> local :edgeList.get(a)){
                neighbours.add(local.getEnd());
            }
        }
        return neighbours;
    }

    @Override 
    public Collection<Edge<V, L>> getEdges(){
        List<Edge<V, L>> edges= new ArrayList<>();
        for (List<Edge<V, L>> local : edgeList.values()){
            edges.addAll(local);
        }
        return edges;
    }

    @Override
    public L getLabel(V a, V b){
        if (!edgeList.containsKey(a)) return null;
        for (Edge<V, L> local : edgeList.get(a)){
            if (local.getEnd().equals(b)){
                return local.getLabel();
            }
        }
        return null;
    }
}


