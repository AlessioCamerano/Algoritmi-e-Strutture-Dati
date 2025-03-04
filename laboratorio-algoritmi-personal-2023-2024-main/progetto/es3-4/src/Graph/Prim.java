package graph;

import java.io.*;
import java.util.*;

import priorityqueue.PriorityQueue;

public class Prim{
    /**
     * Computes the MST using the Prim's Algorithm
     * @param graph the input graph
     * @return a collection of edges forming the minimum spanning forest
     */
    public static <V, L extends Number & Comparable<L>> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        //queue of all neighboring edges
        PriorityQueue<Edge<V,L>> queue = new PriorityQueue<>(Comparator.comparing(edge -> edge.getLabel()));

         //list representing the MST
         ArrayList<Edge<V,L>> minimumTree = new ArrayList<>();

         //set of all visited nodes
         HashSet<V> visitedNodes = new HashSet<>();

         while(visitedNodes.size() < graph.numNodes()){
            V root = null;
            //gets a node from the graph that isn't contained in visitedNodes
            for(V node : graph.getNodes()){
                if(!visitedNodes.contains(node)){
                    root = node;
                    break;
                }
            }
            visitedNodes.add(root);
    
            //adds all neighbors of the root to queue
            for(V end : graph.getNeighbours(root)){
                queue.push(new Edge<>(root , end , graph.getLabel(root , end)));
            }
    
            //visits all reachable nodes
            while(!queue.empty()){
                Edge<V,L> min = queue.top();
                queue.pop();
                V node = min.getEnd();
                if(visitedNodes.contains(node))
                    continue;
                visitedNodes.add(node);
                minimumTree.add(min);
                for(V end : graph.getNeighbours(node)){
                    queue.push(new Edge<>(node , end , graph.getLabel(node , end)));
                }
            }
        }
        System.out.println("Done.");
        return minimumTree;
    }

    //Read the graph data from the CSV file located at the path specified in args[1]
    //Compute the minimum spanning forest using the minimumSpanningForest method
    public static void main(String[] args) throws IOException{
        if(args.length != 1){
            System.err.println("Invalid number of arguments\nUsage: ./Prim [dataset]");
            System.exit(1);
        }

        File dataset = new File(args[0]);
        if(!dataset.exists()){
            throw new FileNotFoundException("The path of the dataset is not valid");
        }
        Graph<String , Double> graph = new Graph<>(false , true);

        BufferedReader reader = new BufferedReader(new FileReader(dataset));

        //loads the csv into the graph
        String line;
        while((line = reader.readLine()) != null){
            StringTokenizer tokenizer = new StringTokenizer(line , ",\n");

            String tok1 = tokenizer.nextToken();
            String tok2 = tokenizer.nextToken();
            Double tok3 = Double.valueOf(tokenizer.nextToken());

            graph.addNode(tok1);
            graph.addNode(tok2);
            graph.addEdge(tok1 , tok2 , tok3);
        }
        reader.close();

        ArrayList<AbstractEdge<String,Double>> minimumForest = new ArrayList<>(minimumSpanningForest(graph));
        
        double totLabel= 0;
        
        // Iterate through each edge in the MST and sum up their weights
        for(AbstractEdge<String, Double> edge :  minimumForest){
            totLabel += edge.getLabel();
        }
        
        System.out.println("Total Nodes: " + graph.numNodes());
        System.out.println("Total Edges: " + minimumForest.size());
        System.out.println("Total Weight: " + totLabel / 1000 + " km");
    } 
}