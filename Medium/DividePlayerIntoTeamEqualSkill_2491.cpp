#include <iostream>
#include <vector>
#include <unordered_map>
class DividePlayerIntoTeamEqualSkill_2491
{
private:
public:
    long long dividePlayers(std::vector<int> &skill)
    {
        // Step 1: Check if the number of elements is even
        if (skill.size() % 2 != 0)
        {
            return -1;
        }

        // Step 2: Calculate the total sum and target sum for each pair
        int total_sum = 0;
        for (int num : skill)
        {
            total_sum += num;
        }
        // If total_sum is not divisible by half of the array size, pairing is impossible
        int n = skill.size() / 2;
        if (total_sum % n != 0)
        {
            return -1;
        }
        int target_pair_sum = total_sum / n;

        // Step 3: Use a frequency map to count elements
        std::unordered_map<int, int> freq;
        for (int num : skill)
        {
            ++freq[num];
        }

        // Step 4: Try to form pairs
        long long total_skill = 0;
        for (int num : skill)
        {
            // Skip this element if it is already paired
            if (freq[num] == 0)
            {
                continue;
            }

            // Calculate the complement that would make the target pair sum
            int complement = target_pair_sum - num;

            // Check if the complement exists and is available for pairing
            if (freq[complement] > 0)
            {
                // Use one occurrence of this element and one of its complement
                total_skill += (num * complement);
                freq[num]--;
                freq[complement]--;
            }
            else
            {
                // If complement is not found, pairing is not possible
                return -1;
            }
        }

        // If all elements are paired, return true
        return total_skill;
    }
};
int main()
{
    DividePlayerIntoTeamEqualSkill_2491 d1;
    std::vector<int> skills = {1,1,2,3};
    std::cout << d1.dividePlayers(skills);
    return 0;
}