/* Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
*/
//O(n)f复杂度
class Solution {
public: 
    int maxSubArray(int A[], int n) {
        int sum=A[0];
        int cursum=0;
        
        for(int i=0;i<n;i++){
            cursum+=A[i];
            if(cursum>sum){
                sum = cursum;
            }
            if(cursum<0){
                cursum=0;
            }
        }
        return sum;
    }
};

//分治策略，O(n*log(n)复杂度，会超时，但可以借鉴其思路
class Solution {
public: 
    int cross(int A[],int low,int high){
        int mid = (high-low)/2;
        int start,end,sum,leftsum,rightsum;
        leftsum =A[mid],sum=0,start=mid;
        for(int i=mid;i>(low-1);i--){
            sum+=A[i];
            if(sum>leftsum){
                start = i;
                leftsum = sum;
            }
        }
        rightsum =A[mid],sum=0,end=mid;
        for(int i=mid;i<(high+1);i++){
            sum+=A[i];
            if(sum>rightsum){
                end = i;
                rightsum = sum;
            }
        }
        return leftsum+rightsum-A[mid];
    }
    int find(int A[],int low,int high){
        if(high==low){
            return A[low];
        }
        int mid = (high+low)/2;
        int max1,max2,max3;
        max1 = find(A,low, mid);
        max2 = find(A,mid+1,high);
        max3 = cross(A,low,high);
        int max = max1;
        if(max<max2) max=max2 ;
        if(max<max3) max=max3 ;
        return max;
    }
    
    int maxSubArray(int A[], int n) {
        return find(A,0,n-1);
    }
};