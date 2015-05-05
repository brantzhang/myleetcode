/*
205 Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.size()!=t.size()){
        return false;
        }
        int len = s.size();
        unordered_map<char,char> smap;
        unordered_map<char,char> tmap;
        //将s中的字符与t中的字符依次进行一一map，主要考虑重复出现的字符不能对应不同的字符 
    	//s中的一个字符不能映射到t中的多个字符，t中的一个字符也不能映射到s中的多个字符 
        for(int i=0;i<len;i++){
        	if(smap.find(s[i])!=smap.end()){
        		if(smap[s[i]]!=t[i]){
        			return false;
    			}
    			continue;
    		}
            smap[s[i]] = t[i];
        }
        for(int i=0;i<len;i++){
        	if(tmap.find(t[i])!=tmap.end()){
        		if(tmap[t[i]]!=s[i]){
        			return false;
    			}
    			continue;
    		}
            tmap[t[i]] = s[i];
        }
        return true;
    }
};