///////////////////////////////////////////////
/// @file 006_reverse-linked-list.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/reverse-linked-list/
/// @version 0.1
/// @date 2022-01-08
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <cstdio>
using namespace std;

// Completed 1/8/2022
// Runtime: 8 ms, faster than 62.75% of C++ online submissions for Reverse Linked List.
// Memory Usage: 8.2 MB, less than 78.03% of C++ online submissions for Reverse Linked List.

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *next;
        ListNode *previous = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode node5(5);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);
    ListNode *reverse_list = solution.reverseList(&node1);

    ListNode *print_node = reverse_list;
    while (print_node != nullptr)
    {
        printf("node %i\n", print_node->val);
        print_node = print_node->next;
    }

    return 0;
}
