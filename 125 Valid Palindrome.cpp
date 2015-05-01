/*
125 Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0){
            return true;
        }
        int i=0;
        int j=s.size()-1;
        char ci,cj;
        bool iflag,jflag,res;
        res = true;
        while(i<=j){
            iflag = jflag = true;
            if(s[i]>='a'&&s[i]<='z'){
                ci = s[i];
            } else if(s[i]>='A'&&s[i]<='Z'){
                ci = s[i]-'A'+'a';
            } else if(s[i]>='0'&&s[i]<='9'){
                ci = s[i];
            } else{
                iflag = false;
                i++;
            }
            if(s[j]>='a'&&s[j]<='z'){
                cj = s[j];
            } else if(s[j]>='A'&&s[j]<='Z'){
                cj = s[j]-'A'+'a';
            } else if(s[j]>='0'&&s[j]<='9'){
                cj = s[j];
            }else{
                jflag = false;
                j--;
            }
            if(iflag&&jflag){
                if(ci != cj){
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};