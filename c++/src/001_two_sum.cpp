///////////////////////////////////////////////
/// @file 001_two_sum.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/two-sum/
/// @version 0.1
/// @date 2021-12-28
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////

// Complete 12/28/2021:
// Runtime: 17 ms, faster than 48.33% of C++ online submissions for Two Sum.
// Memory Usage: 11.2 MB, less than 22.64% of C++ online submissions for Two Sum.

// Corrected for speed 1/12/2022:
// Runtime: 12 ms, faster than 79.80% of C++ online submissions for Two Sum.
// Memory Usage: 10.9 MB, less than 45.57% of C++ online submissions for Two Sum.
// 1. unordered_map vs. map will speed things up
// 2. cleaner approach

#include <vector>
#include <unordered_map>
#include <cstdio>
using namespace std;

// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.

// You can return the answer in any order.

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> imap;
        for (int i = 0;; ++i)
        {
            auto it = imap.find(target - nums[i]);

            if (it != imap.end())
                return vector<int>{i, it->second};

            imap[nums[i]] = i;
        }
    }
};

int main(int argc, char const *argv[])
{
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    // Output: Because nums[0] + nums[1] == 9, we return [0, 1].
    vector<int> myvector = {2, 7, 11, 15};
    int target = 9;
    Solution solution;

    vector<int> indices = solution.twoSum(myvector, target);
    for (auto i = indices.begin(); i != indices.end(); i++)
    {
        printf("%i ", *i);
    }
    printf("\n");

    return 0;
}
