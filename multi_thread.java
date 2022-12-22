package com.company;
import java.util.*;

class RunnableDemo implements Runnable {
    private Thread t;
    private String threadName;
    private int[] array;

    RunnableDemo(String name, int[] array) {
        threadName = name;
        this.array = array;
        System.out.println("Creating " +  threadName );
    }

    public void run() {
        System.out.println("Running " +  threadName );
        try {
//            for(int i = 0; i < array.length; i++) {
////                System.out.println("Thread: " + threadName + ", " + i);
////                // Let the thread sleep for a while.
////                Thread.sleep(50);
////                sum += array[i];
//                Thread.sleep(50);
//            }
            Thread.sleep(50);
        } catch (InterruptedException e) {
            System.out.println("Thread " +  threadName + " interrupted.");
        }
//        System.out.println("Calculating Average: ");
//        average();
    }

    public void average(){
        int sum =0;
        for(int i=0; i < array.length; i++)
        {
            sum += array[i];
        }
        System.out.println("Average: " + sum/ array.length);
    }

    public void start () {
        System.out.println("Starting " +  threadName );
        if (t == null) {
            t = new Thread (this, threadName);
            t.start ();
        }
    }

    public void minimum () {
        int min = Integer.MAX_VALUE;
        for (int i=0; i<array.length; i++)
        {
            if(array[i] < min)
            {
                min = array[i];
            }
        }

        System.out.println("Minimum: " + min);
    }


    public void maximum() {
        int max = array[0];

        for(int i=0; i<array.length; i++)
        {
           if(array[i] > max)
           {
               max = array[i];
           }
        }

        System.out.println("Maximum: " + max);


    }

    public void median() {
        Arrays.sort(array);

        if (array.length % 2 != 0){
            System.out.println("Median: " + array[array.length/2]);
        }
        else{
            System.out.println("Median: " + (array[(array.length-1)/2] + array[array.length/2])/2);

        }

    }
}

public class Main {

    public static void main(String args[]) {
        int[] intArray = new int[]{ 90, 81, 78, 95, 79, 72,85};
        RunnableDemo R1 = new RunnableDemo( "Average", intArray);
        R1.start();
        R1.average();

        RunnableDemo R2 = new RunnableDemo( "Minimum", intArray);
        R2.start();
        R2.minimum();

        RunnableDemo R3 = new RunnableDemo( "Maximum", intArray);
        R3.start();
        R3.maximum();

        RunnableDemo R4 = new RunnableDemo( "Median", intArray);
        R3.start();
        R3.median();

    }
}