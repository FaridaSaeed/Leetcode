class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto i:asteroids)
        {
            bool f = false;
            while(!st.empty() && i<0 && st.top()>0)
            {
                if(abs(i)<=st.top()){
                    f = true;
                    if(abs(i)==st.top())st.pop();
                    break;
                }
                else st.pop();
            }
            if(f)continue;
            st.push(i);
            cout<<i<<' ';
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        if(!ans.empty())
            reverse(ans.begin(),ans.end());
        return ans;
    }
};