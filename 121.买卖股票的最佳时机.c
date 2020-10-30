/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
//Fail testcase [1,2]
//Fail testcase [4,2,1,7]

int maxProfit(int* prices, int pricesSize){

    if(pricesSize == 0)
        return 0;

    int in = prices[0];
    int out = prices[0];
    int profit = out - in;

    for(int i = 1;i < pricesSize;i++)
    {
        if(prices[i] > out)
        {            
            out = prices[i];
        } else if(prices[i] < in) {
            in = prices[i];
            out = prices[i];
        }
        if(profit < out - in)
            profit = out -in;
    }

    if(profit > 0)
        return profit;
    else
        return 0;
}
// @lc code=end

