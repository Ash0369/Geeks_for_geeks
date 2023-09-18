class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        return __builtin_popcountll(n)==1;    
        
    }
};
