// Given an array of strings, return all groups of strings that are anagrams.
// Note: All inputs will be in lower-case.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            vector<string> anag;
            unordered_map<string,int> tab;
            int n = strs.size();
            for (int i = 0; i < n; i++)
            {
                string word = strs[i];
                sort(word.begin(), word.end());
                auto it = tab.find(word);
                if (it != tab.end())
                {
                    if (it->second != -1)
                    {
                        anag.push_back(strs[it->second]);
                        it->second = -1;
                    }
                    anag.push_back(strs[i]);
                }
                else
                {
                    tab.insert(pair<string,int>(word,i));
                }
            }
            return anag;
        }
};

int main()
{
    vector<string> strs;
    strs.push_back("abcd");
    strs.push_back("aacd");
    strs.push_back("dbac");
    strs.push_back("caca");

    Solution solu;
    vector<string> anag = solu.anagrams(strs);

    for (int i = 0; i < anag.size(); i++)
    {
        cout << anag[i] << " ";
    }
    cout << endl;

    return 0;
}
