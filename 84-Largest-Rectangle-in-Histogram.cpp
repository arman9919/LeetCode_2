class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsi(n); // use vector instead of array for nsi
        stack<int> st;
        
        nsi[n-1] = n;
        st.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) 
                st.pop();
            if (st.size() == 0) 
                nsi[i] = n;
            else 
                nsi[i] = st.top();
            st.push(i);
        }

        vector<int> psi(n); // use vector instead of array for psi
        stack<int> gt;
        psi[0] = -1;
        gt.push(0);
        for (int i = 1; i < n; i++) { // corrected loop direction
            while (gt.size() > 0 && heights[gt.top()] >= heights[i]) 
                gt.pop();
            if (gt.size() == 0) 
                psi[i] = -1;
            else 
                psi[i] = gt.top();
            gt.push(i);
        }

        int maxArea = 0; // initialize maxArea to 0
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area = height * breadth;
            if (area > maxArea) 
                maxArea = area; // update maxArea
        }
        return maxArea; // return maxArea
    }
};
