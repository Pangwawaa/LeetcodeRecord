/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start


bool isValid(char * s){

    if(s == NULL)
        return false;
    else if(!strcmp(s,""))
        return true;

    int pos = 0;
    int lpos = 0;
    int rpos = 0;
    int len = strlen(s);
    char *p = malloc(len+1);
    strcpy(p,s);
    char *pleft = malloc(len);
    //不需要为右括号分配存储空间
    //char *pright = malloc(len);

    while (pos < len)
    {
        printf("%d\r\n",*(p + pos));
       if(*(p + pos) == '(' || *(p + pos) == '{' ||
            *(p + pos) == '[')
        {
            *(pleft + lpos) = *(p + pos);
            printf("%d\r\n",*(pleft + lpos));
            pos++;
            lpos++;
            //pleft++;
        }
        else
        {
            //printf("\r\np = %d pl = %d",*(p + pos),*(pleft + lpos -1));
            //没考虑到1)第一个就是右括号 2)最后右括号多于左括号
            if(!pos || !lpos)
                return false;    
            else if((*(p + pos) - *(pleft+ lpos -1)) == 1 ||
                (*(p + pos) - *(pleft+ lpos -1)) == 2)
            {               
                printf("\r\nin if");
                pos++;
                lpos--;
                rpos++;
                //pleft = '\0';
            }
            else
                return false;
        }
    }
    //没考虑到1)全是左括号 2)最后左括号小于右括号
    if(!rpos || lpos)
        return false;
    
    return true;
}


// @lc code=end

