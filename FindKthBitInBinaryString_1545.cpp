#include <iostream>
#include <string>
#include <algorithm>
class FindKthBitInBinaryString_1545
{
private:
    std::string s1 = "0";
    std::string invert(std::string str)
    {
        std::string str_ = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0')
            {
                str_ += '1';
            }
            else
            {
                str_ += '0';
            }
        }
        return str_;
    }

public:
    char findKthBit(int n, int k)
    {
        for (int i = 1; i < n; i++)
        {
            std::string temp = invert(s1);
            std::reverse(temp.begin(), temp.end());
            s1 = s1  + "1" + temp;
            // std::cout<<s1<<std::endl;
        }
        return s1[k-1];
    }
};
int main()
{
    FindKthBitInBinaryString_1545 k1;
    std::cout << k1.findKthBit(4, 11);
    return 0;
} // 011
// 011