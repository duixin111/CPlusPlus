class Solution {
public:
    void reverseString(vector<char>& s) {
        // size_t begin = 0;
        // size_t end = s.size() - 1;
        // while(begin < end)
        // {
        //     swap(s[begin], s[end]);
        //     begin++;
        //     end--;
        // }
        reverse(s.begin(),s.end());
    }
};
