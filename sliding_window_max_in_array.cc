class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> de_queue_index;
        vector<int> max_array;
        for (int i=0; i<nums.size(); i++) {
            
            if (!de_queue_index.empty() && de_queue_index.front() == i-k) 
                de_queue_index.pop_front();
                
            while (!de_queue_index.empty() && nums[de_queue_index.back()] < nums[i])
                de_queue_index.pop_back();
                
            de_queue_index.push_back(i);
            
            if (i>=k-1) 
                max_array.push_back(nums[de_queue_index.front()]);
        }
        return max_array;
    }
};