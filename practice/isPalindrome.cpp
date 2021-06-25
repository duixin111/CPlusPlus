class Solution {
public:
    bool isPalindrome(string s) {
        int str = s.length();
        int left = 0;
        int right = str;
        while(left < right)
        {
            while(left < right && !isalnum(s[left]))
                left++;
            while(left < right && !isalnum(s[right]))
                right--;
            
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
