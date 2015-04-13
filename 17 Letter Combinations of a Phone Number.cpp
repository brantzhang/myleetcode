/*
17 Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> res;
    void find(string left,string right){
        if(right.length()==0){
            res.push_back(left);
            return;
        }
        char cc = right[0];
        string temp = right.erase(0,1);
        
        char ca='a';
        int ii=3;
        if(cc=='7'||cc=='9'){
            ii = 4;
        }
        if(cc>'7'){
            ca='b';
        }
    
        for(int i=0;i<ii;i++){
            char c1 = (cc-'2')*3+ca+i;
            string temp2 = left+c1;
            find(temp2,temp);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return res;
        }
        find("",digits);
        return res;
    }
};