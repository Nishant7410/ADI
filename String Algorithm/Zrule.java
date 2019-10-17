import java.util.*;
public class Zrule
{
    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        
        // first method to solve the Z algo in O(n)
       /* String bstr=sc.nextLine();
        String sstr=sc.next();
        int j=0,c=0;
        int arr[]=new int[bstr.length()];
        for(int i=0;i<bstr.length();i++)
        {
            if(j==sstr.length())
                j=0;
            if(sstr.charAt(j)==bstr.charAt(i))
            {
               
                c++;
                if(c==sstr.length())
                {
                    arr[i-j]=1;
                    c=0;
                }
                 j++;
                
            }
            else
            {
                c=0;
                j=0;
            }
        }
        for(int i=0;i<bstr.length();i++)
         if(arr[i]==1)
                System.out.println(i);*/
        
        
        
        
        //second method to solve the Z algo in O(n^2)
        String text=sc.nextLine();
        String pattern=sc.nextLine();
        String str="";
        str+=pattern;
        str+="$";
        str+=text;
        for(int i=1;i<str.length();i++)
        {
            if(str.charAt(i)==str.charAt(0))
            {
                int j=0;
                int k=i;
                int c=0;
                while(j<str.length()&&k<str.length()&&str.charAt(j)==str.charAt(k))
                {
                    k++;
                    j++;
                    c++;
                }
                if(c==pattern.length())
                    System.out.println("Index is "+(i-pattern.length()-1));
            }
        }
    }
}