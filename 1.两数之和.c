/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *retnums = malloc(2*sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize-1; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i]+nums[j] == target)
            {
                retnums[0] = i;
                retnums[1] = j;
                return retnums;
            }
        }
    }
    
    retnums[0] = -1;
    retnums[1] = -1;
    return retnums;
}


// @lc code=end

