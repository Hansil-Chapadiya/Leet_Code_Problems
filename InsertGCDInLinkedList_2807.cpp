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
        // cout << *this->num1 << " " << *this->num2 << endl;
        // while ((*this->num2) > 0)
        // {
        //     int q = *this->num1 / *this->num2;
        //     int r = *this->num1 - (q * (*this->num2));
        //     *this->num1 = *this->num2;
        //     *this->num2 = r;
        // }
        // return *this->num1;
        if (n1 == 0)
        {
            return n2;
        }
        else
        {
            int r = (n2) % (n1);
            return getGCD(r, n1);
        }
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp_list = head;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            if (temp->val && temp->next != nullptr && temp->next->val)
            {
                int gcd = getGCD(temp->val, temp->next->val);
                ListNode *gcd_node = new ListNode(gcd);
                gcd_node->next = temp_list->next;
                temp_list->next = gcd_node;
                temp_list = gcd_node->next;
            }
        }

        return temp_list;
    }
};
int main()
{
    InsertGCDInLinkedList_2807 in;
    ListNode *head = new ListNode(10);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    ListNode *result = in.insertGreatestCommonDivisors(head);
    while (result != nullptr)
    {
        cout<<result->val;
        result = result->next;
    }

}
