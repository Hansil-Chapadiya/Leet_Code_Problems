/* #include <iostream>
#include <vector>
#include <algorithm>

class MergeTwoSortedArray
{
public:
    std::vector<int> sortedArray(std::vector<int> arr1, std::vector<int> arr2)
    {
        for (int i = 0; i < arr2.size(); i++)
        {
            arr1.push_back(arr2[i]);
        }

        std::sort(arr1.begin(), arr1.end());
        return arr1;
    }
};

int main()
{
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {6, 7, 8, 9, 10};

    MergeTwoSortedArray m1;
    std::vector<int> answer = m1.sortedArray(arr1, arr2);

    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
} */


#include <iostream>
#include <vector>

class MergeTwoSortedArray
{
  public:
  std::vector<int> sortedArray(std::vector<int> arr1, std::vector<int> arr2)
  {
      int m = arr1.size();
      int n = arr2.size();

      // Expand arr1 to hold all elements
      arr1.resize(m + n);

      int size_m = m - 1;
      int size_n = n - 1;
      int answer_array_size = m + n - 1;

      while (size_m >= 0 && size_n >= 0)
      {
          if (arr1[size_m] > arr2[size_n])
          {
              arr1[answer_array_size] = arr1[size_m];
              size_m--;
          }
          else
          {
              arr1[answer_array_size] = arr2[size_n];
              size_n--;
          }
          answer_array_size--;
      }

      while (size_n >= 0)
      {
          arr1[answer_array_size] = arr2[size_n];
          size_n--;
          answer_array_size--;
      }

      return arr1;
  }
};

int main()
{
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {6, 7, 8, 9, 10};

    MergeTwoSortedArray m1;
    std::vector<int> answer = m1.sortedArray(arr1, arr2);

    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}
