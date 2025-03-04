package priorityqueue;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;

/**
 * Priority queue implementation using a heap.
 * @param <E> The generic type of elements in the queue.
 */
public class PriorityQueue<E> implements AbstractQueue<E> {
    
    private ArrayList<E> heap= new ArrayList<>(); //Stores the elements in the queue;
    private HashMap<E, Integer> Map= new HashMap<>(); //Map for a fast index research;
    private Comparator<E> comparator;   //Comparator to order elements;

    /**
     * Constructor to create an empty queue with a specified Comparator.
     * @param comparator Comparator used.
     */
    public PriorityQueue (Comparator<E> comparator){
        this.heap= new ArrayList<>();
        this.Map= new HashMap<>();
        this.comparator= comparator;
    }
    /**
     * Swap two elements.
     * @param i first element.
     * @param j second element.
     */
    private void swap(int i, int j){
        E temp= heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
        Map.put(heap.get(i), i);
        Map.put(heap.get(j), j);
    }

    /**
     * Restore the heap order upwards from a given index
     * @param i index used for restoring.
     */
    private void siftUp(int i){
        while (i > 0){
            int parent= (i - 1)/ 2;
            if(comparator.compare(heap.get(i), heap.get(parent)) >= 0) break;  //the element is in the correct position.
            swap(parent, i);
            i = parent;
        }
    }
    /**
     * Restore the heap order downwards from a given index.
     * @param i index used for restoring.
     */
    private void siftDown(int i){
        int left, right, smallest;
        while (i < heap.size()){
            left= 2 * i + 1;
            right= 2 * i + 2;
            smallest= i;

            if (left < heap.size() && comparator.compare(heap.get(left), heap.get(smallest)) < 0) {
                smallest = left;
            }
            if (right < heap.size() && comparator.compare(heap.get(right), heap.get(smallest)) < 0) {
                smallest = right;
            }
            if (smallest == i) break;   //heap order restored.
            swap(i, smallest);
            i = smallest;
        }
    }

    @Override
    public boolean empty(){
        return heap.isEmpty();
    }

    public boolean push(E e){
        // Check for null elements.
        if (e == null) {
            System.out.println("Cannot insert null elements.");
            return false;
        }
    
        try {
            // Add the element to the end of the heap
            heap.add(e);
            
            // Apply siftUp to maintain the heap property
            siftUp(heap.size() - 1);
            
            // Update the hashMap
            Map.put(e, heap.size() - 1);

            return true; // Successfully added the element
        } catch (Exception ex) {
            // Printing error
            System.out.println("Error during push");
            return false;
        }
    }

    public boolean contains(E e){
        return Map.containsKey(e);
    }

    public E top(){
        if(heap.isEmpty()) return null;
        return heap.get(0);
    }

    public void pop(){
        if(heap.isEmpty()) return;
       
        E removed= heap.get(0);
        E last= heap.remove(heap.size() - 1);

        //switching the element with highest prior with the last element
        if (!heap.isEmpty()){
            heap.set(0,last);
            Map.put(last, 0);
            siftDown(0); //restores the prior order
        }
        Map.remove(removed);
    }

    public boolean remove(E e){
        Integer index= Map.get(e);
        //element not found
        if(index == null) return false;
        
        int lastIndex= heap.size() - 1;
        E last= heap.get(lastIndex);

        //switching the index with the last element
        heap.set(index, last);
        Map.put(last, index);
        
        heap.remove(lastIndex);
        Map.remove(e);

        if(index != lastIndex){
            //restore the prio
            if(index > 0 && comparator.compare(last, heap.get((index - 1) / 2)) < 0){
                //must be moved up
                siftUp(index);
            } else {
                //must be moved down
                siftDown(index);
            }
        }
        return true;
    }

}
