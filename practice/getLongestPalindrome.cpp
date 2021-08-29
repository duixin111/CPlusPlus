class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(n == 0)
            return NULL;
        if(n == 1)
            return 1;
        int maxlength = 0;
        int start;
        for(int i = 0;i < n;i++)//长度为奇数
        {
            int j = i-1,k = i+1;
            while(j >= 0 && k < n && A.at(j) == A.at(k))//循环条件
            {
                if(k - j + 1 > maxlength)
                {
                    maxlength = k - j + 1;
                    start = j;
                }
                j--;
                k++;
            }
        }

        for(int i = 0;i < n;i++)//长度为偶数
        {
            int j = i,k = i + 1;
            while(j >= 0 && k < n && A.at(j) == A.at(k))
            {
                if(k - j + 1 > maxlength)
                {
                    maxlength = k - j + 1;
                    start = j;
                }
                j--;
                k++;
            }
        }
        if(maxlength > 0)
            return maxlength;
        return NULL;
        }
};
