///////////////////////////////////////////////
/// @file 010_merge-k-sorted-lists.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-01-10
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <cstdio>

using namespace std;

// Definition for singly-linked list.
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
    static constexpr int START_MIN = 10 * 10 * 10 * 10 + 1;

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode();
        ListNode *curr_node = head;
        bool complete = false;
        int n_lists = lists.size();

        while (!complete)
        {
            complete = true;
            int next_val_index = 0;
            int next_val = 0;
            int current_min = START_MIN;
            for (int i = 0; i < n_lists; ++i)
            {
                ListNode *curr_list = lists[i];
                if (curr_list != nullptr)
                {
                    complete = false;
                    if (curr_list->val <= current_min)
                    {
                        next_val_index = i;
                        next_val = curr_list->val;
                    }
                }
            }

            // capture value
            curr_node->val = next_val;

            // todo: capture next node on previous?

            // get next node for the one that was used
            lists[next_val_index] = lists[next_val_index]->next;
        }
    }
};

ListNode *get_list(int array[], int array_size)
{
    if (array_size == 0)
        return nullptr;

    ListNode *head_node = new ListNode(array[0]);
    ListNode *previous_node = head_node;
    for (size_t i = 1; i < array_size; i++)
    {
        ListNode *current_node = new ListNode(array[i]);
        previous_node->next = current_node;
        previous_node = current_node;
    }
    return head_node;
}
bool tests(Solution &solution)
{
    /// Example 1
    // Input: lists = [[1,4,5],[1,3,4],[2,6]]
    // Output: [1,1,2,3,4,4,5,6]
    // Explanation: The linked-lists are:
    // [
    //   1->4->5,
    //   1->3->4,
    //   2->6
    // ]
    // merging them into one sorted list:
    // 1->1->2->3->4->4->5->6
    int list1[3] = {1, 4, 5};
    ListNode *test1_node_1 = get_list(list1, 3);
    int list2[3] = {1, 3, 4};
    ListNode *test1_node_2 = get_list(list1, 3);
    int list3[2] = {2, 6};
    ListNode *test1_node_3 = get_list(list1, 2);
    vector<ListNode *> test1 = {test1_node_1, test1_node_2, test1_node_3};

    solution.mergeKLists(test1);

    return true;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    if (tests(solution))
        printf("PASS!\n");
    else
    {
        printf("FAIL!\n");
    }

    return 0;
}
