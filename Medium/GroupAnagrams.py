from typing import List
from collections import defaultdict

class GroupAnagrams:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        hashMap = defaultdict(list)

        for string in strs:
            key = tuple(sorted(string))
            hashMap[key].append(string)

        # for val in hashMap.values():
        #     print(val)

        return list(hashMap.values())


obj = GroupAnagrams()
print(obj.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))