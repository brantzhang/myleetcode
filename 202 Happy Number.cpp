/*202 Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
class Solution {
public:
    unordered_map<int,int> umap;
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        if(umap.find(n)==umap.end()){
            umap[n] = 1;
            int temp1,temp2,temp3;
            temp1 = n;
            temp3 = 0;
            while(temp1!=0){
                temp2 = temp1%10;
                temp3 = temp3 + temp2*temp2;
                temp1 = temp1/10;
            }
            return isHappy(temp3);
        }else{
            return false;
        }
    }
};