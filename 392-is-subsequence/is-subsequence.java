class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = t.length(),j = 0,i = 0,m = s.length();
        while(i<n && j<m)
        {
            if(t.charAt(i)==s.charAt(j))j++;
            if(j==m)return true;
            i++;
        }
        return j==m;
    }
}