/*
188 Best Time to Buy and Sell Stock IV
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k>=prices.size()){//当尝试次数超过prices的个数时，问题可以转换成了无数次买卖的情况。
            int maxP=0;
            for(int i=1;i<prices.size();i++){
                if(prices[i]>prices[i-1]){
                    maxP = maxP + (prices[i]-prices[i-1]);
                }
            }
            return maxP;
        }
        int* sell = new int[k];
        int* buy = new int[k];
        for(int i=0;i<k;i++){
            buy[i] = INT_MIN;
            sell[i] = 0;
        }
        for(int i=0;i<prices.size();i++){
            for(int j=(k-1);j>=0;j--){
                sell[j] = max(sell[j],buy[j]+prices[i]);
                if(j==0){
                    buy[j] = max(buy[j],-prices[i]);
                }else{
                    buy[j] = max(buy[j],sell[j-1]-prices[i]);
                }
            }
        }
        return sell[k-1];
    }
};