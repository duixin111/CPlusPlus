class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    map<int, int> m;
        for(const int val : numbers)
            ++m[val];
        for(const int val : numbers)
        {
            if(m[val] > numbers.size() / 2)
                return val;
        }
        return 0;
    }
};
