public class Fibonacci {
    int fib(int n)
    {    //base condition
        if(n <=1) return n;
        //recurrence relation
        else  return fib(n-1) + fib(n-2);
    }

}