///////////////////////////////////////////////
/// @file 003_climbing-stairs.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/climbing-stairs/
/// @version 0.1
/// @date 2021-12-30
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////

// You are climbing a staircase.It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
#include <cstdio>
class Solution
{
public:
    int climbStairs(int n)
    {
        int n_minus1 = 1;
        int n_minus2 = 0;
        int current_iteration = 0;
        for (size_t i = 1; i <= n; i++)
        {
            current_iteration = n_minus1 + n_minus2;
            n_minus2 = n_minus1;
            n_minus1 = current_iteration;
        }

        return current_iteration;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // 1 <= n <= 45
    int n = 2;
    int n_ways = solution.climbStairs(n);
    printf("solution for %i: %i\n", n, n_ways);
    return 0;
}
