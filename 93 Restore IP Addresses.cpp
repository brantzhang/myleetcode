/*
93	Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:
    vector<string> res;
    bool judge(string s, int start,int end){
    	int temp = 0;
    	if((end-start)>0){
    		if(s[start]=='0'){
    			return false;
    		}
    	}
    	if((end-start)>2){
    		return false;
    	}
    	for(int i=start;i<=end;i++){
    		temp = temp*10+ s[i]-'0';
    	}
    	if(temp>=0&&temp<=255){
    		return true;
    	}
    	return false;
    }
    void dfs(string s, int pos, int num){//从位置pos开始判断字符串s，目前已经有num个点了 
    	if(num == 3){
    		if(judge(s,pos,s.size()-1)){
    			if(s[s.size()-1]=='.'){
    				return ;
    			}
    			res.push_back(s);
    		}
    		return;
    	}
    	for(int i=0;i<3&&i<(s.size()-pos);i++){
    		if(judge(s,pos,pos+i)){
    			string temp = s;
    			temp.insert(pos+i+1,".");
    			dfs(temp,pos+i+2,num+1); 
    		}
    	}
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,0);
	    return res;
    }
};