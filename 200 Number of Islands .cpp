/*
200 Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/
class Solution {
public:
    int judge(vector<vector<char>> &grid, int x, int y,int m, int n){
        if(grid[x][y]=='1'){
            grid[x][y] = '#';
        }else{
            return 0;
        }
        int up,down,left,right;
        up = down = left = right = 0;
        if(x-1>-1&&x-1<m){//向上判断
            up = judge(grid,x-1,y,m,n);
        }
        if(x+1>-1&&x+1<m){//向下判断
            down = judge(grid,x+1,y,m,n);
        }
        if(y-1>-1&&y-1<n){//向左判断
            left = judge(grid,x,y-1,m,n);
        }
        if(y+1>-1&&y+1<n){//向右判断
            right = judge(grid,x,y+1,m,n);
        }
        return up+down+left+right;
    }
    
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();   //行
        if(m==0){
            return 0;
        }
        int n = grid[0].size();  //列
        int counts = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    judge(grid,i,j,m,n);
                    counts++;
                }
            }
        }
        return counts;
    }
};
