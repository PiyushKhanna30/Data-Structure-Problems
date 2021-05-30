import java.util.*;
import java.lang.*;
import java.io.*;


// Remember that the class name should be "Main" and should be "public".
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int ans = 0;
		while(n!=0){
		    int t = sc.nextInt();
		    ans += t%k==0?1:0;
		    n-=1;
		}
		System.out.println(ans);
	}
}