class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int[] ans = new int[nums.length];
        int k = 0;
        int evenSum = Arrays.stream(nums).filter(x -> x % 2 == 0).sum();
        for (int[] query : queries) {
            evenSum -= nums[query[1]] % 2 == 0 ? nums[query[1]] : 0;
            nums[query[1]] += query[0];
            evenSum += nums[query[1]] % 2 == 0 ? nums[query[1]] : 0;
            ans[k++] = evenSum;
        }
        return ans;
    }
//    BRUTE FORCE
    /*
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int[] ans = new int[nums.length];
        int k = 0;
        for (int[] query : queries) {
            nums[query[1]] += query[0];
            ans[k++] = sumOfEven(nums);
        }
        Arrays.stream(ans).forEach(System.out::println);
        return ans;
    }

    private int sumOfEven(int[] nums) {
        return Arrays.stream(nums).filter(x -> x % 2 == 0).sum();
    }
    */
}
