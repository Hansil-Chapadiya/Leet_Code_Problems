def minimize_xor(num1, num2):
    # Count the number of set bits in num2
    set_bits_num2 = bin(num2).count('1')

    # Start with num1 and modify to have the same number of set bits as num2
    x = 0
    # Place bits in the same position as num1 first
    for i in range(31, -1, -1):  # Check from the most significant bit to the least
        if set_bits_num2 == 0:
            break
        if num1 & (1 << i):  # If the ith bit of num1 is set
            x |= (1 << i)  # Set the ith bit in x
            set_bits_num2 -= 1

    # If there are still set bits needed, place them in the lowest available positions
    for i in range(32):  # Check from the least significant bit to the most
        if set_bits_num2 == 0:
            break
        if not (x & (1 << i)):  # If the ith bit of x is not set
            x |= (1 << i)  # Set the ith bit in x
            set_bits_num2 -= 1

    return x

# Test the function with an example
num1 = 10  # Binary: 1010
num2 = 3   # Binary: 0011
minimize_xor(num1, num2)


