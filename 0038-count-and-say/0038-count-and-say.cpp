class Solution {
public:
    
    string solve(string s) {

        string ans = "";

        int count = 1;

        for (int i = 0; i < s.length(); i++) {

            count = 1;

            while (i + 1 < s.length() && s[i] == s[i + 1]) {
                count++;
                i++;
            }

            ans += to_string(count);
            ans += s[i];
        }

        return ans;
    }

    string countAndSay(int n) {

        string res = "1";

        for (int i = 2; i <= n; i++) {
            res = solve(res);
        }

        return res;
    }
};