///////////////////////////////////////////////
/// @file 007_set-matrix-zeroes.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/set-matrix-zeroes/
/// @version 0.1
/// @date 2022-01-08
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

// Completed 1/8/2022
// Runtime: 16 ms, faster than 51.73% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.5 MB, less than 10.93% of C++ online submissions for Set Matrix Zeroes.

class Solution
{
public:
    // Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

    // You must do it in place.

    void setZeroes(vector<vector<int>> &matrix)
    {
        map<int, bool> columns_to_zero;
        map<int, bool> rows_to_zero;
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    columns_to_zero[i] = true;
                    rows_to_zero[j] = true;
                }
            }
        }

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[0].size(); ++j)
            {
                if (columns_to_zero[i] || rows_to_zero[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    //     Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    //     Output: [[1,0,1],[0,0,0],[1,0,1]]
    vector<vector<int>> input_matrix = {{1, 1, 1},
                                        {1, 0, 1},
                                        {1, 1, 1}};

    Solution solution;
    solution.setZeroes(input_matrix);

    for (size_t i = 0; i < input_matrix.size(); ++i)
    {
        for (size_t j = 0; j < input_matrix[0].size(); ++j)
        {
            printf("%i ", input_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
