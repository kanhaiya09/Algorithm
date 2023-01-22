// https://leetcode.com/problems/longest-palindromic-substring/description/

string longestPalindrome(string s) {
    string res = "";
    int max = 0;
    int n  = s.size();
    for(int i = 0 ; i < n; i++){

        int l = i;
        int r = i;
        while(l>=0 and r< n and s[l]==s[r]){
            if(r-l+1>max)
            {
                max = r-l+1;
                res = s.substr(l,max);
            }
            l--;
            r++;
        }

        l = i;
        r = i+1;
        while(l>=0 and r< n and s[l]==s[r]){
            if(r-l+1>max)
            {
                max = r-l+1;
                res = s.substr(l,max);
            }
            l--;
            r++;
        }
    }
    return res;
}
