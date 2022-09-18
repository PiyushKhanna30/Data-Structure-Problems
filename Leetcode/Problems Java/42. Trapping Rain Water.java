class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];

        left[0] = height[0];
        for (int i = 1; i < n; i++)
            left[i] = Math.max(height[i], left[i - 1]);

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = Math.max(height[i], right[i + 1]);

        int water = 0;
        for (int i = 0; i < n; i++)
            water += (Math.min(left[i], right[i]) - height[i]);

        return water;
    }
}

/*
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        Stack<Integer> st = new Stack<>();
        st.add(left[0]);
        for (int i = 1; i < n; i++) {
            if (st.peek() > height[i]) {
                left[i] = st.peek();
            } else {
                while (!st.isEmpty() && st.peek() <= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    left[i] = height[i];
                    st.push(height[i]);
                } else left[i] = st.peek();
            }
        }
        st = new Stack<>();
        st.add(height[n - 1]);
        right[n - 1] = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (st.peek() > height[i]) {
                right[i] = st.peek();
            } else {
                while (!st.isEmpty() && st.peek() <= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    right[i] = height[i];
                    st.push(height[i]);
                } else right[i] = st.peek();
            }
        }
        // Arrays.stream(left).forEach(x->System.out.print(x+", "));
        // System.out.println();
        // Arrays.stream(right).forEach(x->System.out.print(x+", "));
        // System.out.println();
        int water = 0;
        for (int i = 0; i < n; i++) {
            int smallWall = Math.min(left[i], right[i]);
            water += (smallWall - height[i]);
        }

        return water;
    }
}*/
