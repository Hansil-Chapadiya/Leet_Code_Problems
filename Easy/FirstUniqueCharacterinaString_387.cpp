#include <iostream>
#include <vector>
#include <unordered_map>  // Faster!

class FirstUniqueCharacterinaString_387
{
    public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> freqMap;

        for(char c : s)
        {
            freqMap[c]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (freqMap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    FirstUniqueCharacterinaString_387 f1;
    std::cout << f1.firstUniqChar("loveleetcode");
    return 0;
}
