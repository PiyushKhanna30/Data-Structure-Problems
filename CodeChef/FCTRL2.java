/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    static BigInteger dp[];
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t!=0){
		    t-=1;
		    int n = sc.nextInt();
		    if(n>=1){
		        BigInteger a =BigInteger.ONE;
		        for (int i=n;i>0 ;i-- )
		            a=a.multiply(BigInteger.valueOf(i));
		        System.out.println(a);
		    }
		    else{
		        System.out.println(1);
		    }
		}
	}
}
