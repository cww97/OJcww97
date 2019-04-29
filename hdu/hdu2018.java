//package test;
import java.util.*;
public class Main{
	public static void main(String [] args){
		int n,i;
		int[]a=new int[60];
		a[1]=1;
		a[2]=2;
		a[3]=3;
		a[4]=4;
		for (i=5;i<=55;i++){
			a[i]=a[i-3]+a[i-1];
		}
		Scanner cin = new Scanner (System.in);
		while(cin.hasNext()){
			n=cin.nextInt();
			if(n==0) break;
			System.out.println(a[n]);
		}
		
	}
	 
}