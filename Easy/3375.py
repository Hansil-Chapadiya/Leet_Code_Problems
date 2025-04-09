def min_operations(nums, k):
    if any(num < k for num in nums):
        return -1  # impossible

    unique_vals = set(num for num in nums if num != k)
    ops = 0
    sorted_vals = sorted(unique_vals, reverse=True)

    current_vals = set(nums)

    while current_vals != {k}:
        # Pick h such that all values > h are the same
        greater_than_h = [val for val in current_vals if val > k]
        if not greater_than_h:
            break
        max_val = max(greater_than_h)
        # Find next highest value below max_val to serve as h
        possible_h = max(k, max([x for x in current_vals if x < max_val], default=k))
        # Perform the operation
        current_vals.remove(max_val)
        current_vals.add(possible_h)
        ops += 1

    return ops if current_vals == {k} else -1
