/*
3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, int target,int temp, int low,int high) {
        int i=low,j=high;
        int ttt = target-temp;
        while(low<high){
            if(low>i&&nums[low]==nums[low-1]){//去除重复的情况
        		low++;
        		continue;
    		}
    		if(high>j&&nums[high]==nums[high+1]){//去除重复的情况
        		high--;
        		continue;
    		}
        	if((nums[low]+nums[high])==ttt){
        	    vector<int > res;
        		res.push_back(temp);
        		res.push_back(nums[low]);
        		res.push_back(nums[high]);
        		result.push_back(res);
        		low++;
    		}
    		if((nums[low]+nums[high])>ttt){
        		high--;
    		}
    		if((nums[low]+nums[high])<ttt){
        		low++;
    		}
    	}
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int temp=0,target=0;
    	sort(nums.begin(),nums.end());
    	int len = nums.size();
    	for(int i=0;i<len;i++){
    		if(i>0&&nums[i]==nums[i-1]){//去除重复的情况
    			continue;
    		}
    		temp = nums[i];
    		twoSum(nums,target,temp,i+1,len-1);
    	}
    	return result;
    }
};