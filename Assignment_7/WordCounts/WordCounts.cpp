#include "WordCounts.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string stripPunct(string sentence)
{
    string noPunct="";

    for(int i=0; (unsigned)i<sentence.length(); i++)
    {
        if((sentence[i]>='A')&&(sentence[i]<='Z'))
        {
            sentence[i]=sentence[i]+32;
        }

        if(((sentence[i]>='a')&&(sentence[i]<='z'))||(sentence[i]==' '))
        {
            noPunct=noPunct+sentence[i];
        }
    }
    return noPunct;
}

void sortDescending(int arr[], int size) //bubble sort high -> low
{
    //int size=(sizeof(arr)/sizeof(*arr));

    bool sorted=false;
    while(sorted==false)
    {
        sorted=true;
        for(int i=0; i<size-1; i++)
        {
            if(arr[i]<arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                sorted=false;
            }
        }
    }
}

WordCounts::WordCounts()
{
    tally=0;
}

void WordCounts::resetTally()
{
    tally=0;
}

void WordCounts::set_wordsList(string words)
{
    wordsList=words;
}

void WordCounts::add_wordsList(string words)
{
    wordsList=wordsList+words;
}

string WordCounts::get_wordsList()
{
    return wordsList;
}

void WordCounts::tallyWords(string sentence)
//all this does is add sentence to a string in my .h
{
    sentence=stripPunct(sentence);
    add_wordsList(sentence);
}

int WordCounts::getTally(string word)
{
    string str=get_wordsList();
    str=stripPunct(str);
    stringstream wordStream(str);
    string line;

    while(getline(wordStream, line, ' '))
    {
        if(line==word)
        {
            tally++;
        }
    }
    return tally;
    return 0;
}

int WordCounts::mostTimes(string words[], int counts[], int n)
{
    string str=get_wordsList();
    str=stripPunct(str); //may be unnecessary
    //do I need to output the word exactly how I got it?

    stringstream wordStream(str);
    string line;

    int count=0;
    int i=0;
    while(getline(wordStream, line, ' '))
    {
        words[i]=line; //words[] is now an array of words in WordsList
        count++;
        i++;
    }

    //int size=(sizeof(words)/sizeof(*words)); //size for both arrays is the same
    int size=count; //count is # of words in wordStream

    for(int j=0; j<size; j++)
    {
        string targetWord=words[j];
        counts[j]=getTally(targetWord); //counts[] is now an array of word frequency
    }

    int sortedCounts[size];
    for(int k=0; k<size; k++)
    {
        sortedCounts[k]=counts[k]; //parse counts[] into sortedCounts[]
    }

    sortDescending(sortedCounts, size); //sortedCounts[] is now descending. sortedCounts[0] is most frequent
    //this is so that I can still reference words[] with the index number

    string returnWords[size]; //words that will be parsed into words[]

    for(int i=0; i<n; i++) //fill returnWords with words of descending frequency
    {
        int x=sortedCounts[i];
        for(int j=0; j<size; j++)
        {
            if(counts[j]==x)
            {
                //index=j;  //index shared by both counts[] and words[]
                returnWords[i]=words[j];
            }
        }
    }

    for(int z=0; z<n; z++) //parse the arrays to the desired output
    //this messing up the arrays beyond repair, perform this last
    {
        words[z]=returnWords[z];
        counts[z]=sortedCounts[z];
    }

    return n; //get clarification on the return
}
