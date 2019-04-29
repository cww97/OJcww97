//hdu2020
//by cww97
package test;
import java.util.*;

public class hdu2020{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int n;
		int[]a=new int[100];
		while (cin.hasNext()){
			n=cin.nextInt();
			if (n==0)break;
			for (int i=0;i<n;i++) a[i]=cin.nextInt();
			for (int i=0;i<n-1;i++)
				for (int j=i+1;j<n;j++)
					if (Math.abs(a[i])<Math.abs(a[j])){
						int tmp=a[i];a[i]=a[j];a[j]=tmp;
					}
			for (int i=0;i<n-1;i++)System.out.print(a[i]+" ");
			System.out.println(a[n-1]);
		}
	}
}