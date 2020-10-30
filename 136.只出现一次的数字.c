/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
typedef struct 
{
    int val;
    int flag;
    struct listnode *next;
} listnode;

int singleNumber(int* nums, int numsSize){

    listnode *head;
    listnode *ptr;
    listnode *ptrr;
    int flag;
    for (int i = 0; i < numsSize; i++)
    {
        flag = 0;
        ptr = head;
        if(i == 0)
        {
            ptr = malloc(sizeof(listnode));
            ptr->val = nums[i];
            ptr->next = NULL;
            ptr->flag = 0;
            head = ptr;
        } else {
            while(ptr)
            {
                if(nums[i] == ptr->val)
                {
                    ptr->flag = 1;
                    ptr = NULL;
                    flag = 1;
                } else {
                    ptr = ptr->next;
                }
            }
            if(!flag)
            {
                ptrr = malloc(sizeof(listnode));
                ptrr->val = nums[i];
                ptrr->next = head;
                ptrr->flag = 0;
                head = ptrr;
            }
        }
    }

    ptr = head;
    while(ptr)
    {
        if(ptr->flag)
        {
            ptr = ptr->next;
        } else {
            return ptr->val;
        }
    }
    
    return -1;
}


// @lc code=end

