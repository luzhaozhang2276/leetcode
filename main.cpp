#include <bits/stdc++.h>
using namespace std;

/// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);
        for (const auto &p : prerequisites) {
            degree[p[0]]++;
            adjacency[p[1]].emplace_back(p[0]);
        }

        queue<int> Q;
        for (int i = 0; i < degree.size(); ++i) {
            if (degree[i] == 0)
                Q.push(i);
        }

        while (!Q.empty()) {
            int pre = Q.front();
            Q.pop();
            numCourses--;
            for (const auto &p : adjacency[pre]) {
                degree[p]--;
                if (degree[p] == 0)
                    Q.push(p);
            }
        }

        return numCourses == 0;
    }
};

int main() {
    vector<vector<int>> nums = {
                                {2, 1},
                                {4, 1},
                                {4, 2},
                                {3, 2},
                                {5, 3},
                                {5, 4}};

    nums = {{1, 0}};
    Solution solve;
    cout << solve.canFinish(2, nums) << endl;
//    cout << solve.canFinish(6, nums) << endl;

    return 0;
}