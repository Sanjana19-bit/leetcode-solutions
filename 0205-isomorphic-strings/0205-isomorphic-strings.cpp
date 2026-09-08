class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
            return false;

        int mapST[256] = {0};
        int mapTS[256] = {0};

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            if (mapST[a] != 0 && mapST[a] != b)
                return false;

            if (mapTS[b] != 0 && mapTS[b] != a)
                return false;

            mapST[a] = b;
            mapTS[b] = a;
        }

        return true;
    }
};