/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){

    int retlen,tmplen;
    char *p_str = s;
    char *p_ret = s;
    bool isDuplicate = false;

    while(*p_str != '\0')
    {
        int i;
        while (i < tmplen)
        {
            if(*p_str == *(p_ret + i++))
            {
                isDuplicate = true;
                break;
            }
        }

        if(isDuplicate)
        {
            i > (tmplen - i) ?( retlen = i) : (retlen = tmplen - i);
            if(i > retlen)
                retlen = i;
            tmplen = 0;
        } else {
            p_str++;
            tmplen++;
        }
        if(*p_str != *(p_str+1))
        {
            p_str++;
            tmplen++;
        } else {
            if(tmplen > retlen)
                retlen = tmplen;
            tmplen = 0;
            p_ret = p_str;
        }
    }

}
// @lc code=end

