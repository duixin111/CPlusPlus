class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int e : nums)
        ret ^= e;
        int div = 1;
        while((div & ret) == 0)
        div <<= 1;
        int a = 0, b = 0;
        for(int e : nums)
        {
            if(div & e)
            a ^= e;
            else
            b ^= e;
        }
        return vector<int>{a,b};
    }
};
