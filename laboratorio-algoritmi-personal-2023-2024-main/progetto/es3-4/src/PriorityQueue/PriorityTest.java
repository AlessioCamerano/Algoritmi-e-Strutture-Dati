package priorityqueue;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Comparator;

public class PriorityTest{
    private PriorityQueue<Integer> queue;

    //Creating a new queue for each test call.
    @BeforeEach
    public void Start(){
        queue = new PriorityQueue<Integer>(Comparator.naturalOrder());
    }

    @Test
    public void TestPushTop(){
        queue.push(5);
        queue.push(2);
        queue.push(15);

        //top should be 2.
        assertEquals(2, queue.top());
    }

    @Test 
    public void testPop(){
        queue.push(5);
        queue.push(2);
        queue.push(9);
        queue.push(1);

        //should remove the smallest element, which is 1.
        queue.pop();

        //should return true.
        assertEquals(2, queue.top());
    }

    @Test
    public void testEmpty(){
        //testing boolean results of empty().
        assertTrue(queue.empty());

        queue.push(10);
        assertFalse(queue.empty());

        queue.pop();
        assertTrue(queue.empty());
    }

    @Test
    public void testContains(){
        //testing boolean results of contains().
        queue.push(5);
        queue.push(3);

        assertTrue(queue.contains(5));
        assertFalse(queue.contains(2));
    }

    @Test
    public void  testRemove(){
        //testing boolean results of remove();
        queue.push(14);
        queue.push(5);
        queue.push(8);

        assertTrue(queue.remove(5));
        assertFalse(queue.contains(5));
        assertFalse(queue.remove(5));   //should give false cause we just removed it.
    }
}