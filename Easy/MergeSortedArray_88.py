from typing import List


class MergeSortedArray_88:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        tempArray = []

        for i in range(m):

            tempArray.append(nums1[i])

        for i in range(n):

            tempArray.append(nums2[i])

        tempArray.sort()

        for i in range(len(tempArray)):
            nums1[i] = tempArray[i]

        print(nums1)


obj = MergeSortedArray_88()
print(obj.merge([1,2,3,0,0,0],3,[2,5,6],3))