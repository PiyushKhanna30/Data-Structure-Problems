/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		while(t!=0){
		    t-=1;
		    int n = sc.nextInt();
    		String s = String.valueOf(n);
    		if(s.length()<1)
    		    System.out.println(n);
    		else{
    		    int d = 1;
    		    for(int i=s.length()-1;i>0;i--)
    		        d*=10;
    		    int l = n%10;
    		    int f = n/d;
    		    System.out.println(l+f);
		    } 
		    
		}
	}
}
