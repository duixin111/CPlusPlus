class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        int* dp = new int[len];
        int max = array[0];
        dp[0] = array[0];
        for(int i = 1; i < len; ++i)
        {
            int tmp = array[i] + dp[i - 1];
            if(tmp > array[i])
                dp[i] = tmp;
            else
                dp[i] = array[i];
            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};
