class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        if(B == 0)
            return A;
        else
            return addAB(A ^ B, (A & B) << 1);
    }
};
