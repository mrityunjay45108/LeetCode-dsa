class Solution {
public:
    int ans = INT_MAX;

    void backtrack(vector<int>& jobs, vector<int>& workers, int idx) {
        
       
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

           
            if (workers[i] + job >= ans)
                continue;

            workers[i] += job;

            backtrack(jobs, workers, idx + 1);

            workers[i] -= job;
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