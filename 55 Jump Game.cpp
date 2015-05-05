/*
55 Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/
class Solution {  
public:
    bool canJump(vector<int>& nums) {
	//从第一个数字开始依次往后比较，并维持一个最大步数的变量，
         int n = nums.size();
         if(n==0||n==1){
             return true;
         }
         int maxStep = nums[0];
         for(int i=1;i<n;i++){
            if(maxStep == 0){
                return false;
            }
            maxStep--;  //和下一个数字进行比较
            if(maxStep < nums[i]){
                maxStep = nums[i];
            }
            if((maxStep+i)>=n-1){
                return true;
            }
         }
    }
};