#include <iostream>
#include <stack>

class CustomStack
{
private:
    int top;
    std::stack<int> stk;
    std::stack<int> tmp_stk;

public:
    CustomStack(int maxSize)
    {
    }

    void push(int x)
    {
        stk.push(x);
    }

    int pop()
    {
        int pop_val = stk.top();
        stk.pop();
        return pop_val;
    }

    void increment(int k, int val)
    {
        if (k >= stk.size())
        {
            while (!stk.empty())
            {
                tmp_stk.push(stk.top() + val);
                stk.pop();
            }
        }
        else
        {
            while (stk.size() > k)
            {
                tmp_stk.push(stk.top());
                stk.pop();
            }
            while (!stk.empty())
            {
                tmp_stk.push(stk.top() + val);
                stk.pop();
            }
        }
        while (!tmp_stk.empty())
        {
            stk.push(tmp_stk.top());
            tmp_stk.pop();
        }

    }
    void display()
    {
        while (!stk.empty())
        {
            std::cout<<stk.top()<<" ";
            stk.pop();
        }

    }
    int top_()
    {
        return stk.top();
    }
};
int main()
{
    CustomStack stk1(4);
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    // stk1.push(4);
    stk1.increment(5, 100);
    stk1.increment(2, 100);
    // std::cout<<stk1.top_();
    // std::cout<<stk1.top_();
    // std::cout<<stk1.top_();
    // std::cout<<stk1.top_();
    stk1.display();
}
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */