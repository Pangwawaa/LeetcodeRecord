/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start


char * addBinary(char * a, char * b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int len = 0;
    int restlen = 0;
    int tmp = 0;
    char *ptrl = NULL;
    char *retStr;
    char *ptrr = NULL;
    char *ptra = a + lena;
    char *ptrb = b + lenb;
    
    if(lena < lenb)
    {       
        len = lena;
        restlen = lenb - lena;
        ptrl = b + restlen - 1;
        retStr = malloc(lenb*sizeof(char) + 2);
        ptrr = retStr + lenb + 1;
    } else {
        len = lenb;
        restlen = lena - lenb;
        ptrl = a + restlen - 1;
        retStr =  malloc(lena*sizeof(char) + 2);
        ptrr = retStr + lena + 1;
    }
    
    *ptrr = '\0';

    while(len)
    {
        printf("%c %c %c\r\n",*ptra,*ptrb,*ptrr);
        ptrr--;
        ptrb--;
        ptra--;

        if(*ptra == '1' && *ptrb == '1')
        { 
            if(tmp)
                *ptrr = '1';
            else
            {
                *ptrr = '0';
                tmp = 1;
            }
        } else if(*ptra == '1' || *ptrb == '1') {
            if(tmp)
                *ptrr = '0';
            else
                *ptrr = '1';
        } else {
            if(tmp)
            {
                *ptrr = '1';
                tmp = 0;
            }
            else
                *ptrr = '0';
        }
        len--;
    }

    while(restlen)
    {
        ptrr--;
        if(*ptrl == '1')
        {
            if(tmp)
            {
                *ptrr = '0';
                ptrl--;
                restlen--;
            } else
                break;
        } else {
            if(tmp)
            {
                *ptrr = '1';
                ptrl--;
                restlen--;
                tmp = 0;
            }                    
            break;
        }
    }

    if(tmp)
    {
        *retStr = '1';
        return retStr;
    }

    if(restlen)
    {
        memcpy(retStr+1,ptrl-restlen+1,restlen);
        return retStr + 1;
    }

    return retStr + 1;
}
// @lc code=end