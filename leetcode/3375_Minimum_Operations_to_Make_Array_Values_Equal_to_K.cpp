class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(const auto& num : nums) {
            if(k > num) return -1;
            else if(k < num) mp[num]++;
        }
        return mp.size();
    }
};