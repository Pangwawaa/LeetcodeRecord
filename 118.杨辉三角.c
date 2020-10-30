/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    if(numRows == 0)
        return NULL;

    int *retColumnSizes = malloc(numRows * sizeof(int));
    *returnColumnSizes = retColumnSizes;
    int **ret = malloc(numRows * sizeof(int *));

    int *array = malloc(sizeof(int));
    array[0] = 1;
    ret[0] = array;
    retColumnSizes[0] = 1;
    if(numRows == 1)
        return ret;

    array = malloc(2 * sizeof(int));
    array[0] = 1;
    array[1] = 1;
    ret[1] = array;
    retColumnSizes[1] = 2;
    if(numRows == 2)
        return ret;

    int i = 2;
    while(i < numRows)
    {
        int j = 0;
        array = malloc((i+1) * sizeof(int));
        array[j++] = 1;
        while(j < i)
        {
            array[j] = *(ret[i-1]+j-1) + *(ret[i-1]+j);
            j++;
        }
        array[j] = 1;
        ret[i] = array;
        retColumnSizes[i] = i + 1;
        i++;
    } 
    return ret;
}


// @lc code=end

