/*
198	House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
//solution 1 使用动态规划
class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(n==0) return 0;
        int * maxArray = new int[n];
        maxArray[0] = num[0];
        for(int i=1;i<n;i++){
            if(i==1){
                num[1]>num[0]?maxArray[1]=num[1]:maxArray[1]=num[0];
                continue;
            }
            maxArray[i] = maxArray[i-2]+num[i];
            if(maxArray[i]<maxArray[i-1]){
                maxArray[i]=maxArray[i-1];
            }
        }
        return maxArray[n-1];
    }
};

//使用递归
class Solution {
public:
    int ddd(vector<int> &num,int n){
        if(n<=0){
            return 0;
        }
        int res1 = ddd(num,n-1);
        int res2 = ddd(num,n-2)+num[n-1];
        return res1>res2?res1:res2;
    }
    int rob(vector<int> &num) {
        return ddd(num,num.size());
    }
};
