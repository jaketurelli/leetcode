///////////////////////////////////////////////
/// @file 012_number-of-1-bits.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/number-of-1-bits/
/// @version 0.1
/// @date 2022-01-10
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <cstdio>
#include <cstdint>
#include <assert.h>

// Completed 1/10/2022
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 5.9 MB, less than 79.91% of C++ online submissions for Number of 1 Bits.

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int number_bits = 0;
        for (size_t i = 0; i < 32; ++i)
        {
            number_bits += ((1U << i) & n) != 0;
        }
        return number_bits;
    }
};

bool tests(Solution &solution)
{
    // Example 1:
    // Input: n = 00000000000000000000000000001011
    // Output: 3
    // Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
    uint32_t test1 = 0b00000000000000000000000000001011;
    assert(solution.hammingWeight(test1) == 3);

    // Example 2:
    // Input: n = 00000000000000000000000010000000
    // Output: 1
    // Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
    uint32_t test2 = 0b00000000000000000000000010000000;
    assert(solution.hammingWeight(test2) == 1);

    // Example 3:
    // Input: n = 11111111111111111111111111111101
    // Output: 31
    // Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
    uint32_t test3 = 0b11111111111111111111111111111101;
    assert(solution.hammingWeight(test3) == 31);

    return true;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    if (tests(solution))
        printf("\033[1;42;33mPASS!\033[0m\t\t");
    else
        printf("\x1B[31mFAIL!\033[0m\t\t");
    return 0;
}
