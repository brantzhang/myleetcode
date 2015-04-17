/*
Maximum Product Subarray 

Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==1){return A[0];}
        int curMax = A[0];
        int curMin = A[0];
        int Globalmax = A[0];
        int temp;
        for(int i=1;i<n;i++){
            temp = curMax;
            curMax = max(max(curMax*A[i],A[i]),curMin*A[i]);
            curMin = min(min(temp*A[i],A[i]),curMin*A[i]);
            Globalmax = max(curMax,Globalmax);
        }
        return Globalmax;
    }
};