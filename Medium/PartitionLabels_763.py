from typing import List

class PartitionLabels_763:
    def partitionLabels(self, s: str) -> List[int]:
        partition = []
        lastIdxMap = {}

        # Step 1: Store the last occurrence index of each character
        for i in range(len(s)):
            lastIdxMap[s[i]] = i

        # Step 2: Partition the string
        start, end = 0, 0
        for i in range(len(s)):
            end = max(end, lastIdxMap[s[i]])
            if i == end:  # End of a partition
                partition.append(end - start + 1)
                start = i + 1  # Move to the next partition

        return partition

# Testing
obj = PartitionLabels_763()
s = "ababcbacadefegdehijhklij"
print(obj.partitionLabels(s))
