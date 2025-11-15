class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        // Count frequency of each letter in magazine
        for(char c : magazine){
            freq[c - 'a']++;
        }

        // Check if ransomNote can be constructed
        for(char c : ransomNote){
            if(freq[c - 'a'] == 0) return false;
            freq[c - 'a']--;
        }

        return true;
    }
};
