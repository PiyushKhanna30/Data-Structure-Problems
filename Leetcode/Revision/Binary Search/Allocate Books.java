import java.util.ArrayList;
public class Solution {
    public static int findPages(ArrayList<Integer> arr, int n, int m) {
        // Write your code here.
        if(n<m)return -1;
        int start = 1;
        int end = 0;
        for(int i=0;i<n;i++){
            start = Math.max(start, arr.get(i));
            end += arr.get(i);
        }
        int ans = end;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(isValid(arr, n, mid, m)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    static boolean isValid(ArrayList<Integer>arr, int n, int mid, int m){
        int pages = 0;
        for(int i =0;i<n;i++){
            if(pages+arr.get(i)<=mid){
                pages += arr.get(i);
            }
            else{
                m-=1;
                pages = arr.get(i);
            }
            if(m==0)return false;
        }
        return true;
    }
}
