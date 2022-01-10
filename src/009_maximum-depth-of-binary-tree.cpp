///////////////////////////////////////////////
/// @file 009_maximum-depth-of-binary-tree.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/maximum-depth-of-binary-tree/
/// @version 0.1
/// @date 2022-01-10
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <assert.h>
#include <cstdio>

using namespace std;

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
    int maxDepth(TreeNode *root)
    {
        return 0;
    }
};

bool tests(Solution &solution)
{
    // Constraints:
    // The number of nodes in the tree is in the range [0, 104].
    // -100 <= Node.val <= 100

    // Input: root = [3,9,20,null,null,15,7]
    // Output: 3
    TreeNode node0 = TreeNode(3);
    TreeNode node1 = TreeNode(9);
    TreeNode node2 = TreeNode(20);
    TreeNode node3 = TreeNode(15);
    TreeNode node4 = TreeNode(7);
    node0.left = &node1;
    node0.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    assert(solution.maxDepth(&node0) == 3);

    // Example 2:
    // Input: root = [1,null,2]
    // Output: 2
    TreeNode node10 = TreeNode(1);
    TreeNode node11 = TreeNode(2);
    node10.right = &node11;
    assert(solution.maxDepth(&node10) == 2);

    return true;
}

int main(int argc, char const *argv[])
{

    Solution solution;
    if (tests(solution))
        printf("PASS!\n");

    return 0;
}
