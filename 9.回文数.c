/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


int isPalindrome(int x){

int isPalin = 1;
int notPalin = 0;
int up,low;
long int a = 100000000000;     //10^11

if(x == 0)
    return isPalin;
else if(x < 0)
    return notPalin;

while((a > 1) && (x/a == 0))
    a /= 10;

if(a == 1)          //个位数
    return isPalin;

while (a >= 1)
{
    if (a == 1)     //奇数位数
        return isPalin;
    
    up = x/a;
    low = x%10;

    if(up != low)
        return notPalin;

    if (a == 10)    //偶数位数
        return isPalin;
    else
    {
        x = (x - up*a)/10;      //去掉两端验过相等的数字
        a /=100;
    }
}

//确认每个控制流都有返回值
return notPalin;    //避免control reaches end of non-void function

}


// @lc code=end

