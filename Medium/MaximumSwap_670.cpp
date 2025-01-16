#include <iostream>
#include <string>
#include <algorithm>

class MaximumSwap_670
{
public:
    int maximumSwap(int num)
    {
        std::string num_str = std::to_string(num);

        // Find the maximum digit's position
        auto max = std::max_element(num_str.begin(), num_str.end());
        int dist = std::distance(num_str.begin(), max);

        // If the largest digit is not at the first position, swap it with the first
        // if (dist != 0)
        // {
        //     std::swap(num_str[0], num_str[dist]);
        // }
        // else
        // {
        // Max digit is already at the first position. Look for the largest possible one-swap improvement.
        int max_swap_idx = -1;
        int left_swap_idx = -1;
        char max_swap_value = '0';

        // Traverse from right to left to find the best swap
        for (int i = num_str.size() - 1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (num_str[i] > num_str[j])
                {
                    // Store the best swap candidate
                    if (num_str[i] > max_swap_value)
                    {
                        max_swap_value = num_str[i];
                        max_swap_idx = i;
                        left_swap_idx = j;
                    }
                }
            }
        }

        // Perform the best swap if found
        if (max_swap_idx != -1)
        {
            std::swap(num_str[max_swap_idx], num_str[left_swap_idx]);
        }
        // }

        // Convert the modified string back to an integer and return it
        return std::stoi(num_str);
    }
};

int main()
{
    MaximumSwap_670 m1;
    // std::cout << m1.maximumSwap(99368) << std::endl; // Expected: 99863
    std::cout << m1.maximumSwap(1993) << std::endl; // Expected: 99863
    return 0;
}
