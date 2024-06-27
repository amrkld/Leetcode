class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set_answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){

            int j = i +1;
            int k = nums.size()-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i] , nums[j] , nums[k]};
                    //sort(temp.begin(), temp.end());
                    set_answer.insert(temp); // sort so we dont get any dublicates
                    // we must update our pointers
                    j ++;
                    while(nums[j] == nums[j - 1] and j < k){  // if j is the same as j-1
                        j ++; 
                    }
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else{ // if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                }
            }
        }
        return vector<vector<int>>(set_answer.begin(), set_answer.end());
    }
};