class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(')');
            else if(s[i] == '{')
                st.push('}');
            else if(s[i] == '[')
                st.push(']');
            else
            {
                if(st.size() == 0)
                    return false;
                if(st.top() == s[i])
                    st.pop();
            }
        }
        
        if(!st.size())
            return true;
        return false;
    }
};
