using System;

public class Test
{
	public static void Main()
	{
		t1 = CreateThread(ThreadProc, 123);
		
		//
		// ...
		
		//Wait for the thread to terminate
		t1.Join();
	}
	
	ThreadProc(int)
	{
	    //Doing long time
	    
	    //end
	}
}
