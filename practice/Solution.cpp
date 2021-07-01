class Solution {
public:
    int StrToInt(string str){
        int len = str.size();
        int flag = 1;
        if(len == 0)
            return 0;
        const char *cstr = str.c_str();
        if(cstr == NULL)
            return 0;
        int i = 0;
        if(cstr[i] == '+')
        {
            i++;
            flag = 1;
        }
        else if(cstr[i] == '-')
        {
            i++;
            flag = -1;
        }
        long long num = 0;
        while(cstr[i] != '\0')
        {
            if(cstr[i] >= '0' && cstr[i] <= '9')
            {
                num = num * 10 + (cstr[i] - '0');
                i++;
            }
            else
                return 0;
        }
        if(flag < 0)
            num = num * -1;
        return (int)num;
    }
};
