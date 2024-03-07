using System;

namespace CsharpTest
{
    public class Program(string[] args)
    {
        public static void Main(string[] args)
        {
            l s = new l();
            s.hello();
        }

        struct l
        {
            public void hello()
            {
                Console.WriteLine("Hello world");
            }
        }


    }
}