using System;
using System.Numerics;
namespace App;
class Program
{
    static void First_Phase() {
        int n, m = 0;
        double x = 0;
        Console.WriteLine("Введите n: ");
        n = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Введите m: ");
        m = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine($"n++ * m = {n++ * m}");
        Console.WriteLine($"m-- < n = {m-- < n}");
        Console.WriteLine($"++m > n = {m-- < n}");
        Console.WriteLine("Введите x: ");
        x = Convert.ToInt32(Console.ReadLine());
        double a = Math.Cos(Math.Atan(x));
        Console.WriteLine($"cos(arctg(x)) = {a}");
    }
    static void Second_Phase()
    {
        int x, y = 0;
        Console.WriteLine("Введите x: ");
        x = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Введите y: ");
        y = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine($"x, y = {x}, {y}");
        if ((y < 0 && y > -7 && x < 5 && x > 0) || (x >= 0 && y >= 0 && (x+y) <= 5)){
            Console.WriteLine($"x = {x}, y = {y}, входит в область определения");
        }
        else
        {
            Console.WriteLine($"x,y не входят в область определения");
        }
    }
    static void Third_Phase()
    {
        double a = 1000;
        double b = 0.0001;
        double c = (Math.Pow((a - b), 4) - (Math.Pow(a, 4) + 6 * Math.Pow(a, 2) * Math.Pow(b, 2) + Math.Pow(b, 4))) / (-4 * a * Math.Pow(b, 3) - 4 * b * Math.Pow(a, 3));
        Console.WriteLine($"Значение выражения: {c}");
    }
    static void Main(string[] args)
    {
        int x = 0;
        Console.WriteLine("Выбор задания: 1, 2, 3");
        x = Convert.ToInt32(Console.ReadLine());
        switch (x)
        {
            case 1:
                First_Phase();
                break;
            case 2:
                Second_Phase();
                break;
            case 3:   
                Third_Phase(); 
                break;
            default:
                Console.WriteLine("Неправильный выбор");
                break;
        }
    }
}