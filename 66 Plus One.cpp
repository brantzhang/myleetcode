/*
Plus One 
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
�����������һ�����������һ֮�������
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(digits[len-1]!=9){
            digits[len-1]+=1;
            return digits;
        }
        int jinwei = 1;//��λ��Ϣ;
        int count =  len-1;
        while(jinwei==1&&count>=0){
            jinwei = (digits[count]+1)/10;
            digits[count] = (digits[count]+1)%10;
            count--;
        }
        if(jinwei!=0){
            digits.insert(digits.begin(),jinwei);
        }
        return digits;
    }
};