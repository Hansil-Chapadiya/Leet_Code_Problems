class MinimumEndValue {
public:
    long long findMinimumEnd(int sequenceLength, int targetAND) {
        // Start the result as targetAND since it's the smallest possible valid start
        long long endValue = targetAND;

        // Reduce sequence length by 1 as the first element (targetAND) is already counted
        --sequenceLength;

        // Initialize bitMask to 1; this will be used to check each bit of targetAND
        long long bitMask;

        // Loop through each bit position in targetAND by shifting the bitMask left each iteration
        for (bitMask = 1; sequenceLength > 0; bitMask <<= 1) {
            // Check if the current bit in targetAND is 0, allowing flexibility to set this bit in endValue
            if ((bitMask & targetAND) == 0) {
                // Set the bit in endValue if the least significant bit of sequenceLength is 1
                endValue |= (sequenceLength & 1) * bitMask;

                // Right shift sequenceLength to process the next bit in the following iteration
                sequenceLength >>= 1;
            }
            // If the current bit in targetAND is 1, we skip setting it in endValue to retain the AND result
        }

        // Return the final endValue, which is the minimum possible valid end value
        return endValue;
    }
};
