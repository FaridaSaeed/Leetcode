class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>v;
        for(auto i:queries)
        {
            bool f = true;
            int k = 0;
            for(int j=0;j<i.size();j++)
            {
                if(i[j]==pattern[k])
                    k++;
                else if(isupper(i[j])){
                    f = false;
                    break;
                }

            }

            if(f && k==pattern.size())
                v.push_back(1);
            else v.push_back(0);
        }
        return v;
    }
};