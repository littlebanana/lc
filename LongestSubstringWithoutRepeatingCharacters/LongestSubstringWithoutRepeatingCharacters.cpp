// Given a string, find the length of the longest substring without repeating characters.
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// For "bbbbb" the longest substring is "b", with the length of 1.

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_map<char,int> tab;    // tab[c] = the last index of char c
            int l = s.length();
            int len = 0;
            int start = 0;      // the start index of this substring
            for (int i = 0; i < l; i++)
            {
                unordered_map<char,int>::iterator it = tab.find(s[i]);
                if (it != tab.end())
                {
                    if (it->second < start)
                    {
                        len = max(len, i-start+1);
                    }
                    else
                    {
                        start = it->second + 1;
                    }
                    it->second = i;
                }
                else
                {
                    len = max(len, i-start+1);
                    tab.insert(pair<char,int>(s[i],i));
                }
            }
            return len;
        }
};

int main()
{
    string s = "abcabcabcd";

    Solution solu;
    cout << solu.lengthOfLongestSubstring(s) << endl;

    return 0;
}
