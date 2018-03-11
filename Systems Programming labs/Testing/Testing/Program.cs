using System;
using System.Text;
using Microsoft.VisualBasic;

public static class MyClass
{
    public static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        for (var i = 0; i <= 1000; i++)
        {
            Console.Write("\u1F0CF");
            if (i % 50 == 0)
            { // break every 50 chars
                Console.WriteLine();
            }
        }
        Console.ReadKey();
    }
}