/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 外观数列
 */

// @lc code=start


char * countAndSay(int n){

    //省略malloc错误处理
    char *tmp = (char *) malloc(1024*10);
    char *ret = (char *) malloc(1024*10);
    
    /* 字符串赋值错误，这样是指向常量区
     * 导致后面给指针赋值时，出现AddressSanitizer:DEADLYSIGNAL
     * 因为给在给常量区赋值是违法的 */
    //tmp = "1";
    strcpy(ret,"1");
    /* 防止内存泄漏，通过指针操作动态分配的内存区域
     * 而不是直接对地址（tmp，ret）操作 */
    char *p,*ptmp;
    int count = 1;

    if(n == 1)
        return ret;

    //注意循环边界条件
    for(int i=1;i < n;i++)
    {
        p = ret;
        ptmp = tmp;
        while(*p != '\0')
        {
            while(*p == *(p+1))
            {
                count++;
                p++;
            }
            *ptmp = count + 48;
            *(++ptmp) = *p;
            ptmp++;
            count = 1;
            p++;
        }       
        *ptmp = '\0';
        strcpy(ret,tmp);       
    }
    
    return ret;
}


// @lc code=end

