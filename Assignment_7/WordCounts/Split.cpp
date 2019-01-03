#include <iostream>
using namespace std;

int split(string str, char s, string words[], int size)
{
    int count=0;
    string temp="";
    int k=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==s)
        {
            words[k]=temp;
            temp="";
            count++;
            k++;
        }
        else if(i == str.length()-1)
        {
            temp = temp+str[i];
            words[k]=temp;
            count++;
        }
        else
        {
            temp=temp+str[i];
        }
    }
    return count;
}

int main()
{
    string words[4];
    string str="this is a test";
    split(str, ' ', words, str.length());
    //cout<<x<<endl;

    for(int i=0; i<4; i++)
    {
        cout<<words[i]<<endl;
    }
}

