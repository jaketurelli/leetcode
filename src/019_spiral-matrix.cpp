///////////////////////////////////////////////
/// @file 019_spiral-matrix.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-01-17
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <cstdio>

using namespace std;

// Runtime: 4 ms, faster than 12.77% of C++ online submissions for Spiral Matrix.
// Memory Usage: 6.8 MB, less than 71.50% of C++ online submissions for Spiral Matrix.

class Solution
{
private:
    enum Direction
    {
        d_Right,
        d_Down,
        d_Left,
        d_Up
    };

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows * cols;
        int irow = 0;
        int icol = -1;
        int max_row = rows - 1;
        int min_row = 1;
        int max_col = cols - 1;
        int min_col = 0;
        Direction dir = Direction::d_Right;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i)
        {

            if (icol == max_col && dir == Direction::d_Right)
            {
                dir = Direction::d_Down;
                --max_col;
            }
            else if (icol == min_col && dir == Direction::d_Left)
            {
                dir = Direction::d_Up;
                ++min_col;
            }
            else if (irow == max_row && dir == Direction::d_Down)
            {
                dir = Direction::d_Left;
                --max_row;
            }
            else if (irow == min_row && dir == Direction::d_Up)
            {
                dir = Direction::d_Right;
                ++min_row;
            }

            switch (dir)
            {
            case Direction::d_Right:
                ++icol;
                break;
            case Direction::d_Down:
                ++irow;
                break;
            case Direction::d_Left:
                --icol;
                break;
            case Direction::d_Up:
                --irow;
                break;
            default:
                break;
            }

            ans[i] = matrix[irow][icol];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> sol = solution.spiralOrder(matrix);
    for (int val : sol)
        printf("%i ", val);
    return 0;
}
