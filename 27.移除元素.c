/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start

//按原有顺序列出所有不等于指定值的元素
//test fail:[1] 1
//test fail:[] 0
//test fail:[3,3] 3
//test fali:[3,3] 5
//test fail:[4,5] 5 没有考虑到前面全相等的情况，区分全相等和除了最后一个都相当的情况
//test fail:[2,2,3] 2
int removeElement(int* nums, int numsSize, int val){

    if(numsSize == 0)
        return numsSize;

    if(numsSize == 1)
    {
        if(nums[0] == val)
            return 0;
        else
            return 1;     
    }    

    int pos = numsSize-1;
    int tmp;
    int i;
    int count = 0;

    for (i = 0; i < pos+1; i++)
    {
        if(nums[i] == val)
        {
            //allequal = 0;
            count++;
            while(nums[pos] == val && pos > i) 
            {
                count++;
                pos--;
            }
            //printf("i=%d pos=%d\r\n",i,pos);
            if(pos > i)
            {   
                //nochange = 0;
                tmp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = tmp;
                pos--;
                //count++；
            }
        }
        printf("i=%d pos=%d\r\n",i,pos);
    }
#if 0   //思路乱了。。。
    if(nonequal)    //全部元素不等于指定值
        return numsSize;
    else if(nochange && i == 1) //全部元素等于指定值
        return 0;
    else if((nochange && nums[numsSize-1] != nums[numsSize-2]))
        return --i;

    if(i > pos)
        return --i;
#endif
    if(count)   //换过
    {
        return numsSize-count;
    }
    else    //没换过
    {
        if(nums[0] == val)     //全部元素等于指定值
            return 0;
        else if(nums[numsSize-1] == val)   //只有最后一个元素等于指定值
            return numsSize-1;
        else    //全部元素不等于指定值
            return numsSize;
    }
}


// @lc code=end

