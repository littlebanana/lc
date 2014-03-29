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

class Solution2 {
public:
    bool isNeighbor(string s1, string s2)
    {
        int l = s1.length();
        for (int i = 0; i < l; i++)
        {
            char c = s1[i];
            for (int j = 0; j < 26; j++)
            {
                if ('a'+j != c)
                {
                    s1[i] = 'a'+j;
                    if (s1.compare(s2) == 0)
                    {
                        return true;
                    }
                }
            }
            s1[i] = c;
        }
        return false;
    }
    
    void backtrack(string start, string end, const unordered_map<string, vector<string> > &prev, vector<string> path, vector<vector<string> > &paths)
    {
        if (end.compare(start) == 0)
        {
            paths.push_back(path);
            return;
        }
        vector<string> neighbor = prev.find(end)->second;
        int n = neighbor.size();
        for (int i = 0; i < n; i++)
        {
            vector<string> tmp = path;
            tmp.push_back(neighbor[i]);
            backtrack(start, neighbor[i], prev, tmp, paths);
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        int l = start.length();
        
        // level BFS
        
        unordered_set<string> visited;
        unordered_map<string,int> dist;
        unordered_map<string,vector<string> > prev;
        
        bool found = false;
        queue<string> Q;
        Q.push(start);
        visited.insert(start);
        dist.insert(pair<string,int>(start,1));
        
        int n = 1;
        while (!Q.empty() && !found)
        {
            int cnt = 0;
            for (int nn = 0; nn < n; nn++)
            {
                string word = Q.front();
                Q.pop();
                
                int d = dist.find(word)->second;
                
                string next = word;
                for (int i = 0; i < l; i++)
                {
                    char c = next[i];
                    for (int j = 0; j < 26; j++)
                    {
                        if ('a'+j != c)
                        {
                            next[i] = 'a'+j;
                            if (next.compare(end) == 0)
                            {
                                found = true;
                                if (visited.find(end) == visited.end())
                                {
                                    vector<string> p;
                                    p.push_back(word);
                                    prev.insert(pair<string,vector<string> >(end,p));
                                    visited.insert(end);
                                    dist.insert(pair<string,int>(end,d+1));
                                }
                                else
                                {
                                    prev.find(end)->second.push_back(word);
                                }
                            }
                            else
                            {
                                if (dict.find(next) != dict.end())
                                {
                                    if (visited.find(next) == visited.end())
                                    {
                                        vector<string> p;
                                        p.push_back(word);
                                        prev.insert(pair<string,vector<string> >(next,p));
                                        visited.insert(next);
                                        dist.insert(pair<string,int>(next,d+1));
                                        Q.push(next);
                                        cnt++;
                                    }
                                    else
                                    {
                                        int dd = dist.find(next)->second;
                                        if (dd == d+1)
                                        {
                                            prev.find(next)->second.push_back(word);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    next[i] = c;
                }
            }
            n = cnt;
        }
        
        if (!found)
        {
            return vector<vector<string> >();
        }
        
        vector<string> path;
        path.push_back(end);
        vector<vector<string> > paths;
        backtrack(start, end, prev, path, paths);
        for (int i = 0; i < paths.size(); i++)
        {
            reverse(paths[i].begin(), paths[i].end());
        }
        return paths;
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
