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
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n_intervals = intervals.size();
        int high_boundary = intervals.size();
        int low_boundary = 0;

        stack<int> low_indices;
        stack<int> high_indices;

        bool high_boundary_found = false;
        bool low_boundary_found = false;
        int low_index = 0;
        int high_index = 0;
        int int_index = 0;
        while (!high_boundary_found && !low_boundary_found)
        {
            // int binary_ind = (high_boundary - low_boundary) / 2;
            int binary_ind = int_index;

            if (intervals[binary_ind][0] <= newInterval[0] && intervals[binary_ind][1] >= newInterval[0])
            {
                // between current interval
                low_boundary_found = true;
                low_index = binary_ind;
                break;
            }
            else if (intervals[binary_ind][0] > newInterval[0])
            {
                // outside this boundary, lower
                high_boundary = binary_ind;
            }
            else if (intervals[binary_ind][1] < newInterval[0])
            {
                low_boundary = binary_ind;
                // outside this boundary, higher
            }
            int_index++;
        }
    }
};

int main(int argc, char const *argv[])
{
    // Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    // Output: [[1,2],[3,10],[12,16]]
    Solution solution;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> new_interval = {4, 8};
    vector<vector<int>> final_interval = solution.insert(intervals, new_interval);

    return 0;
}
