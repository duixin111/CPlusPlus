class Solution {
public:
    int Fibonacci(int n)
    {
        if(n == 0 || n == 1)
            return n;
        int prev = 0;
        int cur = 1;
        int value;
        for(int i = 2; i <= n; i++)
        {
            value = prev + cur;
            prev = cur;
            cur = value;
        }
        
        return value;
    }
};
