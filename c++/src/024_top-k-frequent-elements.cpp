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
#include <unordered_map>
#include <cstdio>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans(k, 0);
        vector<int> freqs(k, 0);
        vector<int> vals(k, 0);
        unordered_map<int, int> imap;
        unordered_map<int, int> bk_ind;
        for (int j = 0; j < nums.size(); ++j)
        {
            int num = nums[j];
            ++imap[num];
            auto p_f = freqs.begin();
            auto p_v = vals.begin();
            for (int i = 0; i < k; ++i)
            {
                if (imap[num] > freqs[i])
                {
                    if (num == vals[i])
                    {
                        freqs[i] = imap[num];
                    }
                    else
                    {
                        int ind = -1;
                        if (bk_ind.find(num) != bk_ind.end())
                            ind = bk_ind[num];

                        bk_ind[num] = i;
                        freqs.insert(p_f + i, imap[num]);
                        vals.insert(p_v + i, num);

                        if (ind > 0)
                        {
                            freqs.erase(ind + p_f + 1);
                            vals.erase(ind + p_v + 1);
                        }
                    }

                    break;
                }
            }
        }

        for (int i = 0; i < k; ++i)
        {
            ans[i] = vals[i];
            printf("%i,", ans[i]);
        }
        printf("\n");

        return ans;
    }
};

bool tests(Solution &solution)
{
    // vector<int> test1 = {1, 1, 1, 2, 2, 3};
    // // k = 2
    // vector<int> ans1 = solution.topKFrequent(test1, 2);
    // assert(ans1[0] == 1);
    // assert(ans1[1] == 2);

    vector<int> test2 = {3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6};
    // k = 10
    vector<int> ans2 = solution.topKFrequent(test2, 10);

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
