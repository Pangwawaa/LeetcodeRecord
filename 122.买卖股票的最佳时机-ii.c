/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){

    int in = prices[0];
    int out = 0;
    int profit = 0;

    for(int i = 0;i < pricesSize;i++)
    {
        if(prices[i] < out)
        {
            profit += out - in;
            in = prices[i];
            out = 0;   
        } else if(out == 0) {
            if(prices[i] <= in)
                in = prices[i];
            else
                out = prices[i];
        } else {
            out = prices[i];
        }
    }
    
    if(out != 0)
        profit += out - in;

    return profit;
}
// @lc code=end

