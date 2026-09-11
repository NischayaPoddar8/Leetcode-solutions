class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag = false;
        if(n==1) {
            flag=true;
            return flag;
        }
        if(n%2!=0 || n<=0){ // for odd numbers and negative numbers
            return flag;
        }
        return isPowerOfTwo(n/2);
    }
};