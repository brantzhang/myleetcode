/*String to Integer (atoi)
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/class Solution {
public:
    int myAtoi(string str) {
        if(str=="") return 0;
        int length = str.length();
        int temp;
        long long res=0L;
        long aa =1;
        int i=0;
        while(str[i]==' '){
            i++;
        }
        if(str[i]=='-') {
            aa=-1;
            i++;
        }else if(str[i]=='+'){
            i++;
        }
        if(length>1&&(str[i]=='+'||str[i]=='-')){
            if(str[i-1]=='-'&&str[i]=='+') return 0;
            if(str[i-1]=='+'&&str[1]=='-') return 0;
        }
        for(;i<length;i++){
            temp = str[i]-'0';
            if(temp<0||temp>9) break;
            if(res>INT_MAX||res<INT_MIN){
                if(aa==-1) return INT_MIN;
                return INT_MAX;
            }
            res = res*10+temp;
        }
        res = res*aa;
        if(res>INT_MAX)return INT_MAX;
        if(res<INT_MIN)return INT_MIN;
        return res;
    }
};