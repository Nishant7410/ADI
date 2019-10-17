#include<iostream>
#include<string.h>
using namespace std;
int* computeArray(char* data)
{
    int *arr=new int[strlen(data)];
    arr[0]=0;
    int i=0;
    int count=0;
    int j=1;
    while(j<strlen(data))
    {
        if(data[i]==data[j])
        {
            arr[j]=i+1;
            i++;
            j++;
        }
        else if(i==0)
        {
            arr[j]=0;
            j++;
        }
        else
        {
            i=arr[i-1];
        }
    }
    return arr;
}

void kmp(char *txt,char *data)
{
    int *arr=computeArray(data);
    int i=0;
    int j=0;
    while(i<strlen(txt))
    {
       if(txt[i]==data[j])
       {
           i++;
           j++;
       }
       else
       {
           if(j==0)
            i++;
           else
           {
               j=arr[j-1];
           }
       }
       if(j==strlen(data))
        cout<<"Index is "<<i-j<<endl;
    }
}

int main()
{
    char data[50];
    char txt[50];
    cin>>txt>>data;
    kmp(txt,data);
}
