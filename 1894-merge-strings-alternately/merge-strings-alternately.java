class Solution {
    public String mergeAlternately(String word1, String word2) {
        String ans = "";
        int n = Math.min(word1.length(),word2.length());
        for(int i = 0; i < n; i++) 
            ans += word1.charAt(i) + "" + word2.charAt(i); 

        if(word1.length()<word2.length())
        {
            for(int i=n;i<word2.length();i++)ans += word2.charAt(i);
        }
        else
        {
            for(int i=n;i<word1.length();i++)ans += word1.charAt(i);
        }
        return ans;
    }
}