class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str;
        for(int val : numbers)
            str.push_back(to_string(val));
        sort(str.begin(), str.end(), [](string a, string b){return a + b < b + a;});
        string ret = "";
        for(string s : str)
            ret += s;
        
        return ret;
    }
};
