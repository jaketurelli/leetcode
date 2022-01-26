///////////////////////////////////////////////
/// @file 023_binary-tree-maximum-path.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/binary-tree-maximum-path-sum/
/// @version 0.1
/// @date 2022-01-18
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <algorithm>
#include <cstdio>
using namespace std;

// Runtime: 36 ms, faster than 32.77% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 27.7 MB, less than 69.22% of C++ online submissions for Binary Tree Maximum Path Sum.

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int m_max_value;

public:
    Solution() : m_max_value(-1000) {}

    int maxPathSum(TreeNode *root)
    {

        int max_sum = maxPathIter(root);

        return m_max_value;
    }

    int maxPathIter(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        // sum right
        int right_sum = maxPathIter(root->right) + root->val;

        // sum left
        int left_sum = maxPathIter(root->left) + root->val;

        if (right_sum > m_max_value)
            m_max_value = right_sum;

        if (left_sum > m_max_value)
            m_max_value = left_sum;

        if (root->val > m_max_value)
            m_max_value = root->val;

        if (left_sum + right_sum - root->val > m_max_value)
            m_max_value = left_sum + right_sum - root->val;

        return max(max(left_sum, right_sum), root->val);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode root(2);
    TreeNode left(-1);
    TreeNode right(-2);
    root.left = &left;
    root.right = &right;
    Solution solution;
    int max_val = solution.maxPathSum(&root);
    printf("max_val: %i\n", max_val);
    return 0;
}
