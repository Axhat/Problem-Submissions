class Solution {
public:
    bool isPowerOfFour(int n) {
        
        //return __builtin_popcount(num)==1 && // only 1 bit is set
        //      (__builtin_ctz(num)&1)==0;
        
        return __builtin_popcount(n)==1 && (__builtin_ctz(n)&1)==0;
       
    }
};