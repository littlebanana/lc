// You are given a string, S, and a list of words, L, that are all of the same length.
// Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
// For example, given:
// S: "barfoothefoobarman"
// L: ["foo", "bar"]
// You should return the indices: [0,9]. (order does not matter). 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            // brute force method
            int N = L.size();
            int Ls = S.length();
            if (N == 0)
            {
                return vector<int>();
            }
            int Lw = L[0].length();
            if (Ls < N*Lw)
            {
                return vector<int>();
            }

            unordered_map<string,int> dict;
            for (int j = 0; j < N; j++)
            {
                auto it = dict.find(L[j]);
                if (it != dict.end())
                {
                    it->second++;
                }
                else
                {
                    dict[L[j]] = 1;
                }
            }

            vector<int> result;

            for (int i = 0; i <= Ls - N*Lw; i++)
            {
                unordered_map<string,int> used;
                bool found = true;
                for (int j = 0; j < N; j++)
                {
                    string word = S.substr(i+j*Lw, Lw);
                    auto it = dict.find(word);
                    if (it == dict.end())
                    {
                        found = false;
                        break;
                    }
                    else
                    {
                        auto jt = used.find(word);
                        if (jt == used.end())
                        {
                            used[word] = 1;
                        }
                        else
                        {
                            if (jt->second < it->second)
                            {
                                jt->second++;
                            }
                            else
                            {
                                found = false;
                                break;
                            }
                        }
                    }
                }
                if (found)
                {
                    result.push_back(i);
                }
            }
            return result;
        }
};

int main()
{
    string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> L;
    L.push_back("fooo");
    L.push_back("barr");
    L.push_back("wing");
    L.push_back("ding");
    L.push_back("wing");

    vector<int> result;
    Solution solu;
    result = solu.findSubstring(S, L);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }


    return 0;
}
