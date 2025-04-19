from typing import List

class IntersectionOfTwoArray_349:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Sort both arrays
        nums1.sort()
        nums2.sort()

        # Two pointers
        i = 0
        j = 0

        answer = set()

        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                answer.add(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return list(answer)

# Testing
obj  = IntersectionOfTwoArray_349()
print(obj.intersection([1, 2, 2, 1], [2, 2]))         # Output: [2]
print(obj.intersection([4, 9, 5], [9, 4, 9, 8, 4]))   # Output: [9, 4]
