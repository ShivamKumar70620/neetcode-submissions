class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(auto i:matrix){
            
            if(target>=i[0] && target<=i[m-1]){
                int j = 0, k = m-1;
                while(j<=k){
                    int mid = j + (k-j)/2;
                    if(target==i[mid]){
                        return 1;
                    }
                    else if(target>i[mid]){
                        j = mid+1;
                    }
                    else
                        k = mid - 1;
                }
            }
        }
        return 0;
    }
};
