#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Returns min(number of permutations, limit)
    long long countPermutations(vector<int>& freq, long long limit) {
        long long ways = 1;
        int total = 0;

        for (int count : freq) {
            for (int j = 1; j <= count; j++) {

                // ways = ways * (total + j) / j
                // Use __int128 to avoid overflow
                __int128 value = (__int128)ways * (total + j);

                value /= j;

                if (value >= limit) {
                    return limit;
                }

                ways = (long long)value;
            }

            total += count;
        }

        return ways;
    }

    string smallestPalindrome(string s, long long k) {

        vector<int> freq(26, 0);

        // Count all characters
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Only half is needed because the other half is its mirror
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        string firstHalf = "";

        int remaining = s.size() / 2;

        // Build the first half character by character
        while (remaining > 0) {

            bool found = false;

            // Try characters from 'a' to 'z'
            for (int i = 0; i < 26; i++) {

                if (halfFreq[i] == 0) {
                    continue;
                }

                // Choose this character temporarily
                halfFreq[i]--;

                // Count permutations after choosing it
                long long count =
                    countPermutations(halfFreq, k);

                if (k > count) {
                    // Skip all these permutations
                    k -= count;

                    // Put character back
                    halfFreq[i]++;
                }
                else {
                    // This character belongs here
                    firstHalf += char('a' + i);

                    remaining--;
                    found = true;

                    break;
                }
            }

            if (!found) {
                return "";
            }
        }

        // Find middle character for odd-length strings
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
                break;
            }
        }

        // Mirror the first half
        string secondHalf = firstHalf;

        reverse(secondHalf.begin(), secondHalf.end());

        if (middle != '\0') {
            return firstHalf + middle + secondHalf;
        }

        return firstHalf + secondHalf;
    }
};