class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;

        for(int i = 0; i < s.size(); i++) {

            if(isdigit(s[i])) {
                seenDigit = true;
            }

            else if(s[i] == '+' || s[i] == '-') {
                // sign only valid at start or just after e/E
                if(i > 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }

            else if(s[i] == '.') {
                // dot only once and before exponent
                if(seenDot || seenExp)
                    return false;
                seenDot = true;
            }

            else if(s[i] == 'e' || s[i] == 'E') {
                // exponent only once and needs digit before it
                if(seenExp || !seenDigit)
                    return false;

                seenExp = true;
                seenDigit = false; // must have digits after e
            }

            else {
                return false;
            }
        }

        return seenDigit; // ensures valid ending
    }
};