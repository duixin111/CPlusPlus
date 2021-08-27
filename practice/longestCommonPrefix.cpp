class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        if(strs.size() == 0)
            return "";
        sort(strs.begin(), strs.end());
        string a = strs.front();
        string b = strs.back();
        int i = 0;
        for(; i < a.size() && a[i] == b[i]; i++);
        return a.substr(0, i);
    }
};
