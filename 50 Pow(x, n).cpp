/*50 Pow(x, n)
Implement pow(x, n).

Show Tags
Have you met this question in a real interview?
*/
class Solution {
public:
    double tPow(double x, int n){
        if(n==1){
            return x;
        }
        int left = n/2;
        int right = n-left;
        double resLeft = tPow(x,left);
        if(resLeft==0.0){
            return 0.0;
        }
        double resRight;
        if(left == right){
            resRight = resLeft;
        }else{
            resRight = resLeft*x;
        }
        return resLeft*resRight;
    }
    double myPow(double x, int n) {
        double res=1.0;
        if(n==0||x==1.0) return res;
        if(x==-1.0)  {
            if(n%2==0){
                return 1.0;
            }else {
                return -1.0;
            }
        }
        int nn;
        if(n<0){
            nn=-n;
        }else{
            nn=n;
        }
        res = tPow(x,nn);
        if(n<0){
            res = 1.0/res;
        }
        return res;
    }
};