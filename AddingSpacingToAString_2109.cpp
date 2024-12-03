#include <iostream>
#include <vector>
#include <string>

class AddingSpacingToAString_2109
{
private:
    /* data */
public:
    std::string addSpaces(std::string s, std::vector<int> &spaces)
    {
        std::string temp;
        int j = 0;
        for (int i = 0; i < spaces.size(); i++)
        {
            s.insert(spaces[i]+j, " ");
            j++;
        }
        return s;

        /*

        */
    }
};
int main()
{
    AddingSpacingToAString_2109 a1;
    std::vector<int> spaces = {5, 9};
    std::string s = "EnjoyYourCoffee";
    std::cout<<a1.addSpaces(s, spaces);
}