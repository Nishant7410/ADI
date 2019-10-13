import java.util.*;
import java.lang.*;
public class Noofwords
{
public static void main(String ar[])
{
Scanner sc=new Scanner(System.in);
String str=sc.nextLine();
str=str.trim().replaceAll("\\s{1,}"," ");
String ch[]=str.split(" ");
HashMap<String,Integer>map=new HashMap<String,Integer>();
for(int i=0;i<ch.length;i++)
{
if(map.containsKey(ch[i]))
{
map.put(ch[i],map.get(ch[i])+1);
}
else
map.put(ch[i],1);
}
map.forEach((key,value)->System.out.println(key+" : "+value));
}
}