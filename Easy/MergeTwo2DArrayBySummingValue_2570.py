""" from typing import List


class MergeTwo2DArraysBySummingValues_2570:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        uniqueList = {}
        for i in nums1:
            uniqueList[i[0]] = uniqueList.get(i[0], 0) + i[1]

        for j in nums2:
            uniqueList[j[0]] = uniqueList.get(j[0], 0) + j[1]

        uniqueList = sorted(uniqueList.items())
        result = [item for item in uniqueList]
        # result = [[item,value] for item,value in uniqueList]
        return result  # type: ignore


obj = MergeTwo2DArraysBySummingValues_2570()
print(obj.mergeArrays([[1, 2], [2, 3], [4, 5]], [[1, 4], [3, 2], [4, 1]]))
"""

from typing import List
import bisect


class MergeTwo2DArraysBySummingValues_2570:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        uniqueList = []

        def add_or_update(num):
            index = bisect.bisect_left(uniqueList, [num[0], 0])

            if index < len(uniqueList) and uniqueList[index][0] == num[0]:
                uniqueList[index][1] += num[1]
            else:
                uniqueList.insert(index, [num[0], num[1]])

        for num in nums1 + nums2:
            add_or_update(num)
        return uniqueList


obj = MergeTwo2DArraysBySummingValues_2570()
print(obj.mergeArrays([[1, 2], [2, 3], [4, 5]], [[1, 4], [3, 2], [4, 1]]))
