///////////////////////////////////////////////
/// @file 000_backtrace_nqueens.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/n-queens-ii/solution/
/// @version 0.1
/// @date 2022-02-03
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

#include <unordered_set>
#include <cstdio>
using namespace std;

class Solution
{

private:
    int m_n = 0;
    int backtrack(int row, unordered_set<int> &cols, unordered_set<int> &diags, unordered_set<int> &anti_diags)
    {
        //Base case -N queens have been placed
        if (row == m_n)
            return 1;

        int solutions = 0;
        for (int col = 0; col < m_n; ++col)
        {
            int curr_diagonal = row - col;
            int curr_anti_diagonal = row + col;
            // If the queen is not placeable
            if (cols.find(col) != cols.end() ||
                diags.find(curr_diagonal) != diags.end() ||
                anti_diags.find(curr_anti_diagonal) != anti_diags.end())
                continue;

            // "Add" the queen to the board
            cols.insert(col);
            diags.insert(curr_diagonal);
            anti_diags.insert(curr_anti_diagonal);

            // Move on to the next row with the updated board state
            solutions += backtrack(row + 1, cols, diags, anti_diags);

            //"Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.erase(col);
            diags.erase(curr_diagonal);
            anti_diags.erase(curr_anti_diagonal);
        }

        return solutions;
    }

public:
    int totalNQueens(int n)
    {
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> anti_diags;
        m_n = n;
        return backtrack(0, cols, diags, anti_diags);
    }
};

int main(int argc, char const *argv[])
{

    Solution solution;
    printf("%i\n", solution.totalNQueens(5));

    return 0;
}
