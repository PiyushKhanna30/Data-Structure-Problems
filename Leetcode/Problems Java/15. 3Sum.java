class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        Set<List<Integer>> result = new HashSet<>();
        if (len == 0) return new ArrayList<>(result);
        Arrays.sort(nums);
        Arrays.stream(nums).forEach(System.out::println);
        for (int i = 0; i < len; i++) {
            int j = i + 1;
            int k = len - 1;
            while (j < k && k != i) {
                if (nums[i] + nums[j] + nums[k] == 0)
                    result.add(Arrays.asList(nums[i], nums[j++], nums[k--]));
                else if (nums[i] + nums[j] + nums[k] > 0)
                    k -= 1;
                else
                    j += 1;
            }
        }
        return new ArrayList<>(result);
    }
}
