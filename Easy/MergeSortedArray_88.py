""" from typing import List


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
print(obj.merge([1,2,3,0,0,0],3,[2,5,6],3)) """



from typing import List


class MergeSortedArray_88:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        size_m = m-1
        size_n = n-1
        answer_array_size = m + n - 1


        while size_m >= 0 and size_n >= 0:

            if nums1[size_m] > nums2[size_n]:

                nums1[answer_array_size] = nums1[size_m]

                size_m -= 1

            else:

                nums1[answer_array_size] = nums2[size_n]

                size_n -= 1

            answer_array_size -= 1

        while size_n >= 0:

            nums1[answer_array_size] = nums2[size_n]

            size_n -= 1

            answer_array_size -= 1

        print(nums1)


obj = MergeSortedArray_88()
print(obj.merge([1,2,3,0,0,0],3,[2,5,6],3))


