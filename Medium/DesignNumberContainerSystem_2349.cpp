/* #include <iostream>
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

 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <climits>

class DesignNumberContainerSystem_2349
{
private:
    std::unordered_map<int, int> index_map;  // Maps index -> number
    std::map<int, std::set<int>> number_map; // Maps number -> sorted set of indices

public:
    DesignNumberContainerSystem_2349() {}

    void change(int index, int number)
    {
        if (index_map.find(index) != index_map.end())
        {
            int old_number = index_map[index];
            number_map[old_number].erase(index);
            if (number_map[old_number].empty())
            {
                number_map.erase(old_number);
            }
        }
        index_map[index] = number;
        number_map[number].insert(index);
    }

    int find(int number)
    {
        if (number_map.find(number) == number_map.end())
            return -1;
        return *(number_map[number].begin()); // Get the smallest index
    }
};

int main()
{
    DesignNumberContainerSystem_2349 *d1 = new DesignNumberContainerSystem_2349();
    std::cout << d1->find(10) << std::endl; // Output: -1
    d1->change(2, 10);
    d1->change(1, 10);
    d1->change(3, 10);
    d1->change(5, 10);
    std::cout << d1->find(10) << std::endl; // Output: 1
    d1->change(1, 20);
    std::cout << d1->find(10) << std::endl; // Output: 2
    return 0;
}
