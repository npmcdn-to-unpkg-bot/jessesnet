
import java.util.Scanner;

class fibonacci 
{
	private static int[] sequence = {0,1,1,2,3,5,8,13,21,34,55,89,144,233};

    public static void main(String[] args) 
    {
    	Scanner keyboard = new Scanner(System.in);

    	System.out.print("Enter index: ");
    	int index = keyboard.nextInt();
    
    	if (index >=0 && index < sequence.length) {
    		
    		// do work

    	} else {
    		System.out.println("Not found");
    	}

    }

}