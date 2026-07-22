class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isVowel(s[i])) { ++i; continue; }
            if (!isVowel(s[j])) { --j; continue; }
            swap(s[i], s[j]);
            ++i; --j;
        }
        return s;
    }
};