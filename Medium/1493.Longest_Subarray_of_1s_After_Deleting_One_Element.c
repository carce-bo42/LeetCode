/* https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/ */

int longestSubarray(int* nums, int numsSize) {

    int zero_0 = -1;
    int zero_1 = -1;
    int zero_2 = -1;
    int greatest_diff = -1;

    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            zero_0 = zero_1;
            zero_1 = zero_2;
            zero_2 = i;
            if (zero_2 - zero_0 > greatest_diff) {
                greatest_diff = zero_2 - zero_0;
            }
        }
    }
    // One more last loop, when zero_2 is past the end of the numsSize.
    zero_0 = zero_1;
    zero_1 = zero_2;
    zero_2 = numsSize;
    if (zero_2 - zero_0 > greatest_diff) {
        greatest_diff = zero_2 - zero_0;
    }

    // No zeros or one found.
    if (zero_2 == -1 || zero_1 == -1) {
        return numsSize-1;
    }

    // Two zeros found
    if (zero_0 == -1) {
        return numsSize - zero_1 > zero_2 ? numsSize-zero_1-1  : zero_2-1;
    }

    return greatest_diff-2;
}