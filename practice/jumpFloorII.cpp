class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0 || number == 1)
            return 1;
        return pow(2, number - 1);
    }
};
