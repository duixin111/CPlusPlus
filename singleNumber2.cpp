class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> q;
        for(int num: nums)
        ++q[num];
        for(auto [num, occ] : q)
        {
            if(occ == 1)
            {
                return num;
                break;
            }
        }
        return -1;
    }
};
