#include <iostream>
#include <vector>
#include <algorithm>

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeTwoSortedList_21
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        std::vector<int> v;

        // Collect values from list1
        ListNode *temp = list1;
        while (temp != nullptr)
        { // Now correctly handles 1-element lists
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Collect values from list2
        temp = list2;
        while (temp != nullptr)
        { // Now correctly handles 1-element lists
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the collected values
        std::sort(v.begin(), v.end());

        // Handle empty case
        if (v.empty())
            return nullptr;

        // Create new linked list from sorted values
        ListNode *result = new ListNode(v[0]);
        temp = result;
        for (size_t i = 1; i < v.size(); i++)
        {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }

        return result;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    MergeTwoSortedList_21 m1;

    // Creating list1: 1 -> 2 -> 4
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Creating list2: 1 -> 3 -> 4
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merge lists
    ListNode *mergedList = m1.mergeTwoLists(list1, list2);

    // Print merged list
    printList(mergedList);

    return 0;
}
