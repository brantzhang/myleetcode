/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> hashtable;
        int count=0,temp=0,max=1;
        for(int i=0;i<num.size();i++){
            hashtable[num[i]] = i;
        }
        
        for(int i=0;i<num.size();i++){
            temp=0;
            count=1;
            
            temp = num[i]+1;
            while(hashtable.find(temp)!=hashtable.end()){
                count++;
                hashtable.erase(temp);
                temp++;
            }
            
            temp = num[i]-1;
            while(hashtable.find(temp)!=hashtable.end()){
                count++;
                hashtable.erase(temp);
                temp--;
            }
            
            if(count>max) max = count;
        }
        
        return max;
        
    }
};