class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int mod = 1000000000 + 7;
        int arr[][] = new int[n][2];
        for(int i = 0; i<n; i++){
            arr[i] = new int[] {efficiency[i],speed[i]};
            
        }
        
        Arrays.sort(arr, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0]>=b[0]?-1:1;
            }
        });
        
        // System.out.println("--");   
        Queue<Integer>q = new PriorityQueue<>(k);
        long res = 0;
        long s = 0;
        
        for(int i=0;i<n;i++){
            s+=arr[i][1];
            q.add(arr[i][1]);
            if(q.size()>k)s-=q.poll();
            res = Math.max(res,s*arr[i][0]);
            
        }
        return (int)(res%mod);
    }
    
        
//         Arrays.sort(arr, new Comparator<int[]>(){
//             public int compare(int[] a, int[] b){
//                 return a[0]>=b[0]?1:-1;
//             }
//         });
        
//         // System.out.println("--");   
//         long res = 0;
//         for(int i=0;i<n;i++){
//             System.out.print(arr[i][0]+": ");   
//             Queue<Integer>q = new PriorityQueue<>();
//             long e = arr[i][0];
//             long s = 0;
//             for(int j=i;j<n;j++){
//                 System.out.print(arr[j][1]+" ");
//                 s+=arr[j][1];
//                 q.add(arr[j][1]);
//                 if(q.size()>k){
//                     s-=q.poll();
//                 }
//             }
//             res = Math.max(res,s*e);
//             System.out.println();
//         }
//         return (int)(res%mod);
//     }
}
