/* https://leetcode.com/problems/two-sum/description/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *result = (void*)0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result = malloc(sizeof(int) * 2);
                result[0] = i; result[1] = j;
                *returnSize = 2;
                break;
            }
        }
    }

    return result;
}