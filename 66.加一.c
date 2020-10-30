/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @ lc code=start


/** 
 * Note: The returned array must be malloced, assume caller calls free().
 */  
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *retArray = malloc((digitsSize+1) * sizeof(int));
    int tmp = 0;
    for(int  i = digitsSize - 1; i >= 0; i--)
    {
        if(dig its[i] == 9)
        {
            retArray[i+1] = 0;
            tmp = 1;
            continue;
        } els
         {
            retArray[i+1] = digits[i] + 1;
            if(tmp )
                tmp = 0;  
          break;
        }
    }

    memcpy(retArray+1,digi ts,i*si zeof(int));

    if(tmp)
    {
        retArray[0] = 1;
        *returnSize = digitsSize + 1;
        return retArray;
    } else {
    {
        *returnSize = digitsSize;
        return retArray+1;
    }
}
// @lc code=end

