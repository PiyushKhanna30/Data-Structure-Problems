class Solution {
    public int minSetSize(int[] arr) {
        int arrSize = arr.length;
        Map<Integer, Integer> numFreq = new HashMap<>();
        for (int n : arr)
            numFreq.put(n, numFreq.getOrDefault(n, 0) + 1);

        int[] freqs = new int[arrSize + 1];
        for (int value : numFreq.values())
            freqs[value] += 1;

        int currSize = 0;
        int ans = 0;
        int i = freqs.length-1;
        while (currSize * 2 < arrSize && i>0) {
            if (freqs[i] > 0) {
                currSize += i;
                freqs[i] -= 1;
                ans += 1;
            } else {
                i--;
            }
        }
        return ans;
    }
}

/**
class Solution {
    public int minSetSize(int[] arr) {
        int n = arr.length;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : arr) {
            if (freq.containsKey(num))
                freq.put(num, freq.get(num) + 1);
            else
                freq.put(num, 1);
        }
        List<Integer> values = new ArrayList<>();
        for(int val : freq.values())
            values.add(val);
        
        Collections.sort(values);

        
        int res = 0;
        int n2 = 0;
        for (int i = values.size() - 1; i >= 0; i--) {
            n2 += values.get(i);
            res += 1;
            if (n2 * 2 >= n) return res;
        }
        return res;
    }
}
**/
