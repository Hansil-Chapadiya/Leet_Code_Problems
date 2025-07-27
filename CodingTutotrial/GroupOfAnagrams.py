from typing import List
from collections import defaultdict

def anagram(strs: List[str]) -> List[List[str]]:
    freqMap = defaultdict(list)  # Automatically creates an empty list for new keys

    for str_ in strs:
        sorted_str = ''.join(sorted(str_))  # Sorting the string gives a common key for anagrams
        freqMap[sorted_str].append(str_)

    answer = list(freqMap.values())  # Extract all anagram groups

    return answer

print(anagram(["eat", "tea", "tan", "ate", "nat", "bat"]))
