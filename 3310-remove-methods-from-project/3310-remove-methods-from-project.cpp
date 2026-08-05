class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& suspicious) {
        suspicious[node] = true;

        for (int next : graph[node]) {
            if (!suspicious[next]) {
                dfs(next, graph, suspicious);
            }
        }
    }

    vector<int> remainingMethods(
        int n,
        int k,
        vector<vector<int>>& invocations
    ) {
        vector<vector<int>> graph(n);

        for (auto& edge : invocations) {
            int caller = edge[0];
            int called = edge[1];

            graph[caller].push_back(called);
        }

        vector<bool> suspicious(n, false);

        dfs(k, graph, suspicious);

        for (auto& edge : invocations) {
            int caller = edge[0];
            int called = edge[1];

            if (!suspicious[caller] && suspicious[called]) {
                vector<int> answer;

                for (int i = 0; i < n; i++) {
                    answer.push_back(i);
                }

                return answer;
            }
        }

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};