class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<vector<int>> vec(nums.size()+1);
        for(auto i:mp){
            vec[i.second].push_back(i.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i > 0; --i) {
            for (int num : vec[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
