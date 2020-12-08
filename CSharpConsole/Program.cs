using System;
using MazeCrackerDotnet;

namespace CSharpConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            Maze maze = new Maze(16, 16);
            maze.RandomGenerate();
            Console.WriteLine(maze);
        }
    }
}
