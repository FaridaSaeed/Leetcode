class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = beginWord.size();
        vector<vector<int>>adj(n+2);
        int lst = -1;
        for(int i=0;i<n;i++)if(endWord==wordList[i])lst = i;
        if(lst==-1)return 0;
        queue<int>q;
        vector<int>lvl(n+2,-1);
        for(int i=0;i<n;i++)
        {
            int s = 0;
            for(int l = 0;l<m;l++)
            {
                s+=(beginWord[l]!=wordList[i][l]);
            }
            if(s<=1){
                q.push(i);
                lvl[i] = 1;
            }
            for(int j=0;j<n;j++)
            {
                int tr = 0;
                for(int k=0;k<m;k++)
                {
                    tr+=(wordList[i][k]!=wordList[j][k]);
                }
                if(tr<=1)adj[i].push_back(j);
            }
        }
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(auto i:adj[f])
            {
                if(lvl[i]==-1)
                {
                    q.push(i);
                    lvl[i] = lvl[f]+1;
                }
            }
        }
        return lvl[lst]+1;
    }
};