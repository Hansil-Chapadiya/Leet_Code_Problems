// #include <iostream>
// #include <vector>
// using namespace std;
// class MissingObservation_2028
// {
// private:

// public:
//     MissingObservation_2028(/* args */);
//     ~MissingObservation_2028();
//     vector<int> missingRolls(vector<int> &, int, int);
// };
// vector<int> MissingObservation_2028::missingRolls(vector<int> &rolls, int mean, int n)
// {
//     int m_array_length = rolls.size();
//     int n_array_length = n;
//     int flag =0;
//     int sum = (n + m_array_length) * mean;
//     int sum_of_given_rolls = 0;
//     for (int i = 0; i < m_array_length; i++)
//     {
//         sum_of_given_rolls += rolls.at(i);
//     }
//     int diff = sum - sum_of_given_rolls;
//     // for (int i = 0; i < possible_observation.size(); i++)
//     // {
//     //     for (int j = 0; j < possible_observation.size(); j++)
//     //     {
//     //         if ((possible_observation.at(i) + possible_observation.at(j)) == diff)
//     //         {
//     //             resultant_array.push_back(possible_observation.at(i));
//     //             resultant_array.push_back(possible_observation.at(j));
//     //             flag = 1;
//     //         }
//     //     }
//     //     if (flag)
//     //     {
//     //         break;
//     //     }

//     // }
//     // Check if the difference can be divided across the missing rolls
//     if (diff < n || diff > 6 * n) {
//         return {}; // Return empty vector if it's not possible
//     }

//     vector<int> resultant_array(n, 1); // Start with all rolls set to 1
//     diff -= n; // We already added 1 for each missing roll

//     for (int i = 0; i < n && diff > 0; i++) {
//         int increment = min(5, diff); // We can add at most 5 to each roll
//         resultant_array[i] += increment;
//         diff -= increment;
//     }

//     return resultant_array;
// }
// MissingObservation_2028::MissingObservation_2028(/* args */)
// {
// }

// MissingObservation_2028::~MissingObservation_2028()
// {
// }
// int main()
// {
//     MissingObservation_2028 m1;
//     vector<int> rolls = {1,5,6};
//     int mean = 3;
//     int n = 4;
//     vector<int> missing_place = m1.missingRolls(rolls, mean, n);
//     for (int i = 0; i < missing_place.size(); i++)
//     {
//         cout << missing_place.at(i);
//     }
// }

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class MissingObservation_2028
{
public:
    MissingObservation_2028() {}
    ~MissingObservation_2028() {}
    vector<int> missingRolls(vector<int> &rolls, int mean, int n);
};

vector<int> MissingObservation_2028::missingRolls(vector<int> &rolls, int mean, int n)
{
    int m_array_length = rolls.size();
    int total_sum = (n + m_array_length) * mean;
    int sum_of_given_rolls = accumulate(rolls.begin(), rolls.end(), 0);
    int diff = total_sum - sum_of_given_rolls;

    // Check if the difference can be divided across the missing rolls
    if (diff < n || diff > 6 * n) {
        return {}; // Return empty vector if it's not possible
    }

    vector<int> resultant_array(n, 1); // Start with all rolls set to 1
    diff -= n; // We already added 1 for each missing roll

    for (int i = 0; i < n && diff > 0; i++) {
        int increment = min(5, diff); // We can add at most 5 to each roll
        resultant_array[i] += increment;
        diff -= increment;
    }

    return resultant_array;
}

int main()
{
    MissingObservation_2028 m1;
    vector<int> rolls = {1, 5, 6};
    int mean = 3;
    int n = 4;

    vector<int> missing_place = m1.missingRolls(rolls, mean, n);

    if (missing_place.empty()) {
        cout << "No valid solution." << endl;
    } else {
        for (int i = 0; i < missing_place.size(); i++) {
            cout << missing_place[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
