class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 找缺失数字
     * @param a int整型vector 给定的数字串
     * @return int整型
     */
    int solve(vector<int>& a) {
        // write code here
        int i = 0;
        int j = a.size() - 1;
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if(a[mid] == mid)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};
