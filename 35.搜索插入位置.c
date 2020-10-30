/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start

//思考栈的解法(计数)
int searchInsert(int* nums, int numsSize, int target){

    int k = 0;
    int j = numsSize;
    int i = 0;

    while(k <= j)
    {
        i = (k+j)/2;

        if(nums[i] == target)
                return i;

        if(nums[i] < target)
        {
            if(i ==  0)
                return 1;
            else if(i == numsSize-1)
                return numsSize;
            else if(nums[i+1] >= target)
                return i+1;
            else
                i++;

            k = i;
        }
        else    //nums[i] > target
        {
            if(i ==  0)
                return 0;
            else if(nums[i-1] < target) 
            {
                if(i == numsSize-1)     //[1,3] 0
                    return numsSize-1;
                else
                    return i;
            }
            else if(nums[i-1] == target)
                return i-1;    
            else
                i--;
            
            j = i;
        }
    }

    return -1;  
}

// @lc code=end

