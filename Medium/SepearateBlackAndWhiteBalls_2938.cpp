#include <iostream>
#include <string>
#include <vector>

class SeperateBlackAndWhiteBalls_2938
{
private:
    long long swapCount = 0; // Track number of swaps

    // Merge function used in merge sort
    void merge(std::vector<char> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays
        std::vector<char> L(n1), R(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        // Merge the temporary arrays back into arr[left..right]
        int i = 0;    // Initial index of first subarray
        int j = 0;    // Initial index of second subarray
        int k = left; // Initial index of merged subarray

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
                // Every time a character from the right half is placed before the left,
                // it indicates swaps. The number of such swaps is equal to the number
                // of remaining elements in the left half (because they're all bigger).
                swapCount += (n1 - i);
            }
            k++;
        }

        // Copy the remaining elements of L[], if any
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if any
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Merge sort function
    void mergeSort(std::vector<char> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

public:
    long long minimumSteps(std::string s)
    {
        std::vector<char> arr(s.begin(), s.end());
        mergeSort(arr, 0, arr.size() - 1);
        return swapCount;
    }
};

int main()
{
    SeperateBlackAndWhiteBalls_2938 sorter;
    std::string s = "100";

    long long swapCount = sorter.minimumSteps(s);

    std::cout << "Number of swaps: " << swapCount << std::endl;

    return 0;
}
