//Recursion--

// class Solution {
// public:
//   int n;
//   long long solve(int i,int j,vector<int>&nums){
//     if(i>=n){
//         return 0;
//     }
//     long long skip=solve(i+1,j,nums);
//     long long take=0;
//     if(j==-1 || nums[i]-i>=nums[j]-j){
//       take=nums[i]+solve(i+1,i,nums);
//     }
//     return max<long long>(skip,take);
//   }
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         n=nums.size();
//         long long temp=*max_element(nums.begin(),nums.end());
//         if(temp<=0){
//             return temp;
//         }
//        return solve(0,-1,nums);
//     };
// };


//Test_case-upto 341
//Recursion+memoization


// class Solution {
// public:
//   int n;
//   unordered_map<string,long long>dp;
//   long long solve(int i,int j,vector<int>&nums){
//     if(i>=n){
//         return 0;
//     }
//    string key=to_string(j)+"_"+to_string(i);
//    if(dp.find(key)!=dp.end()){
//     return dp[key];
//    }
//     long long skip=solve(i+1,j,nums);
//     long long take=0;
//     if(j==-1 || nums[i]-i>=nums[j]-j){
//       take=nums[i]+solve(i+1,i,nums);
//     }
//      return dp[key]=max<long long>(skip,take);
//   }
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         n=nums.size();
//         long long temp=*max_element(nums.begin(),nums.end());
//         if(temp<=0){
//             return temp;
//         }
//        return solve(0,-1,nums);
//     };
// };



//T.c-O(n^2)
//Buttom-up
// class Solution {
// public:
  
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n=nums.size();
//         long long temp=*max_element(nums.begin(),nums.end());
//         if(temp<=0){
//             return temp;
//         }
//         vector<long long>dp(n);
//         for(int i=0;i<n;i++){
//             dp[i]=nums[i];
//         }
//         long long result=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                if(nums[i]-i>=nums[j]-j){
//                 dp[i]=max<long long>(dp[i],nums[i]+dp[j]);
//                }
//             }
//             result=max(result,dp[i]);
//         }
//       return result;
//     };
// };


class Solution {
public:

    class BIT {
    public:

        int n;
        vector<long long> bit;

        BIT(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }

        void update(int idx, long long val) {

            while(idx <= n) {

                bit[idx] = max(bit[idx], val);

                idx += idx & (-idx);
            }
        }

        long long query(int idx) {

            long long ans = 0;

            while(idx > 0) {

                ans = max(ans, bit[idx]);

                idx -= idx & (-idx);
            }

            return ans;
        }
    };

    long long maxBalancedSubsequenceSum(vector<int>& nums) {

        int n = nums.size();

        long long mx = *max_element(nums.begin(), nums.end());

        // all negative
        if(mx <= 0)
            return mx;

        vector<long long> vals;

        for(int i = 0; i < n; i++) {

            vals.push_back((long long)nums[i] - i);
        }

        // Coordinate Compression
        vector<long long> temp = vals;

        sort(temp.begin(), temp.end());

        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        BIT bit(temp.size());

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long key = (long long)nums[i] - i;

            int idx = lower_bound(temp.begin(), temp.end(), key) - temp.begin() + 1;

            // best previous dp
            long long best = bit.query(idx);

            long long curr = best + nums[i];

            ans = max(ans, curr);

            bit.update(idx, curr);
        }

        return ans;
    }
};