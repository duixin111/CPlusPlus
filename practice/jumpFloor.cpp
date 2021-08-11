class Solution {
public:
    int jumpFloor(int number) {
        
        if(number == 1)
            return 1;
        
        int a = 1, b = 1, c;
        for(int i = 2; i <= number; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
