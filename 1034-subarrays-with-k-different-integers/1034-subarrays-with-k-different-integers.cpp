class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (freq[nums[right]] == 0)
                k--;     // we added a new distinct number
            freq[nums[right]]++;

            while (k < 0) {   // shrink window until valid
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    k++;     // removed a distinct number
                left++;
            }

            count += (right - left + 1);  // number of valid subarrays ending at right
        }
        return count;
    }
};
