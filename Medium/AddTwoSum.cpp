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

    void showList(ListNode *l1)
    {
        while (l1 != nullptr)
        {
            cout << l1->val << " ";
            l1 = l1->next;
        }
        cout << endl;
    }
};

class AddTwoSum
{
    ListNode* temp_list;
    ListNode* current;
    int carry;

public:
    AddTwoSum()
    {
        temp_list = new ListNode(); // Initialize the dummy node
        current = temp_list;
        carry = 0;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        while (l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return temp_list->next;
    }

    ~AddTwoSum()
    {
        // Destructor to clean up the dummy node if needed
        delete temp_list;
    }
};

ListNode* reverseNum(int &num)
{
    ListNode *temp_list = new ListNode();
    ListNode *l1 = temp_list;

    int temp = num;
    while (temp > 0)
    {
        int rem = temp % 10;
        l1->next = new ListNode(rem);
        l1 = l1->next;
        temp /= 10;
    }

    return temp_list->next;
}

int main()
{
    int num1 = 24;
    int num2 = 56;

    ListNode *l1 = reverseNum(num1);
    ListNode *l2 = reverseNum(num2);

    AddTwoSum ad;
    ListNode *l3 = ad.addTwoNumbers(l1, l2);

    ListNode result;
    result.showList(l3);

    // Clean up memory for l1, l2, l3
    while (l1 != nullptr)
    {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr)
    {
        ListNode *temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (l3 != nullptr)
    {
        ListNode *temp = l3;
        l3 = l3->next;
        delete temp;
    }

    return 0;
}
