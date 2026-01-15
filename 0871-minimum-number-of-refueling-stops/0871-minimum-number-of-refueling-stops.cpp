class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max-heap to store fuel amounts of stations we have passed
        priority_queue<int> max_heap;
        
        int currentFuel = startFuel;
        int stops = 0;
        int i = 0;
        int n = stations.size();
        
        // While we haven't reached the target
        while (currentFuel < target) {
            // Add all stations we can reach with current fuel to the heap
            while (i < n && stations[i][0] <= currentFuel) {
                max_heap.push(stations[i][1]);
                i++;
            }
            
            // If no more stations can be reached and we aren't at target
            if (max_heap.empty()) return -1;
            
            // Refuel from the best station we passed (Greedy choice)
            currentFuel += max_heap.top();
            max_heap.pop();
            stops++;
        }
        
        return stops;
    }
};
