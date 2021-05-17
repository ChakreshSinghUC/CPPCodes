//Print the n-th Fibonacci number
//Concept: Instead of going for recursive calls to the function, we memoize the results in an array and refer it as we proceed linearly.
//Time complexity: O(n)

// LeetCode reference: https://leetcode.com/problems/fibonacci-number/

#include <iostream>
#include <vector>

using namespace std;

int fibonacci_iterative(int n)
{
    // Possible improvement: Space coplexity can be improved by relying only the two most recent Fibonacci numbers.
    vector<int> F(n, 0);
    F[0] = 1;
    F[1] = 1;

    for (int i = 2; i < n; i++)
        F[i] = F[i - 1] + F[i - 2];

    return F[n - 1];
}

int fibonacci_iterative_improved(int n)
{
    // Note: we are not maintaing an array of length n
    int curr = 1, prev = 0, next;
    for (int i = 1; i < n; i++)
    {
        next = curr + prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main()
{
    int n = 10;
    cout << "The " << n << "-th Fibonacci number is: " << fibonacci_iterative_improved(5);
}