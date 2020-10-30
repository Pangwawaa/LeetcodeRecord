/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if 0
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    if(!l1 || !l2)
    {
        if(!l1)
            return l2;
        else
            return l1;
    }

    //注意定义多个指针的方式
    struct ListNode *before,*p1,*p2,*head;
    before = l1;
    p1 = l1;
    p2 = l2;
    int flag = 1;
    if(l1->val <= l2->val)
        head = l1;
    else
        head = l2;
    
    while(p1 && p2)
    {
        //before = pl->next;
        if(p1->val >= p2->val)
        {
            //printf("\r\n# before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
            if(p1->val > p2->val && before == p1)
            //if(before == p1)
            {
                while(p2->next && flag)
                {                    
                    if(p1->val >= p2->next->val)
                        p2 = p2->next;
                    else
                        flag = 0;
                }
                printf("\r\n^ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
                before = p2;
                printf("\r\n1");
                before->next = p1;
                printf("\r\n2");
                p1 = p1->next;
                //before->next = p2;
                //before = p2;
                p2 = p2->next;
                printf("\r\n3");
                //before = before->next;
                
                //printf("\r\n^ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
                
            }
            else if(p1->val == p2->val && before == p1)
            {
                printf("\r\n# before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
                //before = p2;
                //before->next = p1;
                p1 = p1->next;
                before->next = p2;
                p2 = p2->next;
                before = before->next;
                before->next = p1;
                
                //before = before->next;
                
                //printf("\r\n# before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
            }
            else
            {
    #if 1
                printf("\r\n$ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
                before->next = p2;  //before 是p1前一个不为空
                printf("\r\n1");
                before = before->next;  //
                printf("\r\n2");
                p2 = p2->next;
                printf("\r\n3");           
                before->next = p1; //bug
                printf("\r\n4");               
                //p1 = p1->next;
                //printf("\r\n$ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
    #else
                printf("\r\n$ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
                before->next = p2;  //before 是p1前一个不为空
                before->next = p1; //bug
                before = before->next;  //
                p2 = p2->next;                       
                //p1 = p1->next;
                printf("\r\n$ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
    #endif
            }
            //printf("\r\n#p1=%d p2=%d",p1->val,p2->val);
        }
        else
        {

            {
                printf("\r\n@ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
                before = p1;
                p1 = p1->next;
                //printf("\r\n@ before=%d p1=%d p2=%d",before->val,p1->val,p2->val);
            }
        }
    }
    
    if(p2)
        before->next = p2;

    return head;
}
#endif
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    if(!l1 || !l2)
    {
        if(!l1)
            return l2;
        else
            return l1;
    }

    struct ListNode  *p1,*p2,*bf1,*head;
    p1=l1;
    bf1=l1;
    p2=l2;
    
    if(p1->val < p2->val)       //第一次移动
        head = p1;
    else
        head = p2;

    while(p1&&p2)
    {
        //以l1为基准
        if(p1->val < p2->val)     //不用插入
        {
            //printf("@ bf1=%d p1=%d p2=%d\r\n",bf1->val,p1->val,p2->val);
            if(bf1 == p1)       //第一次移动
            {
                p1 =p1->next;
            }
            else
            {
                bf1 = bf1->next;
                p1 = p1->next;
            }
            //printf("@ bf1=%d p1=%d p2=%d\r\n",bf1->val,p1->val,p2->val);
        }
        else       //p2需要插入p1
        {
            if(head == p2)       //第一次移动
            {
                //printf("$ bf1=%d p1=%d p2=%d\r\n",bf1->val,p1->val,p2->val);
                p2 = p2->next;
                head->next = p1;
                bf1 = head;
                //printf("$ bf1=%d p1=%d p2=%d\r\n",bf1->val,p1->val,p2->val);
            }
            else
            {
                //printf("# bf1=%d p1=%d p2=%d\r\n",bf1->val,p1->val,p2->val);
                bf1->next = p2;
                p2 = p2->next;
                bf1 = bf1->next;
                bf1->next = p1;
                //printf("# bf1=%d \r\n",bf1->val);
                //printf("# p1=%d \r\n",p1->val);
                //printf("# p2=%d \r\n",p2->val);
            }
        }
    }

    if(p2)
        bf1->next = p2;
    
    return head;
}
// @lc code=end

