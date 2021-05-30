//Iterative
// Time O(n) Space O(1)
class Reverse
{
    public static String reverseWord(String str)
    {
        char []arr = str.toCharArray();
        int l = arr.length-1;
        int s = 0;
        while(s<l){
            char c = arr[s];
            arr[s] = arr[l];
            arr[l] = c;
            s+=1;
            l-=1;
        }
        return String.valueOf(arr);
    }
}

//Recursive
// Time O(n) Space O(n)
class Reverse
{
    public static String reverseWord(String str)
    {
        char arr[] = str.toCharArray();
        rev(arr,0,arr.length-1);
        return String.valueOf(arr);
    }
    private static void rev(char[] arr, int s, int l){
        if(s<l){
            char c = arr[s];
            arr[s] = arr[l];
            arr[l] = c;
            rev(arr, s+1, l-1);
        }
        return;
    }
}