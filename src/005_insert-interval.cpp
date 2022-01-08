///////////////////////////////////////////////
/// @file 005_insert-interval.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/insert-interval/
/// @version 0.1
/// @date 2022-01-05
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

// You are given an array of non-overlapping intervals intervals where
// intervals[i] = [starti, endi] represent the start and the end of
// the ith interval and intervals is sorted in ascending order by starti.
// You are also given an interval newInterval = [start, end] that
// represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted
// in ascending order by starti and intervals still does not have any
// overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.
class Solution
{
private:
    enum Location
    {
        LOCATION_OUTSIDE_BELOW,
        LOCATION_OUTSIDE_ABOVE,
        LOCATION_INSIDE,
        LOCATION_NOT_FOUND
    };

public:
    vector<vector<int>>
    insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> FinalInterval;
        int new_indices[2] = {0};
        Location new_index_locations[2] = {LOCATION_NOT_FOUND, LOCATION_NOT_FOUND};

        for (int i = 0; i < 2; i++)
        {
            int bound_low = 0;
            int bound_high = intervals.size();
            bool bound_found = false;
            while (!bound_found)
            {
                int bin_ind = (bound_high - bound_low) / 2 + bound_low;
                printf("bin_ind: %i\n", bin_ind);
                // inside?
                if (intervals[bin_ind][0] <= newInterval[i] && intervals[bin_ind][1] >= newInterval[i])
                {
                    bound_found = true;
                    new_index_locations[i] = LOCATION_INSIDE;
                    new_indices[i] = bin_ind;
                    printf("bound (%i) found inside interval {%i,%i}\n", newInterval[i], intervals[bin_ind][0], intervals[bin_ind][1]);
                }
                else if (intervals[bin_ind][1] < newInterval[i])
                {
                    printf("higher\n");
                    if (bin_ind == intervals.size() - 1 || newInterval[i] < intervals[bin_ind + 1][0])
                    {
                        bound_found = true;
                        new_index_locations[i] = LOCATION_OUTSIDE_ABOVE;
                        new_indices[i] = bin_ind;
                        printf("bound (%i) found above interval {%i,%i}\n", newInterval[i], intervals[bin_ind][0], intervals[bin_ind][1]);
                    }
                    else
                    {
                        bound_low = bin_ind;
                        continue;
                    }
                }
                else if (intervals[bin_ind][1] > newInterval[i])
                {
                    printf("lower\n");
                    if (bin_ind == 0 || newInterval[i] > intervals[bin_ind - 1][1])
                    {
                        bound_found = true;
                        new_index_locations[i] = LOCATION_OUTSIDE_BELOW;
                        new_indices[i] = bin_ind;
                        printf("bound (%i) found below interval {%i,%i}\n", newInterval[i], intervals[bin_ind][0], intervals[bin_ind][1]);
                    }
                    else
                    {
                        bound_high = bin_ind;
                        continue;
                    }
                }
            }
        }

        // binary search:
        //   1. at each index:
        //      a. are you inside?
        //      b. are you just above?
        //          if no (just higher than next) - go again at higher bound
        //      c. are you just below?
        //          if no (just lower than previous) - go again at lower bound

        return FinalInterval;
    }
};

int main(int argc, char const *argv[])
{
    // Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    // Output: [[1,2],[3,10],[12,16]]
    Solution solution;
    vector<vector<int>> intervals = {
        {1, 2},
        {4, 5},
        {6, 7},
        {8, 10},
        {12, 16}};
    vector<int> new_interval = {13, 14};
    vector<vector<int>> final_interval = solution.insert(intervals, new_interval);

    return 0;
}
