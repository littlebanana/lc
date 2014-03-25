// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// Return true because "leetcode" can be segmented as "leet code". 

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            int L = s.length();
            // Dynamic programming
            bool tab[L+1];        // tab[i] = whether s[i...(L-1)] can be seperated
            tab[L] = true;
            for (int i = L-1; i >= 0; i--)
            {
                tab[i] = false;
                for (int j = i; j < L; j++)
                {
                    if (dict.find(s.substr(i,j-i+1)) != dict.end() && tab[j+1])
                    {
                        tab[i] = true;
                        break;
                    }
                }
            }
            return tab[0];
            ;    }
};

int main()
{
    string s = "leetcode";
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    Solution solu;
    cout << (solu.wordBreak(s, dict) ? "true" : "false") << endl;

    return 0;
}
