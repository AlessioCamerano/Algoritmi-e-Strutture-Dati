package priorityqueue;

import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        // Create a PriorityQueue with a comparator for Integer (min-heap)
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(Comparator.naturalOrder());

        System.out.println("Adding elements to the priority queue...");
        queue.push(5);
        queue.push(3);
        queue.push(8);
        queue.push(1);

        System.out.println("Is the queue empty? " + queue.empty()); // Expected: false

        System.out.println("The top element is: " + queue.top()); // Expected: 1 (smallest element)

        System.out.println("Removing the top element...");
        queue.pop(); // Removes 1, the smallest element

        System.out.println("The new top element is: " + queue.top()); // Expected: 3

        System.out.println("Does the queue contain 5? " + queue.contains(5)); // Expected: true
        System.out.println("Does the queue contain 10? " + queue.contains(10)); // Expected: false

        System.out.println("Removing specific element (5)...");
        queue.remove(5);

        System.out.println("Does the queue still contain 5? " + queue.contains(5)); // Expected: false

        System.out.println("Final queue state:");
        while (!queue.empty()) {
            System.out.println(queue.top()); // Print each element starting from the smallest
            queue.pop();
        }

        System.out.println("Is the queue empty now? " + queue.empty()); // Expected: true
    }
}
