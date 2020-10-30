/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 */

// @lc code=start
//不能采用 a < b < c 的表达方式
//strlen不算\0

bool isPalindrome(char * s){
    char *front = s;
    char *back = s + strlen(s) - 1;

    while(front < back)
    {
        if(!((*front > 47 && *front < 58) || (*front > 64 && *front < 91) || (*front > 96 && *front < 123)))
        {
            front++;
            continue;
        } else if (!((*back > 47 && *back < 58) || (*back > 64 && *back < 91) || (*back > 96 && *back < 123))) {
            back--;
            continue;
        } else if (*front == *back || (*front - *back == 32 && *back > 64) || (*back - *front == 32 && *front > 64)){
            front++;
            back--;
        } else {
            return false;
        }
    }

    return true;
}
// @lc code=end

