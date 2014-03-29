// Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
//    Only one letter can be changed at a time
//    Each intermediate word must exist in the dictionary
// For example,
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:
//     All words have the same length.
//     All words contain only lowercase alphabetic characters.

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    struct Node
    {
        int dist;
        vector<string> parents;
        Node (int d) : dist(d) {}
    };
    
    void backtrack(int level, string end, const unordered_map<string,Node> &visited, vector<string> seq, vector<vector<string> > &seqs)
    {
        seq[level] = end;

        auto it = visited.find(end);
        int n = it->second.parents.size();
        for (int i = 0; i < n; i++)
        {
            string parent = it->second.parents[i];
            if (level == 1)
            {
                seq[level-1] = parent;
                seqs.push_back(seq);
            }
            else
            {
                backtrack(level-1, parent, visited, seq, seqs);
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        int l = start.length();
        
        dict.insert(end);
        
        queue<string> Q;
        unordered_map<string,Node> visited;
        
        Q.push(start);
        Node tmp(1);
        visited.insert(pair<string,Node>(start,tmp));
        
        int mindist = 0;
        while (!Q.empty())
        {
            string word = Q.front();
            Q.pop();
            
            int dist = visited.find(word)->second.dist;
            if (mindist > 0 && dist >= mindist)
            {
                continue;
            }

            string next = word;            
            for (int i = 0; i < l; i++)
            {
                char c = next[i];
                for (int j = 0; j < 26; j++)
                {
                    if ('a'+j != c)
                    {
                        next[i] = 'a'+j;
                        if (dict.find(next) != dict.end())
                        {
                            auto it = visited.find(next);
                            if (it == visited.end())
                            {
                                Node tmp(dist+1);
                                tmp.parents.push_back(word);
                                visited.insert(pair<string,Node>(next,tmp));
                                Q.push(next);
                            }
                            else if (it->second.dist == dist+1)
                            {
                                it->second.parents.push_back(word);
                            }
                            if (next.compare(end) == 0)
                            {
                                if (mindist == 0)
                                {
                                    mindist = dist + 1;
                                }
                            }
                        }
                    }
                }
                next[i] = c;
            }
        }
        
        if (mindist == 0)
        {
            return vector<vector<string> >();
        }
        
        vector<string> seq(mindist);
        vector<vector<string> > seqs;
        backtrack(mindist-1, end, visited, seq, seqs);
        return seqs;
    }
};

int main()
{
    Solution solu;

    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dog");
    dict.insert("dot");

    string start = "hot";
    string end = "dog";
    vector<vector<string> > paths = solu.findLadders(start, end, dict);
    for (int i = 0; i < paths.size(); i++)
    {
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
