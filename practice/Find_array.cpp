class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if(m == 0)
            return false;
        int n = array[0].size();
        if(n == 0)
            return false;
        int r = 0;
        int c = n - 1;
        while(r < m && c >= 0)
        {
            if(target == array[r][c])
                return true;
            else if(target > array[r][c])
                ++r;
            else
                --c;
        }
        return false;
    }
};
