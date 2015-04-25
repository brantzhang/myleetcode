/*
62 Unique Paths 
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1&&n==1){
            return 1;
        }
       int** pp = new int*[m];
        for(int i=0;i<m;i++){//构造二维数组
            pp[i] = new int[n];
        }
        for(int i=0;i<m;i++){//使用动态规划，每个格子的路径数等于上面的格子的值加上左边的格子的值。
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    if(i==j){
                        pp[i][j]=0;
                    }else{
                        pp[i][j] = 1;
                    }
                    continue;
                }
                pp[i][j] = 0;
                if(i-1>-1){
                    pp[i][j] = pp[i-1][j];
                }
                if(j-1>-1){
                    pp[i][j]+=pp[i][j-1];
                }
            }
        } 
        return pp[m-1][n-1];
    }
};
