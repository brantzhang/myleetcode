/*
121 Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int max = 0;
        int temp = 0;
        for(int i=1;i<prices.size();i++){
            temp+=(prices[i]-prices[i-1]);
            if(temp>max){
                max = temp;
            }
            if(temp<=0){
                temp = 0;
            }
        }
        return max;
    }
};