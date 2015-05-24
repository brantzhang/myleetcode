/*
Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/
class Solution {
public:
    string dfs(string s,int counts,int n){
        if(counts==n){
            return s;
        }
        int len = s.size();
        int coun=0;
        int temp1,temp2;
        temp1 = s[0]-'0';
        coun++;
        string res;
        char cc;
        for(int i=1;i<len;i++){
            temp2 = s[i]-'0';
            if(temp1==temp2){
                coun++;
                continue;
            } else {
            	cc = coun+'0';
                res = res+cc;
                cc = temp1+'0';
                res = res+cc;
                temp1 = temp2;
                coun = 1;
            }
        }
        cc = coun+'0';
        res = res+cc;
        cc = temp1+'0';
        res = res+cc;
        string res2 = dfs(res,counts+1,n);
        return res2;
    }
    string countAndSay(int n) {
        
        string res = dfs("1",1,n);
        return res;
    }
};