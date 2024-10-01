class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string s,ans;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/'){
                if(!s.empty())
                {
                    if(s==".." && !st.empty()) st.pop();
                    else if(s==".." || s==".")
                        s.clear();
                    else 
                        st.push(s);
                }
                s.clear();
                continue;
            }
            int cdot = 0;
            while(i<path.size() && path[i]=='.')
            {
                cdot++;
                s+=path[i];
                i++;
            }
            if(cdot)i--;
            else s+=path[i];
        }
        if(!s.empty()){
            if(s==".." && !st.empty()) st.pop();
            else if(s==".." || s==".")
                s.clear();
            else 
                st.push(s);
        }
        if(st.empty())return"/";
        while(!st.empty())
        {
            reverse(st.top().begin(),st.top().end());
            ans+=st.top();
            ans+='/';
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};