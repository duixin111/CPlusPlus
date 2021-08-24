class Solution {
public:
    int partion(vector<int>& a, int low, int high)
    {
        int temp = a[low];
        while(low < high)
        {
            while(low < high && a[high] <= temp)
                --high;
            if(low == high)
                break;
            else
                a[low] = a[high];
            while(low < high && a[low] >= temp)
                ++low;
            if(low == high)
                break;
            else
                a[high] = a[low];
        }
        a[low] = temp;
        
        return low;
    }
    int quickSort(vector<int>& a, int low, int high, int K)
    {
        int p = partion(a, low, high);
        if(K == p - low + 1)
            return a[p];
        else if(p - low + 1 > K)
            return quickSort(a ,low, p, K);
        else
            return quickSort(a, p + 1, high, K - (p - low + 1));
    }
    
    
    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quickSort(a, 0, n - 1, K);
    }
};
