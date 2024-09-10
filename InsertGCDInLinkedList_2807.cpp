#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class InsertGCDInLinkedList_2807
{
private:
    int getGCD(int n1, int n2)
    {
        if (n2 == 0)
        {
            return n1;
        }
        return getGCD(n2, n1 % n2);
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;

        // Traverse the linked list and insert GCD nodes
        while (temp != nullptr && temp->next != nullptr)
        {
            int gcd = getGCD(temp->val, temp->next->val);

            // Insert the GCD node between the current node and the next node
            ListNode *gcd_node = new ListNode(gcd);
            gcd_node->next = temp->next;
            temp->next = gcd_node;

            // Move temp two steps forward
            temp = gcd_node->next;
        }

        return head; // Return the modified list starting from head
    }
};

int main()
{
    InsertGCDInLinkedList_2807 in;

    // Creating the linked list: 10 -> 6 -> 10 -> 3
    ListNode *head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    // Inserting GCD nodes
    ListNode *result = in.insertGreatestCommonDivisors(head);

    // Printing the modified list
    while (result != nullptr)
    {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << "nullptr" << endl;

    return 0;
}
