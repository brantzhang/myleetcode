/* Minimum Window Substring Total Accepted: 34996 Total Submissions: 185364 My Submissions Question Solution 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include<iostream>
using namespace std;

string minWindow(string s, string t) {
    int hashS[256] = {0};
    int hashT[256] = {0};
    int start = 0, end = 0;
    int startR = -1, endR = -1;
    int i=0;
    int suc = 0;
    int len = t.length();
    string res="";
    while(i<t.length()){
    	hashT[t[i++]] ++;
    }
    while(start<s.length()&&hashT[s[start]]==0){
    	start++;
    }
    if(start<s.length()){
    	end = start;
    }else{
    	return "";
    }
    while(1){
    	if(end==s.length()){
    		if(endR==-1){
    		    return "";
    		}
    		return s.substr(startR,endR-startR+1);
    	}
    	if(hashT[s[end]]!=0){
    		if(hashS[s[end]]<hashT[s[end]]){
    			suc++;
    		}
    		hashS[s[end]]++;
    		if(suc==len){
    			if((endR-startR)!=0){
    				if ((endR-startR)>(end-start)){
    					endR = end;
    					startR = start;
    				}
    			}else{
    				endR = end;
    				startR = start;
    			}
    			//已经找到了一个窗口，下面开始从前面开始往后减小窗口的距离
				while(suc == len){
					if (hashT[s[start]]!=0){
						if(hashS[s[start]]==hashT[s[start]]){
							suc--;
							hashS[s[start]]--;
							start++;
							while(start<s.length()&&hashT[s[start]]==0){
								start++;
							}
							end++;
						}else{
							hashS[s[start]]--;
							start++;
							if((end-start) < (endR-startR)){
								startR = start;
								endR = end;
							}
						}
					}else{
						start++;
						if((end-start) < (endR-startR)){
							startR = start;
							endR = end;
						}
					}
				} 
    		}else{
    			end++;
    		}
    	}else{
    		end++;
    		
    	}
    }
}

int main(){
	string s = "a";
	string t = "a";
	cout<<minWindow(s,t)<<endl;
}
