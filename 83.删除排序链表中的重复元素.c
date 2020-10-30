/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct  {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head){

    if(!head)
        return head;

    ListNode* pnode = head->next;
    ListNode* phead = head;

    while (pnode)
    {
        while(pnode && (pnode->val == phead->val))
        {
            pnode = pnode->next;
        }
        if(pnode == NULL)
        {
            phead->next = NULL;
            break;
        }
        if(phead->next != pnode)
        {
            phead->next = pnode;
        }
        pnode = pnode->next;
        phead = phead->next;
    }
    
    return head;
}


// @lc code=end

