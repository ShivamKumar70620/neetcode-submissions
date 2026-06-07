class Solution {
public:

    void mergeSort(int l, vector<int> &nums, int r){
        if(l>=r)
            return;
        int mid = (l+r) / 2;
        mergeSort(l,nums, mid);
        mergeSort(mid+1, nums, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int> &nums, int l, int m, int r){
        vector<int> t;
        int i = l, j = m+1;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j])
                t.push_back(nums[i++]);
            else
                t.push_back(nums[j++]);
        }
        while(i<=m) t.push_back(nums[i++]);
        while(j<=r) t.push_back(nums[j++]);
        for(int k=l;k<=r;k++) nums[k] = t[k-l];
    }
    vector<int> sortArray(vector<int>& nums) {
        int i=0,n=nums.size();
        mergeSort(0,nums,n-1);
        return nums;
    }
};