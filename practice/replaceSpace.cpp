class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        int len = s.length();
        int sum = 0;
        for(auto e : s)
        {
            if(e == ' ')
                ++sum;
        }
        s.resize(len + 2 * sum);
        for(int i = len - 1, j = s.size() - 1; j > i; j--, i--)
        {
            if(s[i] != ' ')
                s[j] = s[i];
            else
            {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};
