class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>> pq;

        for(int i:nums){
            mp[i]++;
        }
        
        for(auto i:mp){
            pq.push({i.second, i.first});
        }

        vector<int>ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
