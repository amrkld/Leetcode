class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        while (l < r) {
            int dist = r - l;
            int min_dist = min(height[r], height[l]);
            int temp_area = min_dist * dist; 
            maxArea = max(maxArea, temp_area);
            // update our pointers
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return maxArea;
    }
};