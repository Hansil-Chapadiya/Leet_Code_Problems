from typing import List

class MaximumCandiesAllocatedtoKChildren_2226:
    def binarySearch(self, low: int, high: int, candies: List[int], k: int) -> int:
        best = 0
        while low <= high:
            childSatisfy = 0
            mid = (low + high) // 2
            for i in candies:
                childSatisfy += i // mid

            if childSatisfy >= k:
                best = mid  # Track the best possible result
                low = mid + 1
            else:
                high = mid - 1

        return best

    def maximumCandies(self, candies: List[int], k: int) -> int:
        if sum(candies) < k:  # Edge case: not enough candies for each child
            return 0
        low = 1
        high = max(candies)
        return self.binarySearch(low, high, candies, k)

# Test case
obj = MaximumCandiesAllocatedtoKChildren_2226()
print(obj.maximumCandies([5, 8, 6], 3))  # Output: 5
