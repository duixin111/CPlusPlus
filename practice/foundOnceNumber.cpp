class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr intvector 
     * @param k int 
     * @return int
     */
    int foundOnceNumber(vector<int>& arr, int k) {
        // write code here
        int* m = new int[32];
        for(int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for(int e : arr)
                sum += (e >> i & 1);
            m[i] = sum;
        }
        int ret = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(m[i] % k != 0)
                ret += 1 << i;
        }
        
        return ret;
    }
};
