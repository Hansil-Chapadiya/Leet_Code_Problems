#include <iostream>
#include <vector>
#include <string>
class RemoveAllOccuranceOfSubstring_1910
{
private:
public:
    std::string removeOccurrences(std::string s, std::string part)
    {
        int i;
        while (true)
        {
            if ((i = s.find(part)) != std::string::npos)
            {
                s = s.erase(i, part.size());
            }
            else
            {
                return s;
            }
        }
    }
};
int main()
{
    RemoveAllOccuranceOfSubstring_1910 r1;
    std::cout << r1.removeOccurrences("daabcbaabcbc", "abc");
}