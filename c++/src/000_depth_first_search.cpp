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
#include <stack>
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

// Recursive
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

// Iterative
void DFS_pre_order_iterative(Node *root)
{
    stack<Node *> st;
    Node *curr_node = root;
    while (curr_node != nullptr || !st.empty())
    {
        // while current node is not null and the stack is not empty,
        // follow left nodes down until you hit a leaf,
        // adding the right nodes to the stack along the way.
        while (curr_node != nullptr)
        {
            printf("%i ", curr_node->val);
            if (curr_node->right != nullptr)
                st.push(curr_node->right);

            curr_node = curr_node->left;
        }

        // leaf has been found, if a node exists on the stack,
        // that becomes the current node
        if (!st.empty())
        {
            curr_node = st.top();
            st.pop();
        }
    }
}
void DFS_post_order_iterative(Node *root)
{
    stack<Node *> st1, st2;
    Node *curr_node = root;
    st1.push(root);
    while (!st1.empty())
    {
        curr_node = st1.top();
        st1.pop();
        st2.push(curr_node);

        if (curr_node->left != nullptr)
            st1.push(curr_node->left);
        if (curr_node->right != nullptr)
            st1.push(curr_node->right);
    }

    while (!st2.empty())
    {
        printf("%i ", st2.top()->val);
        st2.pop();
    }
}
void DFS_in_order_iterative(Node *root)
{
    stack<Node *> st;
    Node *curr_node = root;
    while (curr_node != nullptr || !st.empty())
    {
        // iterate through all lefts, adding the node to the stack
        // the first time you visit it.
        while (curr_node != nullptr)
        {
            st.push(curr_node);
            curr_node = curr_node->left;
        }

        // leaf has been reached
        // pop off the stack and handle it
        curr_node = st.top();
        st.pop();
        printf("%i ", curr_node->val);

        // current node is now the current node's right
        curr_node = curr_node->right;
    }
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

    printf("DFS pre order (recursive):\n");
    DFS_pre_order(&n0);
    printf("\n");

    printf("DFS pre order (iterative):\n");
    DFS_pre_order_iterative(&n0);
    printf("\n");

    printf("DFS post order (recursive):\n");
    DFS_post_order(&n0);
    printf("\n");

    printf("DFS post order (iterative):\n");
    DFS_post_order_iterative(&n0);
    printf("\n");

    printf("DFS in order (recursive):\n");
    DFS_in_order(&n0);
    printf("\n");

    printf("DFS in order (iterative):\n");
    DFS_in_order_iterative(&n0);
    printf("\n");

    return 0;
}
