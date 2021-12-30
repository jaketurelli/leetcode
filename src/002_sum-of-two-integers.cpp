///////////////////////////////////////////////
/// @file 002_sum-of-two-integers.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/sum-of-two-integers/
/// @version 0.1
/// @date 2021-12-28
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <bitset>
using namespace std;

// Complete (12/30/2021)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
// Memory Usage: 5.9 MB, less than 23.95% of C++ online submissions for Sum of Two Integers.

// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.

// You can return the answer in any order.

class Solution
{
public:
    //Given two integers a and b, return the sum of the two integers without using the operators + and -.
    //     Constraints:
    // -1000 <= a, b <= 1000
    int getSum(int a, int b)
    {
        const int number_bits = sizeof(int) * 8;

        int sum_value = 0;
        bool remainder = 0;

        uint8_t sum_mask = 0;
        const uint8_t MASK0 = 0; // 000
        const uint8_t MASK1 = 1; // 001
        const uint8_t MASK2 = 3; // 011
        const uint8_t MASK3 = 7; // 111

        for (size_t place_index = 0; place_index < number_bits; place_index++)
        {
            if (a & 1U)
                sum_mask |= (sum_mask << 1U) | 1U;
            if (b & 1U)
                sum_mask |= (sum_mask << 1U) | 1U;
            if (remainder)
                sum_mask |= (sum_mask << 1U) | 1U;

            if (sum_mask == MASK1)
            {
                sum_value |= (1U << place_index);
                remainder = 0;
            }
            else if (sum_mask == MASK2)
            {
                remainder = 1;
            }
            else if (sum_mask == MASK3)
            {
                // printf("size 3\n");

                sum_value |= (1U << place_index);
                remainder = 1;
            }

            a >>= 1U;
            b >>= 1U;
            sum_mask = 0;
        }
        return sum_value;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    printf("sum: %i\n", solution.getSum(-20, 30));

    return 0;
}
