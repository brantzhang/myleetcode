/*
1 Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map1;  //Ê¹ÓÃunorder_map´úÌæhash_map
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(map1.find(target-nums[i]) != map1.end()){
                res.push_back(map1[target-nums[i]]);
                res.push_back(i+1);
                break;
            }else{
                map1[nums[i]] = i+1;
            }
        }
        return res;
    }
};