class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0; // use long to detect overflow
        int sign = 1;

        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits and convert
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before multiplying
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // Step 4: Apply sign and return
        return (int)(result * sign);
    }
};
