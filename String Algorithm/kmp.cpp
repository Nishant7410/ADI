#include<iostream>
#include<string.h>
using namespace std;
int* computeArray(char* data)
{
    int *arr=new int[strlen(data)];
    arr[0]=0;
    int i=0;
    int count=0;
    int j=0;
    for ( i = 1; data[i]!='\0' ; i++)
    {
        if(data[i]==data[j])
        {
            count++;
            arr[i]=count;
            j++;
        }
        else
        {
            j=0;
            count=0;
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
        if(j==strlen(data))
        {
            cout<<"Index :"<<i-j<<endl;
            j=arr[j-1];
        }
        else if(i<strlen(txt) && data[j]!=txt[i])
        {
            if(j!=0)
            {
                j=arr[j-1];
            }
            else
            {
                i++;
            }

        }
    }
}

int main()
{
    char data[50];
    char txt[50];
    cin>>txt>>data;
    kmp(txt,data);
}
