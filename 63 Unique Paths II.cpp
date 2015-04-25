/*
63 Unique Paths II 
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(m==1&&n==1){
            if(obstacleGrid[0][0]==0)
                return 1;
            else
                return 0;
        }
       int** pp = new int*[m];
        for(int i=0;i<m;i++){//�����ά����
            pp[i] = new int[n];
        }
        for(int i=0;i<m;i++){//ʹ�ö�̬�滮��ÿ�����ӵ�·������������ĸ��ӵ�ֵ������ߵĸ��ӵ�ֵ��
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1){//������ϰ���ֱ�Ӹ�ֵΪ0��˵����·��ͨ
                    pp[i][j] = 0;
                    continue;
                }
                if(i==0&&j==0){
                    pp[i][j] = 1;
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