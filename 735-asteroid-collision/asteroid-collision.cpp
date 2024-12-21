class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(auto i:asteroids)
        {
            if(st.empty())st.push_back(i);
            else
            {
                if(i<0 && st.back()>0)
                {
                    while(!st.empty()&& st.back()>0 && abs(i)>st.back())
                        st.pop_back();
                    if(st.empty() || st.back()<0)st.push_back(i);
                    if(st.back()>0 && abs(i)==st.back()){
                        st.pop_back();
                    }
                }
                else
                    st.push_back(i);
            }
        }
        return st;
    }
};