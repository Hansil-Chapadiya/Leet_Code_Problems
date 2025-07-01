#include <iostream>
#include <vector>
#include <string>

class FindtheOriginalTypedStringI
{
  public:
    int possibleStringCount(std::string word) {

        char prev = word[0];
        int cnt = 1;

        for(int i = 1; i < word.size(); i++)
        {
            if(prev == word[i])
            {
                cnt++;
            }

            prev = word[i];
        }
        return cnt;
    }
};

int main()
{

    FindtheOriginalTypedStringI f1;
    // std::cout<<f1.possibleStringCount("abbcccc");
    // std::cout<<f1.possibleStringCount("abcd");
    std::cout<<f1.possibleStringCount("aaaa");
    return 0;
}
