class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(auto i:mp){
            minheap.push({i.second, i.first});
            if(minheap.size()>k)
                minheap.pop();
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;
    }
};
