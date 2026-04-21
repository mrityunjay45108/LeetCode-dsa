class Solution {
public:

    bool isAnagram(string a, string b) {
        if (a.size() != b.size()) return false;

        int count[26] = {0};

        for (int i = 0; i < a.size(); i++) {
            count[a[i] - 'a']++;
            count[b[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<bool> visited(strs.size(), false);

        for (int i = 0; i < strs.size(); i++) {

            if (visited[i]) continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {

                if (!visited[j] && isAnagram(strs[i], strs[j])) {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};