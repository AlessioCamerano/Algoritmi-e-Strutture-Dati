package priorityqueue;
/**
 * Interface for a priority queue data structure.
 * @param <E> The generic type of elements in the queue.
 */
public interface AbstractQueue<E> {

    /**
     * Checks if the queue is empty.
     * @return true if the queue is empty.
     */
    boolean empty();

    /**
     * Adds an element to the priority queue.
     * @param e The element to be added.
     * @return success or not (true or false).
     */
    boolean push(E e);

    /**
     * Checks if an element is present in the queue.
     * @param e The element to check for.
     * @return true if the element is present.
     */
    boolean contains(E e);

    /**
     * Returns the element with the highest priority without removing it.
     * @return The element with the highest priority.
     */
    E top();

    /**
     * Removes the element with the highest priority from the queue.
     */
    void pop();

    /**
     * Removes a specific element from the queue, if present.
     * @param e The element to be removed.
     * @return true if the element was removed successfully.
     */
    boolean remove(E e);
}
