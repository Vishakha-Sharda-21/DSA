class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        // Topological Sort
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            order.push_back(current);

            for (int next : graph[current]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Cycle exists
        if (order.size() != numCourses) {
            return {};
        }

        return order;
    }
};
