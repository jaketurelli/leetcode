///////////////////////////////////////////////
/// @file 028_longest-increasing-subsequence.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/longest-increasing-subsequence/solution/
/// @version 0.1
/// @date 2022-01-30
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution
{

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1);
        int max_length = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > max_length)
                        max_length = dp[i];
                }
            }
        }
        return max_length;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 1, 2, 3};
    printf("max_length: %i\n", solution.lengthOfLIS(nums));
    return 0;
}
