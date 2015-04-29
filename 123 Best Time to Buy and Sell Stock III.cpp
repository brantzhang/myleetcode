/*
123 Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/
class Solution {
public:
    void subArray1(vector<int>& prices,vector<int>& sinArr){
        if(prices.size()==1){
            sinArr.push_back(0);
        }
        int max =0;
        int temp = 0;
        sinArr.push_back(0);
        for(int i=1;i<prices.size();i++){
            temp+=(prices[i]-prices[i-1]);
            if(temp>max){
                max = temp; 
            }
            if(temp<=0){
                temp=0;
            }
            sinArr.push_back(max);
        }
    }
    void subArray2(vector<int>& prices,vector<int>& sinArr){
        if(prices.size()==1){
            sinArr.push_back(0);
        }
        int max =0;
        int temp = 0;
        sinArr.push_back(0);
        for(int i=(prices.size()-1);i>=0;i--){
            temp+=(prices[i-1]-prices[i]);
            if(temp<max){
                max = temp; 
            }
            if(temp>=0){
                temp=0;
            }
            sinArr.push_back(-max);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int maxP = 0;
        int temp = 0;
        vector<int> left;//´Ó0-n
        vector<int> right;//´Ón-0
        subArray1(prices,left);
        subArray2(prices,right);
        int n = left.size();
        for(int i=0;i<n;i++){
            if(maxP<(left[i]+right[n-1-i])){
                maxP = (left[i]+right[n-1-i]);
            }
        }
        return maxP;
    }
};