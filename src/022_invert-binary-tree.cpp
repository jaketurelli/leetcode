///////////////////////////////////////////////
/// @file 022_invert-binary-tree.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief  https://leetcode.com/problems/invert-binary-tree/
/// @version 0.1
/// @date 2022-01-18
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

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
public:
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
    // Memory Usage: 9.8 MB, less than 37.95% of C++ online submissions for Invert Binary Tree.

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};