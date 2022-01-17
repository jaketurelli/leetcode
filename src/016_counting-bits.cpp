///////////////////////////////////////////////
/// @file 016_counting-bits.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/counting-bits/
/// @version 0.1
/// @date 2022-01-16
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

#include <vector>
#include <cstdio>
using namespace std;

// Runtime: 12 ms, faster than 16.30% of C++ online submissions for Counting Bits.
// Memory Usage: 7.8 MB, less than 88.16% of C++ online submissions for Counting Bits.

class Solution
{
public:
    vector<int> countBits(int n)
    {
        // 0       0    0
        // 1       1    1
        // 2     1 0    1
        // 3     1 1    2
        // 4   1 0 0    1
        // 5   1 0 1    2
        int number_bits = 0;
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            ans[i] = ans[i & (i - 1)] + 1;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> new_array = solution.countBits(5);

    for (int val : new_array)
        printf("%i ", val);
    return 0;
}
