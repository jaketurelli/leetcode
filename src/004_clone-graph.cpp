///////////////////////////////////////////////
/// @file 004_clone-graph.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/clone-graph/
/// @version 0.1
/// @date 2022-01-05
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

// completed: 1/5/2022
// Runtime: 13 ms, faster than 8.06% of C++ online submissions for Clone Graph.
// Memory Usage: 8.9 MB, less than 44.13% of C++ online submissions for Clone Graph.

// Modified 1/12/2022
// Runtime: 7 ms, faster than 61.98% of C++ online submissions for Clone Graph.
// Memory Usage: 9.1 MB, less than 10.78% of C++ online submissions for Clone Graph.
// 1.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<int, Node *> m_added_nodes;

public:
    Node *cloneGraph(Node *node)
    {

        if (node == nullptr)
            return nullptr;

        if (m_added_nodes.count(node->val) == 0)
        {
            printf("new node: %i\n", node->val);
            Node *new_node = new Node(node->val);
            m_added_nodes[node->val] = new_node;
        }
        else
            return nullptr;

        for (auto i = node->neighbors.begin(); i != node->neighbors.end(); ++i)
        {
            if (m_added_nodes.count((*i)->val) == 0)
                m_added_nodes[node->val]->neighbors.push_back(cloneGraph(*i));
            else
                m_added_nodes[node->val]->neighbors.push_back(m_added_nodes[(*i)->val]);
        }

        return m_added_nodes[node->val];
    }
};

void print_node(Node &node)
{
    printf("node: %i\n", node.val);
    for (auto i = node.neighbors.begin(); i != node.neighbors.end(); i++)
    {
        print_node(**i);
    }
}
int main(int argc, char const *argv[])
{
    Node node1 = Node(1);
    Node node2 = Node(2);
    Node node3 = Node(3);
    Node node4 = Node(4);
    node1.neighbors = {&node4, &node2};
    node2.neighbors = {&node1, &node3};
    node3.neighbors = {&node2, &node4};
    node4.neighbors = {&node3, &node1};
    Solution solution;
    Node *deep_copy = solution.cloneGraph(&node1);

    printf("printing clone:\n");
    // print_node(*deep_copy);

    return 0;
}
