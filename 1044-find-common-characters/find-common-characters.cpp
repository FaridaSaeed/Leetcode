class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        string s = words[0];
        int n = words.size();
        vector<string>ans;
        for(auto i:s)
        {
            int x = 0;
            for(int j=1;j<n;j++)
            {
                bool f = false;
                for(auto &k:words[j])
                {
                    if(i==k && !f)
                    {
                        f = true;
                        k = 'O';
                        x++;
                    }
                }
            }
            if(x==n-1)
            {
                string c;
                c+=i;
                ans.push_back(c);

            }
        }
        return ans;
    }
};