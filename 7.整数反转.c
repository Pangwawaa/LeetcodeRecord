/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start
int reverse(long int x){

    long int retnum = 0;
    long int d = 10000000000;    //10^10
    long int b = 0;
    //int c=10;
    int token = 1;

    if(x == 0)
        return 0;
    else if(x < 0)
    {
        token = -1;
        x *= -1;
    }
        
#if 0
    while ((d > 1) && (b == 0))
    {
        d = d/10;
        b = x/d;
        c--;
    };
    
    if(d == 1)
        return x;
    else
    {
        while (d > 1)
        {
            if(d == 10)
            {
                retnum += (x%d)*d;
                retnum += x/d;
            }
            else
            {
                retnum += (x % (d/10)) * d;
            }
            d = d/10;
            x = x/d;
        }
    }
#endif

    while ((d > 1) && (b == 0))
    {
        d = d/10;
        b = x/d;
    };

    if (d == 1)
    {
        return token * x;
    }
    
    while (d >= 1)
    {
        retnum += (x%10)*d;
        x = x/10;
        d = d/10;
    };
    retnum = token * retnum;

    if((retnum < -2147483648) || (retnum > 2147483647))
        return 0;
    
    return retnum;
}


// @lc code=end