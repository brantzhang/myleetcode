/*
Valid Parentheses 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
//**************************

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        char temp=' ';
        for(int i=0;i<s.length();i++){
            if(charStack.empty()){
                charStack.push(s[i]);
            } else {
                if(s[i]=='('||s[i]=='['||s[i]=='{'){
                    charStack.push(s[i]);
                } else {
                    temp = charStack.top();
                    if((temp=='('&&s[i]==')')||(temp=='['&&s[i]==']')||(temp=='{'&&s[i]=='}')){
                        charStack.pop();
                    }else{
                        charStack.push(s[i]);
                    }
                }
            }
        }
        if(charStack.empty())  return true;
        return false;
    }
};
