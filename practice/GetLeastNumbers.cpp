class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if(k == 0 || k > input.size())
            return ret;
        priority_queue<int, vector<int>> q;
        for(const int val : input)
        {
            if(q.size() < k)
            {
                q.push(val);
            }
            else
            {
                if(val < q.top())
                {
                    q.pop();
                    q.push(val);
                }
            }
        }
        
        while(!q.empty())
        {
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
};
