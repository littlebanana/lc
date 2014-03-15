// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want. 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        void generate(const string &s, int idx, string prev, vector<string> &combs)
        {
            int l = s.length();
            if (idx == l)
            {
                combs.push_back(prev);
                return;
            }

            // parse a character
            switch (s[idx])
            {
                case '2':
                    {
                        generate(s, idx+1, prev+'a', combs);
                        generate(s, idx+1, prev+'b', combs);
                        generate(s, idx+1, prev+'c', combs);
                        break;
                    }
                case '3':
                    {
                        generate(s, idx+1, prev+'d', combs);
                        generate(s, idx+1, prev+'e', combs);
                        generate(s, idx+1, prev+'f', combs);
                        break;
                    }
                case '4':
                    {
                        generate(s, idx+1, prev+'g', combs);
                        generate(s, idx+1, prev+'h', combs);
                        generate(s, idx+1, prev+'i', combs);
                        break;
                    }
                case '5':
                    {
                        generate(s, idx+1, prev+'j', combs);
                        generate(s, idx+1, prev+'k', combs);
                        generate(s, idx+1, prev+'l', combs);
                        break;
                    }
                case '6':
                    {
                        generate(s, idx+1, prev+'m', combs);
                        generate(s, idx+1, prev+'n', combs);
                        generate(s, idx+1, prev+'o', combs);
                        break;
                    }
                case '7':
                    {
                        generate(s, idx+1, prev+'p', combs);
                        generate(s, idx+1, prev+'q', combs);
                        generate(s, idx+1, prev+'r', combs);
                        generate(s, idx+1, prev+'s', combs);
                        break;
                    }
                case '8':
                    {
                        generate(s, idx+1, prev+'t', combs);
                        generate(s, idx+1, prev+'u', combs);
                        generate(s, idx+1, prev+'v', combs);
                        break;
                    }
                case '9':
                    {
                        generate(s, idx+1, prev+'w', combs);
                        generate(s, idx+1, prev+'x', combs);
                        generate(s, idx+1, prev+'y', combs);
                        generate(s, idx+1, prev+'z', combs);
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }

        // DFS
        vector<string> letterCombinations(string digits) {
            vector<string> combs;
            generate(digits, 0, "", combs);
            return combs;
        }

        // more elgant handling of the cases using hash table
        void generate(const string &s, int idx, const unordered_map<char,string> &tab, string prev, vector<string> &combs)
        {
            int l = s.length();
            if (idx == l)
            {
                combs.push_back(prev);
                return;
            }

            // parse a character
            auto it = tab.find(s[idx]);
            if (it != tab.end())
            {
                for (int i = 0; i < it->second.length(); i++)
                {
                    generate(s, idx+1, tab, prev+it->second[i], combs);
                }
            }
        }

        vector<string> letterCombinations2(string digits) {
            vector<string> combs;
            unordered_map<char,string> tab;
            tab['2'] = "abc";
            tab['3'] = "def";
            tab['4'] = "ghi";
            tab['5'] = "jkl";
            tab['6'] = "mno";
            tab['7'] = "pqrs";
            tab['8'] = "tuv";
            tab['9'] = "wxyz";

            generate(digits, 0, tab, "", combs);
            return combs;
        }
};

int main()
{
    Solution solu;

    string digits = "23";
    cout << "digits = " << digits << endl;
    vector<string> combs = solu.letterCombinations(digits);

    for (int i = 0; i < combs.size(); i++)
    {
        cout << combs[i] << endl;
    }

    return 0;
}
