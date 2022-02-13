///////////////////////////////////////////////
/// @file 000_breadth-first-search.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief breadth first search practice
/// @version 0.1
/// @date 2022-02-12
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <queue>
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

void BFS_non_recursive(Node *root)
{
    // we build up a queue, adding to the queue at each level
    // we grab the oldest node on the queue (FIFO), print/process it
    // then add left and right nodes to the queue
    // then we pop off the current Node from the queue
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        printf("%i ", q.front()->val);

        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);

        q.pop();
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

    BFS_non_recursive(&n0);
    return 0;
}
