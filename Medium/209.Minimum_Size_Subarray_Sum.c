/* https://leetcode.com/problems/minimum-size-subarray-sum/description/ */

int minSubArrayLen(int target, int* nums, int numsSize){

    int sum = 0;
    int start = 0;
    int min_len = numsSize + 1;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        while (sum >= target) {
            // The minimum length is the last length that satisfied sum >= target.
            min_len = i - start + 1 < min_len ? i - start + 1 : min_len;
            sum -= nums[start];
            start++;
        }
    }
    return min_len == numsSize + 1 ? 0 : min_len;
}