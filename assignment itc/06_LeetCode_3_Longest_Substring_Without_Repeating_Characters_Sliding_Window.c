/*
 * Problem Name          : Longest Substring Without Repeating Characters
 * LeetCode Problem No.  : 3
 * Topic                 : STRINGS
 * Problem Link          : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Problem Description:
 * Given a string s, determine the length of the longest
 * substring that contains no repeating characters.
 *
 * A substring is a continuous sequence of characters
 * within the original string.
 *
 * The solution must identify the maximum length of a
 * substring in which every character appears only once.
 */

int lengthOfLongestSubstring(char* s) {
    int last[256];
    
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int start = 0;
    int maxLength = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = s[i];

        if (last[ch] >= start) {
            start = last[ch] + 1;
        }

        last[ch] = i;

        int length = i - start + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}
