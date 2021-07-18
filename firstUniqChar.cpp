class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> arr;
        for (char ch: s) {
            ++arr[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (arr[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
