class Solution {
public:
    int ans = INT_MAX;

    void backtrack(vector<int>& jobs, vector<int>& workers, int idx) {
        
        // All jobs assigned
        if (idx == jobs.size()) {
            int mx = 0;

            for (int w : workers) {
                mx = max(mx, w);
            }

            ans = min(ans, mx);
            return;
        }

        int job = jobs[idx];

        for (int i = 0; i < workers.size(); i++) {

            // Pruning
            if (workers[i] + job >= ans)
                continue;

            workers[i] += job;

            backtrack(jobs, workers, idx + 1);

            workers[i] -= job;

            // Important optimization
            // If worker had no job before, don't try other empty workers
            if (workers[i] == 0)
                break;
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {

        sort(jobs.rbegin(), jobs.rend());

        vector<int> workers(k, 0);

        backtrack(jobs, workers, 0);

        return ans;
    }
};