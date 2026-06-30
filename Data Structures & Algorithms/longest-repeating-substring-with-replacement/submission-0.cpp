class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> cnt;

            int maxi=0;
            for(int j=i;j<s.size();j++){
                cnt[s[j]]++;
                maxi = max(maxi, cnt[s[j]]);
                if((j - i + 1) - maxi <= k){
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};
