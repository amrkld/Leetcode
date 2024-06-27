class Solution {
public:
    bool isPalindrome(string s) {
        // alphanumeric contains numbers
        string lowers = \\;
        for (auto ch : s) {
            lowers += tolower(ch);
        }

        string alphaS = \\;
        // Alph is in range from (97 (a) to 122 (z))
        for (auto ch : lowers) {
            int chh = int(ch);
            if ((chh > 96 && chh < 123) || (chh >= 48 && chh <= 57)) {
                alphaS += ch;
            }
        }

        if (alphaS.size() == 1 || alphaS.size() == 0) {
            return true;
        }

        // two pointers , start & end
        int start = 0;
        int end = alphaS.size() - 1;

        while (start <= int(end + 1 / 2)) {
            if (alphaS[start] == alphaS[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};