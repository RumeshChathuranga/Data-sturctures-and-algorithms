package Rumesh;

import java.util.NoSuchElementException;

public class LinkedList {

    private class Node {
        private int value;
        private Node next;

        public Node(int value) {
            this.value = value;
        }
    }

    private Node first;
    private Node last;
    private int size;

    private Boolean isEmpty(){
        return first==null;
    }

    public void addLast(int item){
        var node = new Node(item);
        if(isEmpty()) first = last=  node;
        else {
            last.next = node;
            last = node;
        }
        size++;
    }

    public void addFirst (int item){
        var node = new Node(item);
        if(isEmpty()) first= last = node;
        else {
            node.next = first;
            first = node;
        }
        size++;
    }

    public  int indexOf(int item){
        int index = 0;
        var current = first;
        while(current!= null){
            if(current.value == item) return index;
            index++;
            current = current.next;
        }
        return -1;
    }

    public Boolean contains(int item){
        return indexOf(item) != -1;
    }

    public void removeFirst() throws NoSuchElementException {
        if (isEmpty()) throw new NoSuchElementException();

        if(first == last) {
            first= last = null;
            size--;
            return;
        }

        var second = first.next;
        first.next = null;
        first = second;
        size--;

    }

    public void removeLast() {
        if(isEmpty() || first==last) {
            removeFirst();
            return;
        }

        var current = first;
        while(current.next != last){
            current = current.next;
        }
        current.next = null;
        current = last;
        size--;
    }

    public int size(){
        return size;
    }

    public int[] toArray() {
        int[] arr = new int[size];
        var current = first;
        int index = 0;
        while (current!=null){
            arr[index++] = current.value;
            current = current.next;
        }
        return arr;
    }

    public void reverse(){
        //10 -> 20 -> 30
        //10 <- 20 <- 30
        var previous = first;
        var current = first.next;
        while (current!= null){
            var next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }

        last = first;
        last.next = null;
        first =  previous;

    }
}
