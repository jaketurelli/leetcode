///////////////////////////////////////////////
/// @file 019_spiral-matrix.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
/// @version 0.1
/// @date 2022-01-17
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        // Runtime: 5 ms, faster than 85.19% of C++ online submissions for Longest Repeating Character Replacement.
        // Memory Usage: 7 MB, less than 83.81% of C++ online submissions for Longest Repeating Character Replacement.

        int letters[26] = {0};
        int res = 0;
        int max_length = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            max_length = max(++letters[s[i] - 'A'], max_length);

            if (res - max_length < k)
                res++;
            else
                letters[s[i - res] - 'A']--;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    solution.characterReplacement();
    for (int val : sol)
        printf("%i ", val);
    return 0;
}
