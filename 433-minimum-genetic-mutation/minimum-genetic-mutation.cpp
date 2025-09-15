class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string>q;
        unordered_map<string,int>lvl;
        q.push(startGene);
        lvl[startGene] = 1;
        while(!q.empty())
        {
            string front = q.front();
            q.pop();
            for(auto i:bank)
            {
                if(!lvl[i])
                {
                    int s = 0;
                    for(int j = 0;j<i.size();j++)
                    {
                        if(i[j]!=front[j])s++;
                    }
                    if(s==1)
                    {
                        q.push(i);
                        lvl[i] = lvl[front]+1;
                    }
                }
            }
        }
        return lvl[endGene]-1;
    }
};