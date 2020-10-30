/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start

//碰到第一个重复的数字后，一直找到下一个不同的数字
//找到下一个不同的数字后，若该数字有重复，移动到最后一个重复处，替换这个数字
//需要标记的位置：1.被替换数字首次出现的位置
//需要维护的值：被比较的值，交换后，变成新值继续比较 X 不需要
int removeDuplicates(int* nums, int numsSize){

    if(!numsSize)
        return 0;
    else if(numsSize == 1)
        return 1;

    int pos = 0;
    int tmp;

    for (int i = 1; i < numsSize; i++)
    {
        if(nums[pos] != nums[i])    
        {
            if(!pos || (i - pos) == 1)      //不需要交换
                pos++;
            else
            {
                while(i+1 < numsSize && nums[i] == nums[i+1]) i++;  

                tmp = nums[pos+1];
                nums[pos+1] = nums[i];
                nums[i] = tmp;
                pos++;
                //i++;
            }
        }
        else    //需要交换
        {   //注意while循环体为空的表达方式
            while(i+1 < numsSize && nums[pos] == nums[++i]) ;  //找到下一个不同的数字
            //{}
            while(i+1 < numsSize && nums[i] == nums[i+1]) i++;

            //此时i是第一个不同的数字
            //处理到最后仍然相同的情况,此时不进行交换
            if(!(i == numsSize -1 && nums[pos] == nums[i]))
            {
                tmp = nums[pos+1];
                nums[pos+1] = nums[i];
                nums[i] = tmp;
                pos++;
                //i++;
            }
        }
    }

    return pos+1;    
}


// @lc code=end

