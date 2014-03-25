


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        void generate(const string &s, int left, const vector<vector<int> > &next, string cut, vector<string> &sets)
        {
            if (next.empty())
            {
                return;
            }

            int L = s.length();
            int n = next[left].size();
            for (int i = 0; i < n; i++)
            {
                int start = next[left][i];

                string tmp = cut+s.substr(left,start-left);
                if (start == L)
                {
                    sets.push_back(tmp);
                }
                else
                {
                    generate(s, start, next, tmp+" ", sets);
                }
            }
        }

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            int L = s.length();
            // Dynamic programming
            bool tab[L+1];
            tab[L] = true;
            vector<vector<int> > next(L);       // index of the start of the next substring
            for (int i = L-1; i >= 0; i--)
            {
                tab[i] = false;
                for (int j = i; j < L; j++)
                {
                    if (dict.find(s.substr(i,j-i+1)) != dict.end() && tab[j+1])
                    {
                        tab[i] = true;
                        next[i].push_back(j+1);
                    }
                }
            }

            // backtracking
            vector<string> sets;
            generate(s, 0, next, "", sets);
            return sets;
        }
};

int main()
{
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    string s = "catsanddog";

    Solution solu;
    vector<string> sets = solu.wordBreak(s, dict);
    for (int i = 0; i < sets.size(); i++)
    {
        cout << sets[i] << endl;
    }

    return 0;
}
