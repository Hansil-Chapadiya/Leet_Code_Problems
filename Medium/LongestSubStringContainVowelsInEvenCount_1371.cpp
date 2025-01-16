#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class LongestSubStringContainVowelsInEvenCount_1371
{
public:
    int findTheLongestSubstring(string s)
    {
        int mask = 0;
        unordered_map<int, int> mask_map;
        mask_map[0] = -1;
        int max_len = 0;

        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'a':
                mask ^= 1 << 0;
                break;
            case 'e':
                mask ^= 1 << 1;
                break;
            case 'i':
                mask ^= 1 << 2;
                break;
            case 'o':
                mask ^= 1 << 3;
                break;
            case 'u':
                mask ^= 1 << 4;
                break;
            default:
                break;
            }

            if (mask_map.find(mask) != mask_map.end())
            {
                max_len = max(max_len, i - mask_map[mask]);
            }
            else
            {
                mask_map[mask] = i;
            }
        }
        return max_len;
    }
};

int main()
{
    LongestSubStringContainVowelsInEvenCount_1371 l1;
    string s = "eleetminicoworoep";
    cout << "The length of the longest substring with vowels in even count is: "
         << l1.findTheLongestSubstring(s) << endl;
    return 0;
}

static const int hansil = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
How the Length is Calculated:
The length of the valid substring is always calculated as:

cpp
Copy code
current_index - previous_index_of_same_mask
*/