class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(k%n==0) return;
        int *bak;
        bak = (int*)malloc(n*sizeof(int));
        int real = k%n;
        for(int i=0;i<n;i++){
            bak[(i+real)%n] = nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i] = bak[i];
        }
        free(bak);
    }
};