#include <iostream>
using namespace std;

// Simple Recursive Fibonacci
long long fibonachi(int n)
{
    if (n <= 1){
        return n;
    }
        
    return fibonachi(n - 1) + fibonachi(n - 2);
}

// Iterative Fibonacci with Memoization
long long fibonacci_iterative_Memo(int n, long long *memo)
{
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (memo[i] == 0)
            memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

// Helper function for matrix multiplication
void multiply(long long F[2][2], long long M[2][2])
{
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// Recursive power function for matrix exponentiation
void power(long long F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;

    long long M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

// Fibonacci using Matrix Exponentiation
long long fib(int n)
{
    if (n == 0)
        return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}

int main()
{
    int n = 50;

    cout << "Fibonacci of 25 using simple recursion is: " << fibonachi(25) << endl;
    cout << "Fibonacci of " << n << " using matrix exponentiation is: " << fib(n) << endl;

    long long memo[60] = {0};
    cout << "Fibonacci of " << n << " using iterative memoization is: " << fibonacci_iterative_Memo(n, memo) << endl;

    return 0;
}
