#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
class DesignNumberContainerSystem_2349
{
private:
    std::unordered_map<int, int> u_map;

public:
    DesignNumberContainerSystem_2349()
    {
    }

    void change(int index, int number)
    {
        u_map[index] = number;
    }

    int find(int number)
    {
        int min = INT_MAX;

        for (auto i : u_map)
        {
            if (i.second == number && i.first < min)
            {
                min = i.first;
            }
        }
        return min == INT_MAX ? -1 : min;
    }
};
int main()
{
    DesignNumberContainerSystem_2349 *d1 = new DesignNumberContainerSystem_2349();
    std::cout << d1->find(10) << std::endl;
    d1->change(2, 10);
    d1->change(1, 10);
    d1->change(3, 10);
    d1->change(5, 10);
    std::cout << d1->find(10) << std::endl;
    d1->change(1, 20);
    std::cout << d1->find(10) << std::endl;
    return 0;
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */