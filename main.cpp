#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i = 0; i < nums.size(); i++){
        if(i != 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size(); j++){
            if(j != i + 1 && nums[j] == nums[j - 1]) continue;
            int l = j + 1, h = nums.size() - 1;
            while(h > l){
                long p = nums[i] + nums[j], q = nums[l] + nums[h];
                long four_sum = p + q;
                if(four_sum < target){
                    l++;
                }
                else if(four_sum > target){
                    h--;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                    while(l < h && nums[l] == nums[l + 1]){
                        l++;
                    }
                    while(l < h && nums[h] == nums[h - 1]){
                        h--;
                    }
                    l++, h--;
                }
            }
        }
    }
    return ans;
}

