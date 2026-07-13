class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> rec;
        int n =  heights.size();
        for(int i = 0; i <= n; i++){
            while(!rec.empty() && (i == n || heights[rec.top()] >= heights[i])){
                int height = heights[rec.top()];
                rec.pop();
                int width = rec.empty() ? i : i - rec.top() -1;
                maxArea = max(maxArea, height * width);
            }
            rec.push(i);
        }
        return maxArea;
    }
};
