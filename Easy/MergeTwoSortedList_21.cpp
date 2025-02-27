#include <iostream>
#include <vector>
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
class MergeTwoSortedList_21
{
private:
    /* data */
public:
};
int main()
{
    MergeTwoSortedList_21 m1;
    ListNode *list1;
    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next = new ListNode(4);

    ListNode *list2;
    list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list1->next = new ListNode(4);

    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
