class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int circles = 0;
        queue<int> q;
        for (int i = 0; i < provinces; i++)
        {
            if (!visited[i])
            {
                q.push(i);
                while (!q.empty())
                {
                    int j = q.front(); q.pop();
                    visited[j] = 1;
                    for (int k = 0; k < provinces; k++)
                    {
                        if (isConnected[j][k] == 1 && !visited[k])
                        {
                            q.push(k);
                        }
                    }
                }
                circles++;
            }
        }
        
        return circles;
    }
};
