from typing import List


class FindUniqueBinaryString:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        twothpower = len(nums[0])
        map_size = pow(2, twothpower)
        # print(map_size)
        map_dict = self.createmap(map_size)
        for binaryStr in nums:
            map_dict.pop(binaryStr, None)

        return next(iter(map_dict.keys()))

    def createmap(self, nums: int) -> dict:
        map_dict = {}
        width = len(bin(nums - 1)[2:])  # Find the max binary length

        for num in range(nums):  # Include 0
            binaryStr = format(
                num, f"0{width}b"
            )  # Convert to binary with leading zeros
            print(binaryStr)
            map_dict[binaryStr] = num  # Store binary string as key

        return map_dict


f = FindUniqueBinaryString()
# print(f.findDifferentBinaryString(["01", "10"]))
# print(f.findDifferentBinaryString(["00","01"]))
print(f.findDifferentBinaryString(["111","011","001"]))
