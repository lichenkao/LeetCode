class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26; 
        long long INF = 1e9;
        vector<vector<long long>> dis(n, vector<long long>(n, INF));

        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            long long x = original[i] - 'a';
            long long y = changed[i] - 'a';
            long long z = cost[i];
            dis[x][y] = min(dis[x][y], z);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] < INF && dis[k][j] < INF && dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (x != y) {
                if(dis[x][y] == INF){
                    ans = -1;
                    break;
                }

                ans += dis[x][y];
            }
        }

        return ans;
    }
};