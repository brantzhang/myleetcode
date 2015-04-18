/*
Bitwise AND of Numbers Range Total
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
For example, given the range [5, 7], you should return 4.
Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
****************/
//�����������а�λ�룬���ս�����ǿ���ߵ������λ�����������ƣ�ֱ��m==n,��ʱʣ�µľ��������λ���������ƻ�ָ��λ�ü���
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int temp=0;
        while(m!=n){
            m = m>>1;
            n = n>>1;
            temp++;
        }
        return m<<temp;
    }
};
