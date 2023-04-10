using System;
using System.Threading;
using System.Threading.Tasks;

namespace Server
{
    class Program
    {
        static void MainThread(object state)
        {
            for(int i = 0; i < 5; i++)
            {
                Console.WriteLine("Hello Thread");
            } 
              
        }
        static void Main(string[] args)
        {
            Task t = new Task(() => { while (true) { } },TaskCreationOptions.LongRunning);

            ThreadPool.QueueUserWorkItem(MainThread);

            while (true)
            {

            }

            //Thread t = new Thread(MainThread); // default thread is t.IsBackGround is false
            //t.IsBackground = true;
            //t.Name = "Test Thread";
            //t.Start();
            //Console.WriteLine("Waiting for Thread");
            //t.Join();

            //Console.WriteLine("Hello, World!");


        }
    }
}
