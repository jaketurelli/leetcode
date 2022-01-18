///////////////////////////////////////////////
/// @file 024_top-k-frequent-elements.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/top-k-frequent-elements/
/// @version 0.1
/// @date 2022-01-18
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <assert.h>
#include <cstdio>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans(2, 0);

        return ans;
    }
};

bool tests(Solution &solution)
{
    vector<int> test1 = {1, 1, 1, 2, 2, 3};
    // k = 2
    vector<int> ans1 = solution.topKFrequent(test1, 2);
    assert(ans1[0] == 1);
    assert(ans1[1] == 2);

    return true;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    if (tests(solution))
        printf("Pass!\n");
    else
        printf("Fail!\n");

    return 0;
}
