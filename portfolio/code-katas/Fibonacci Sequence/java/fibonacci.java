
import java.util.Scanner;

class fibonacci 
{
	private static long[] sequence = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903};

    public static void main(String[] args) 
    {
    	Scanner keyboard = new Scanner(System.in);

    	System.out.print("Enter index [between 0 and "+(sequence.length-1)+"]: ");
    	int index = keyboard.nextInt();
    
    	if (index >=0 && index < sequence.length) {
    		
    		// do work
            // System.out.println(sequence[index]);

            if (index == 0) {
                System.out.println("fibonacci number is 0");
            } else if (index == 1) {
                System.out.println("fibonacci number is 1");    
            } else {

                long startTime = System.nanoTime();
                long iterate  = iterative(index);
                long endTime = System.nanoTime();
                double elapsed = (endTime-startTime)/1000000;

                System.out.println("fibonacci number (iterative) is " + iterate + ", took " + elapsed + "ms and "+memoryUsage()+" bytes"); 

                startTime = System.nanoTime();
                long recurse  = recursively(index);
                endTime = System.nanoTime();
                elapsed = (endTime-startTime)/1000000;

                System.out.println("fibonacci number (recursively) is " + recurse + ", took " + elapsed + "ms and "+memoryUsage()+" bytes");
            }

    	} else {
    		System.out.println("Out of bounds");
    	}

    }

    public static long iterative(int index)
    {
        long index2 = 0;
        long index1 = 1;

        for (int i=3; i<=index; i++) {
            long temp = index1;
            index1 = index2 + index1; 
            index2 = temp;
        }

        return index2 + index1;
    }

    public static long recursively(int index)
    {
        if (index <= 0) {
            return 0;
        }

        if (index == 1) {
            return 1;
        }

        return recursively(index-1) + recursively(index-2);
    }

    public static long memoryUsage()
    {
        // Get the Java runtime
        Runtime runtime = Runtime.getRuntime();
        // Run the garbage collector
        runtime.gc();
        // Calculate the used memory
        long memory = (runtime.totalMemory() - runtime.freeMemory());

        return memory;
    }

}
