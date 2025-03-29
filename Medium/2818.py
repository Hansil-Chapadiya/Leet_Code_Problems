from typing import List
import heapq
import math

class MaximizeScoreUsingOperations_2818:
    MOD = 10**9 + 7

    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prime_factors_count = [0] * n

        # Calculate the prime factor count for each number in nums
        for index in range(n):
            num = nums[index]

            # Check for prime factors from 2 to sqrt(n)
            for factor in range(2, int(math.sqrt(num)) + 1):
                if num % factor == 0:
                    # Increment prime factor count
                    prime_factors_count[index] += 1

                    # Remove all occurrences of the prime factor from num
                    while num % factor == 0:
                        num //= factor

            # If num is still greater than or equal to 2, it's a prime factor
            if num >= 2:
                prime_factors_count[index] += 1

        # Initialize next and previous dominant index arrays
        next_higher_prime_index = [n] * n
        prev_higher_prime_index = [-1] * n

        # Stack to store indices for maintaining decreasing order of prime factor count
        decreasing_prime_stack = []

        # Calculate the next and previous dominant indices for each number
        for index in range(n):
            while (
                decreasing_prime_stack
                and prime_factors_count[decreasing_prime_stack[-1]]
                < prime_factors_count[index]
            ):
                top_index = decreasing_prime_stack.pop()

                # Set the next dominant element for the popped index
                next_higher_prime_index[top_index] = index

            # If the stack is not empty, set the previous dominant element for the current index
            if decreasing_prime_stack:
                prev_higher_prime_index[index] = decreasing_prime_stack[-1]

            # Push the current index onto the stack
            decreasing_prime_stack.append(index)

        # Calculate the number of subarrays in which each element is dominant
        dominant_subarray_count = [0] * n
        for index in range(n):
            dominant_subarray_count[index] = (next_higher_prime_index[index] - index) * (
                index - prev_higher_prime_index[index]
            )

        # Max heap to process elements in decreasing order of their value
        max_heap = []

        # Push each number and its index onto the max heap
        for index in range(n):
            heapq.heappush(max_heap, (-nums[index], index))

        max_score = 1

        # Helper function to compute the power of a number modulo MOD
        def modular_exponentiation(base, exponent):
            result = 1

            # Compute exponentiation using binary exponentiation
            while exponent > 0:
                if exponent % 2 == 1:
                    result = (result * base) % self.MOD

                base = (base * base) % self.MOD
                exponent //= 2

            return result

        # Process elements while there are operations left
        while k > 0 and max_heap:
            # Get the element with the maximum value from the heap
            num, index = heapq.heappop(max_heap)
            num = -num  # Convert back to positive

            # Determine the number of operations to apply on the current element
            operations = min(k, dominant_subarray_count[index])

            # Update the score by raising the element to the power of operations
            max_score = (max_score * modular_exponentiation(num, operations)) % self.MOD

            # Reduce the remaining operations count
            k -= operations

        return max_score


# Example usage:
obj = MaximizeScoreUsingOperations()
print(obj.maximumScore([8,3,9,3,8], 2))
