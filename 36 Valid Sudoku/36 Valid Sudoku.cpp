/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;i++){
            map<char,int> hashtable;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    if(hashtable.find(board[i][j]) != hashtable.end()) return false;
                    hashtable[board[i][j]]=j;
                }
            }
            map<char,int> hashtable2;
            for(int j=0;j<9;j++){
                if(board[j][i] != '.'){
                    if(hashtable2.find(board[j][i]) != hashtable2.end()) return false;
                    hashtable2[board[j][i]]=j;
                }
            }
            
        }
        
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,int> hashtable3;
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(board[i+a][j+b] != '.'){
                            if(hashtable3.find(board[i+a][j+b]) != hashtable3.end()) return false;
                            hashtable3[board[i+a][j+b]]=j;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};