#include<iostream>
#include<string.h>
using namespace std;
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}
int word(string str)
{
    int size1=str.size();
    if(size1==0)
        return true;
    bool res[size1+1];
    memset(res,0,sizeof(res));
    for(int i=1;i<=size1;i++)
    {
        if(res[i]==false&&dictionaryContains(str.substr(0,i)))
        res[i]=true;
        if(res[i]==true)
        {
            if(i==size1)
            return true;
            for(int j=i+1;j<=size1;j++)
            {
                if(res[j]==false&&dictionaryContains(str.substr(i,j-i)))
                res[j]=true;
                if(j==size1&&res[j]==true)
                    return true;
            }

        }

    }
    return false;

}
int main()
{
    string str;
    cin>>str;
    cout<<word(str);
}
