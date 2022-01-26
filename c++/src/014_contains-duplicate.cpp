///////////////////////////////////////////////
/// @file 014_contains-duplicate.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/contains-duplicate/
/// @version 0.1
/// @date 2022-01-15
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

#include <vector>
#include <unordered_set>

// Runtime: 76 ms, faster than 62.52% of C++ online submissions for Contains Duplicate.
// Memory Usage: 51.5 MB, less than 23.82% of C++ online submissions for Contains Duplicate.

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        unordered_set<int> iset;
        for (int i = 0; i < nums.size(); ++i)
        {
            // if (iset.find(nums[i]) != iset.end())
            //     return true;
            pair<unordered_set<int>::iterator, bool> inserted = iset.insert(nums[i]);
            if (!inserted.second)
                return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.containsDuplicate return 0;
}
