/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 */

// @lc code=start


int strStr(char * haystack, char * needle){

    //注意怎么判断字符串为空字符串
    if(*needle == '\0')
        return 0;

    int len_needle = strlen(needle);
    int len_haystack = strlen(haystack);
    char *p1 = haystack;
    int count = 0;

    while(count <= len_haystack - len_needle)
    {
        if(!strncmp(p1,needle,len_needle))
            return count;
        else
        {
            p1++;
            count++;
        }
    }
    
    return -1;
}


// @lc code=end

