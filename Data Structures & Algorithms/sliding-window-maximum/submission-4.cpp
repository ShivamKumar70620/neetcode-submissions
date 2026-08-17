class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int mx1 = INT_MIN, mx2 = INT_MIN;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        int i=0,j=k;
        while(j<n){
            pq.push({nums[j],j});

            while(pq.top().second<j-k+1){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            j++;
        }
        return ans;
    }
};
