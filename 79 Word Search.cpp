/*
79 Word Search
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
     bool dfs79(vector<vector<char> > &board, vector<vector<bool> > &bit, string word, string &foundS, int x, int y){
    if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && bit[x][y] == false && board[x][y] == word[foundS.size()]){
		foundS += board[x][y];
		bit[x][y] = true;
    }else 
		return false;
    if (foundS.size() == word.size()) return true;
    
    if (dfs79(board, bit, word, foundS, x, y-1)) return true;
    if (dfs79(board, bit, word, foundS, x-1, y)) return true;
    if (dfs79(board, bit, word, foundS, x, y+1)) return true;
    if (dfs79(board, bit, word, foundS, x+1, y)) return true;
    bit[x][y] = false;
    foundS = foundS.substr(0, foundS.size() - 1);
    return false;
  }
  bool exist(vector<vector<char> > &board, string word) {
	int row = board.size();
    if (row == 0) return false;
    int col = board[0].size();
    
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++){
        if (board[i][j] == word[0]){
           string foundS = "";
           vector<vector<bool> > bit(row, vector<bool>(col)); // 初始化都为false
           if (dfs79(board, bit, word, foundS, i, j)) return true;
         }
      }
    return false;
  }
};