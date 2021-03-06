/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){

    *returnSize = rowIndex + 1;
    int *ret = malloc((rowIndex + 1) * sizeof(int));
    memset(ret,0,(rowIndex + 1) * sizeof(int));

    ret[0] = 1;
    if(rowIndex == 0)
        return ret;

    for(int i = 1;i <= rowIndex;i++)
    {
        int tmp = 1;
        if(i == 1)
        {
            ret[i] = 1;
        } else {
            for(int j = i-1;j > 0;j--)
                ret[j] = ret[j] + ret[j-1];
            ret[i] = 1;
        }
    }
    ret[rowIndex] = 1;

    return ret;
}
// @lc code=end

