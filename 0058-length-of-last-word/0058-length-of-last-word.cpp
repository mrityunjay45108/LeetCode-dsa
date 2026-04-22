class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count = 0;
        int i = s.size() - 1;

        // Step 1: ignore trailing spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: count last word
        while(i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};