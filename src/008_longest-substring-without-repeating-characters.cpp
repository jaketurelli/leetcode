///////////////////////////////////////////////
/// @file 008_longest-substring-without-repeating-characters.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// @version 0.1
/// @date 2022-01-08
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <string>
#include <map>
#include <assert.h>

using namespace std;

class Solution
{
public:
    ///////////////////////////////////////////////
    /// @brief Given a string s, find the length of the longest substring without repeating characters.
    ///
    /// @param s
    /// @return int
    ///////////////////////////////////////////////
    int lengthOfLongestSubstring(string s)
    {

        if (s.size() == 0)
            return 0;

        int current_count = 0;
        int max_count = 1;
        map<int, bool> *current_letters = new map<int, bool>();

        for (size_t i = 0; i < s.size(); ++i)
        {
            if ((*current_letters)[s[i]])
            {
                current_letters->clear();
                (*current_letters)[s[i]] = true;
                if (current_count > max_count)
                {
                    max_count = current_count;
                    current_count = 1;
                }
            }
            else
            {
                (*current_letters)[s[i]] = true;
                current_count++;
            }
        }
        if (current_count > max_count)
            max_count = current_count;
        return max_count;
    }
};

bool tests(Solution &solution)
{
    string t1 = "abcabcbb";
    assert(solution.lengthOfLongestSubstring(t1) == 3);

    string t2 = "au";
    assert(solution.lengthOfLongestSubstring(t2) == 2);

    string t3 = " ";
    assert(solution.lengthOfLongestSubstring(t3) == 1);

    string t4 = "dvdf";
    assert(solution.lengthOfLongestSubstring(t4) == 3);

    return true;
}

int main(int argc, char const *argv[])
{
    Solution solution;

    tests(solution);
    return 0;
}
