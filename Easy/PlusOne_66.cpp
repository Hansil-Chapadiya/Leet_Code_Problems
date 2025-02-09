// #include <iostream>
// #include <vector>
// #include <string>
// class PlusOne_66
// {
// private:
// public:
//     std::vector<int> plusOne(std::vector<int> &digits)
//     {
//         // long long sum = 0;
//         // for (int i = 0; i < digits.size(); i++)
//         // {
//         //     sum = (sum * 10) + digits[i];
//         // }
//         // std::string num = std::to_string(sum + 1);

//         std::vector<int> answer;
//         std::string digit;
//         for (int i = 0; i < digits.size(); i++)
//         {
//             digit += (digits[i] + '0');
//         }

//         char ch = digit.empty() ? '0' : digit.back();


//         if (ch == '9')
//         {
//             int n = digit.size() - 1;
//             int size_of_digit = digit.size();
//             int cnt = 0;
//             while (digit[n] == '9' && n >= 0) // 8 9 9 9
//             {
//                 n--;
//                 cnt++;
//             }
//             if (n == -1)
//             {
//                 n++;
//                 digit[n] = '1';
//                 n++;
//                 while (cnt != 0 && n <= size_of_digit)
//                 {
//                     digit.push_back('0');
//                     n++;
//                     cnt--;
//                 }
//             }
//             else
//             {

//                 int d = digit[n] - '0' + 1;
//                 // std::cout << d << std::endl;
//                 digit[n] = d + '0';
//                 // cnt--;
//                 n++;
//                 while (cnt != 0 && n < size_of_digit)
//                 {
//                     digit[n] = '0';
//                     n++;
//                     cnt--;
//                 }
//             }
//             // digit[digit.size() - 1] = '1';
//             // digit.push_back('0');
//         }
//         else
//         {
//             int last_digit = (ch - '0') + 1;
//             digit[digit.size() - 1] = last_digit + '0';
//         }
//         digit.push_back('\0');

//         std::cout << digit;
//         for (auto i : digit)
//         {
//             answer.push_back(i - '0');
//         }
//         return answer;
//     }
// };
// int main()
// {
//     PlusOne_66 p1;
//     // std::vector<int> nums = {7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6, 7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7, 4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6};
//     // std::vector<int> nums = {1, 2, 3};
//     // std::vector<int> nums = {8, 9, 9, 9};
//     // std::vector<int> nums = {9, 0, 9};
//     std::vector<int> nums = {9};

//     p1.plusOne(nums);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>

std::vector<int> plusOne(std::vector<int> &digits) {
    std::vector<int> answer;
    std::string digit;

    // Convert vector to string
    for (int i = 0; i < digits.size(); i++) {
        digit += (digits[i] + '0');
    }

    // Get last character safely
    char ch = digit.back();

    if (ch == '9') {
        int n = digit.size() - 1;
        int size_of_digit = digit.size();
        int cnt = 0;

        // Find the position of the last non-'9' digit
        while (n >= 0 && digit[n] == '9') {
            n--;
            cnt++;
        }

        if (n == -1) {  // All digits are '9' (e.g., "999")
            digit = "1";  // Set first digit to '1'
            while (cnt--) digit.push_back('0');  // Append zeros
        } else {  // Case like "12899" → "12900"
            digit[n] = (digit[n] - '0' + 1) + '0';  // Increment non-'9' digit
            n++;
            while (cnt--) digit[n++] = '0';  // Set remaining to '0'
        }
    } else {  // Normal case: Just increment the last digit
        digit.back() = (ch - '0' + 1) + '0';
    }

    // Convert back to vector<int>
    for (char c : digit) {
        answer.push_back(c - '0');
    }

    return answer;
}

int main() {
    std::vector<int> digits = {9, 9, 9};  // Example input
    std::vector<int> result = plusOne(digits);

    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
