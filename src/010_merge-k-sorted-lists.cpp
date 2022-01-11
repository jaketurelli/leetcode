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

// Completed 1/10/2022
// Runtime: 604 ms, faster than 8.07% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 13 MB, less than 94.92% of C++ online submissions for Merge k Sorted Lists.

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
        int n_lists = lists.size();
        if (n_lists == 0)
            return nullptr;

        ListNode *head = nullptr;
        ListNode *curr_node = nullptr;
        ListNode *prev_node = nullptr;
        bool complete = false;
        bool not_first_run = false;

        while (!complete)
        {
            complete = true;
            int next_val_index = 0;
            int current_min = START_MIN;
            for (int i = 0; i < n_lists; ++i)
            {
                if (lists[i] != nullptr)
                {
                    complete = false;
                    if (lists[i]->val < current_min)
                    {
                        next_val_index = i;
                        current_min = lists[i]->val;
                    }
                }
            }

            if (complete)
                return head;

            curr_node = lists[next_val_index];
            printf("adding %i from list %i\n", curr_node->val, next_val_index);

            // get next node for the one that was used
            lists[next_val_index] = lists[next_val_index]->next;

            // todo: capture next node on previous?
            if (not_first_run)
            {
                prev_node->next = curr_node;
            }
            else
            {
                head = curr_node;
                not_first_run = true;
            }

            curr_node->next = nullptr;
            prev_node = curr_node;
        }
        return head;
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
    ListNode *test1_node_2 = get_list(list2, 3);
    int list3[2] = {2, 6};
    ListNode *test1_node_3 = get_list(list3, 2);
    vector<ListNode *> test1 = {test1_node_1, test1_node_2, test1_node_3};

    ListNode *test1_solution = solution.mergeKLists(test1);
    printf("printfing solution:\n");
    while (test1_solution != nullptr)
    {
        printf("%i,", test1_solution->val);
        test1_solution = test1_solution->next;
    }
    printf("\n");

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
