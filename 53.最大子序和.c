/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */

// @lc code=start

//没有考虑到只有一个负数的情况  [-1]
//没有考虑到全是负数的情况  [-2,-1]
//边界条件  [-1,1,-1,2,-2,-2]
//[-1,-2,3,-1,-2,1,1]
int maxSubArray(int* nums, int numsSize){
    int suma = 0;
    int sumb = 0;
    int tmpa = 0;
    int tmpb = 0;
    int flag = 0;

    for (int i = 0; i < numsSize/2; i++)
    {
        if(nums[i]<0)
        {
            if(!flag)        //已经出现正数
            {
                if(i == 0)
                {
                    suma = nums[i];
                    continue;
                }

                if(suma <= nums[i]) 
                {
                    suma = nums[i];
                    continue;
                }
            } 
            
            if(tmpa + nums[i] < 0)
            {
                tmpa = 0;
                continue;
            }
        }

        flag = 1;
        tmpa += nums[i];

        if(tmpa > suma)
            suma = tmpa;
    }
    printf("\r\nsuma %d tmpa %d flag %d",suma,tmpa,flag);


    for (int j = numsSize-1; j >= numsSize/2; j--)
    {
        if(nums[j] < 0)
        {
            if(flag < 2)        //已经出现正数
            {
                if(j == numsSize - 1)
                {
                    sumb = nums[j];
                    continue;
                }

                if(sumb <= nums[j]) {
                    
                    sumb = nums[j];
                    continue;
                }
            } 
            
            if(tmpb + nums[j] < 0)
            {
                tmpb = 0;
                continue;
            }
        }

        flag = 2;
        tmpb += nums[j];

        if(tmpb > sumb)
            sumb = tmpb;
    }
    printf("\r\nsumb %d tmpb %d flag %d",sumb,tmpb,flag);

    tmpa += tmpb;

    if(flag)
    {
        if(suma < sumb)
            suma = sumb;
        if(suma < tmpb)
            suma = tmpb;
    } else {
        if(suma == 0)
            return sumb;
        if(sumb ==  0)
            return suma;
        if(suma < sumb)
            return sumb;
        return suma;
    }

    return suma;
    
}


// @lc code=end

