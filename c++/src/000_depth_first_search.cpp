///////////////////////////////////////////////
/// @file 000_depth_first_search.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief Depth first search practice
/// @version 0.1
/// @date 2022-02-12
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <cstdio>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0),
             left(nullptr),
             right(nullptr) {}
    Node(int _val) : val(_val),
                     left(nullptr),
                     right(nullptr) {}
    Node(int _val, Node *_left, Node *_right) : val(_val),
                                                left(_left),
                                                right(_right) {}
};

void DFS_pre_order(Node *root)
{
    if (root == nullptr)
        return;
    printf("%i ", root->val);
    DFS_pre_order(root->left);
    DFS_pre_order(root->right);
}
void DFS_post_order(Node *root)
{
    if (root == nullptr)
        return;

    DFS_post_order(root->left);
    DFS_post_order(root->right);
    printf("%i ", root->val);
}
void DFS_in_order(Node *root)
{
    if (root == nullptr)
        return;

    DFS_in_order(root->left);
    printf("%i ", root->val);
    DFS_in_order(root->right);
}

int main(int argc, char const *argv[])
{
    Node n8 = Node(8);
    Node n7 = Node(7);
    Node n6 = Node(6, &n8, nullptr);
    Node n3 = Node(3);
    Node n4 = Node(4, nullptr, &n7);
    Node n5 = Node(5);
    Node n1 = Node(1, &n3, &n4);
    Node n2 = Node(2, &n5, &n6);
    Node n0 = Node(0, &n1, &n2);

    //               0
    //          /         \
    //         1            2
    //       /   \         /  \ 
    //      3     4       5     6
    //             \           /
    //              7         8

    printf("DFS pre order:\n");
    DFS_pre_order(&n0);
    printf("\n");

    printf("DFS post order:\n");
    DFS_post_order(&n0);
    printf("\n");

    printf("DFS in order:\n");
    DFS_in_order(&n0);
    printf("\n");

    return 0;
}
