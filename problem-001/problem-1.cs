using System;


public class CalcSum
{
    private readonly int _step;
    private readonly int _end;

    public CalcSum(int step, int end)
    {
        _step = step;
        _end  = end;
    }

    public int sum()
    {
        return sum(0);
    }

    private int sum(int i = 0)
    {
        if (i < _end)
            return sum(i + _step) + i;
        else
            return 0;
    }
}


public class Problem1
{
    public delegate int Summation();

    static public void Main ()
    {
        const int end = 1000;

        CalcSum calcSum3  = new CalcSum( 3, end);
        CalcSum calcSum5  = new CalcSum( 5, end);
        CalcSum calcSum15 = new CalcSum(15, end);

        Summation sum3  = new Summation(calcSum3.sum);
        Summation sum5  = new Summation(calcSum5.sum);
        Summation sum15 = new Summation(calcSum15.sum);

        int result = sum3() + sum5() - sum15();
        Console.WriteLine("Value: " + result);
    }
}
