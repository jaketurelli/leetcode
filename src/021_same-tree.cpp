///////////////////////////////////////////////
/// @file 021_same-tree.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/same-tree/
/// @version 0.1
/// @date 2022-01-17
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

//Definition for a binary tree node.
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
    // Runtime: 3 ms, faster than 54.17% of C++ online submissions for Same Tree.
    // Memory Usage: 10.1 MB, less than 7.30% of C++ online submissions for Same Tree.
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
            return p == q;

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
