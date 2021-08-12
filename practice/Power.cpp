class Solution {
public:
    double Power(double base, int exponent) {
        double ret = base;
        if(exponent < 0)
        {
            while(++exponent)
            {
                ret *= base;
            }
            ret = 1 / ret;
        }
        
        else if(exponent == 0)
            ret = 1.0;
        else
        {
            while(--exponent)
            {
                ret *= base;
            }
        }
        return ret;
    }
};
