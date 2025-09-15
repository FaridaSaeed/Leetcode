class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_map<string,int>lvl;
        q.push(beginWord);
        lvl[beginWord] = 1;
        while(!q.empty())
        {
            string front = q.front();
            q.pop();
            for(auto i:wordList)
            {
                if(!lvl[i])
                {
                    int s = 0;
                    for(int j=0;j<i.size();j++)
                        s+=(i[j]!=front[j]);
                    if(s==1)
                    {
                        q.push(i);
                        lvl[i] = lvl[front]+1;
                    }
                }
            }
        }
        return lvl[endWord];
    }
};