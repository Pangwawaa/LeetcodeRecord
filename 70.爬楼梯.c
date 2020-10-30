/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start


int climbStairs(int n){

    int ret = 1;
    int count = n/2;
    double jn = 1;
    double jnm = 1;
    int m;
    int nm;
    int nn;
    int tmp;
    count = n/2;

    while (count > 0)
    {
        nn = n - count;
        m = count;
        nm = nn - m;
        
        if(m < nm)
        {    
            tmp = nm;
            nm = m;
            m = tmp;
        }

        while(nn > m)
        {
            jn *= nn;
            nn--;
        }

        while(nm > 0)
        {
            jnm *= nm;
            nm--;
        }

        ret += (jn / jnm);
        jn = 1;
        jnm = 1;
        count--;
    }
    
    return ret;
}
// @lc code=end

