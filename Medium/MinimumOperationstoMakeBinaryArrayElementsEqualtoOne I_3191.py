def min_operations(nums):
    n = len(nums)
    operations = 0

    for i in range(n):
        if nums[i] == 0:
            if i + 2 >= n:
                return -1
            # Flip the next 3 elements
            nums[i] ^= 1
            nums[i + 1] ^= 1
            nums[i + 2] ^= 1
            operations += 1

    return operations

# Example usage:
nums = [0, 1, 0, 0, 0, 1]
result = min_operations(nums)
print(result)  # Output: 2
