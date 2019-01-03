#include <iostream>
using namespace std;

void stripPunct(string sentence)
{
    string noPunct="";

    for(int i=0; i<sentence.length(); i++)
    {
        if((sentence[i]>='A')&&(sentence[i]<='Z'))
        {
            sentence[i]=sentence[i]+32;
        }

        if((sentence[i]>='a')&&(sentence[i]<='z'))
        {
            noPunct=noPunct+sentence[i];
        }
    }
}

int main()
{

}
