#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int mid) 
    {
        int n = nums.size();
        vector<int> diff(n+1,0);

        for(int i=0;i<mid;i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l]+=val;
            diff[r+1]-=val;
        }

        for(int i=1;i<n;i++) diff[i] += diff[i-1];

        for(int i=0;i<n;i++)
        {
            if(diff[i]<nums[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int low=0, high=n, ans=-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(nums,queries,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};