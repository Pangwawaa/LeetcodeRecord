/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    if(!l1 && !l2)
        return NULL;
    
    struct ListNode *pl1,*pl2,*head,*p;
    int sum,flag = 0;
    pl1 = l1;
    pl2 = l2;
    
    while(pl1 && pl2)
    {
        struct ListNode *tank = malloc(sizeof(struct ListNode));
        sum = pl1->val + pl2->val;
  
        if(sum > 9 && flag == 0)
            flag = 1;
        else if(flag)
        {
            sum += 1;
            if(sum < 10)
                flag = 0;
        }
        tank->val = sum % 10;
        tank->next = NULL;
        if(pl1 == l1)
        {    
            head = tank;
            p = tank;
        } else {
            p->next = tank;
            p = p->next;
        }
            
        pl1 = pl1->next;
        pl2 = pl2 ->next;
    }


    if(!pl1 && !pl2)
    {
        if(flag)
        {
           struct ListNode *tank = malloc(sizeof(struct ListNode));
            tank->val = 1;
            tank->next = NULL;
            p->next = tank;
        }
    } else {
        if(pl1)
            pl2 = pl1;

        while(pl2)
        {
            struct ListNode *tank = malloc(sizeof(struct ListNode));
            if(flag)
            {
                if(pl2->val == 9)
                    tank->val = 0;
                else
                {
                    tank->val = pl2->val + 1;
                    flag = 0;
                }
            } else {
                tank->val = pl2->val;
            }
                
            tank->next = NULL;
            p->next = tank;
            p = p->next;
            pl2 = pl2->next;
        }

        if(flag)
        {
           struct ListNode *tank = malloc(sizeof(struct ListNode));
            tank->val = 1;
            tank->next = NULL;
            p->next = tank;
        }
    }
    return head;

}


// @lc code=end

