//Justin Hayward
//CSCI 1300-106, Tom
//
//Assignment 7

#include <iostream>
#include <sstream>
#include <algorithm>
#include "WordCounts.h"
using namespace std;

//stripPunctW removes all punctuation from a string
//function starts by changing ever character to lowercase
//once every character is lowercase, it searches for and removes punctuation
//returns the new edited string
string stripPunctW(string sentence)
{
    string noPunct="";

    for(int i=0; (unsigned)i<sentence.length(); i++)
    {
        if((sentence[i]>='A')&&(sentence[i]<='Z'))
        {
            sentence[i]=sentence[i]+32; //capital -> lowercase
        }

        if(((sentence[i]>='a')&&(sentence[i]<='z'))||(sentence[i]==' '))
        {
            noPunct=noPunct+sentence[i];
        }
    }
    return noPunct;
}

//sortDescending is a bubble sort that takes an integer array and orders it from high to low
//function takes an integer array, string array, and mutual size of the arrays as parameters
//every count is correlated to a word. As the count gets sorted, so do the words
//this function is used to list the words in descending frequency in a list of words
//this function is created mainly for use in getTally
//function does not return anything, but fills and sorts two arrays
void sortDescending(int arrCounts[], string arrWords[], int size) //bubble sort high -> low
{
    bool sorted=false;
    while(sorted==false)
    {
        sorted=true;
        for(int i=0; i<size-1; i++)
        {
            if(arrCounts[i]<arrCounts[i+1])
            {
                swap(arrCounts[i], arrCounts[i+1]);  //order counts
                swap(arrWords[i], arrWords[i+1]);  //order words
                sorted=false;
            }
        }
    }
}

//default constructor
//function initializes the tally
WordCounts::WordCounts()
{
    tally=0;
}

//resetTally, intuitively, resets the count of tally to 0
//function does not return a value, but modifies a private data member
void WordCounts::resetTally()
{
    tally=0;
}

//set_wordsList is a personal setting function
//given a string as parameters, it alters the data member wordsList to equal that string
void WordCounts::set_wordsList(string words)
{
    wordsList=words;
}

//add_wordsList modifies a private data member
//function takes a string as parameters.
//it takes wordsList and adds the given string to it, after adding a space
//function does not return anything, but modifies a data member
void WordCounts::add_wordsList(string words)
{
    wordsList=wordsList+" "+words;
}

//get_words list is a getting function for the private data member wordsList
//function returns the string of wordsList
string WordCounts::get_wordsList()
{
    return wordsList;
}

//I approached the function tallyWords in an unconventional way
//tallyWords takes a string as parameters
//function removed all punctuation in a string and adds the modified string to wordsList
//As opposed to making an array of word tallies, I took a shortcut
//tallyWords does not return a value, but adds a string to wordsList to be utilized in getTally
void WordCounts::tallyWords(string sentence)
//all this does is add sentence to a string in my .h
{
    sentence=stripPunctW(sentence);
    add_wordsList(sentence);
}

//getTally gets the frequency of a word in a string of words
//As opposed to creating a list of every tally for every word, I chose to focus on one word at a time
//getTally takes a string as parameters
//getTally utilizes stringstreams to look at every word in a string until it finds a matching word
//every time the function find an instance of the target word, it adds 1 to the tally of that word
//function returns an integer that is the number of instances of the target word in a string
int WordCounts::getTally(string word)
{
    tally=0;

    string str=get_wordsList(); //gets the wordsList stream from the class header
    str=stripPunctW(str);
    stringstream wordStream(str);
    string line;

    while(getline(wordStream, line, ' '))  //line = any word in str
    {
        if(line==word)
        {
            tally++;
        }
    }
    return tally;
}

//mostTimes finds the n most frequent words in an array of words
//mostTimes takes two empty arrays, an array of strings, an array of integers, and an integer as parameters
//function fills the arrays with the n words and their respective counts
//the function first pulls wordsList and removes the punctuation
//the function divides the string into words via stringstream separated with spaces
//the function checks every word to see if it exists in the array words[]
//if not, the function adds the word to the array
//once words[] is filled, the function calls getTally to fill counts[] with each words' frequency at the respective index
//once counts[] is filled, the members of the array are sorted from highest to lowest
//as each counts[] index is swapped,so is the corresponding words[] index
//the function successfully sorts the words and counts from highest frequency to lowest
//the function returns the largest count
int WordCounts::mostTimes(string words[], int counts[], int n)
{
    string str=get_wordsList(); //make sure tallyWords is called
    str=stripPunctW(str); //may be unnecessary

    if(str=="") //if string is empty
    {
        //cout<<"Count: 0"<<"Most common: 0";
        return 0;
    }

    stringstream wordStream(str);
    string line;
    int count=0;
    int i=0;
    while(getline(wordStream, line, ' ')) //line = any word in str
    {
        bool found=false;
        for(int j=0; j<i; j++)
        {
            if(words[j]==line)  //if I have already found the word in str
            {
                found=true;
            }
        }

        if((found==false)&&(line!=""))  //if the word is not already in words[]
        {
            words[i]=line; //words[] is now an array of words in WordsList
            count++;
            i++;
        }
    }


    int size=count; //count is # of words in wordStream

    for(int j=0; j<size; j++)
    {
        string targetWord=words[j];
        counts[j]=getTally(targetWord); //counts[] is now an array of word frequency
    }

    sortDescending(counts, words, size); //sortedCounts[] is now descending. sortedCounts[0] is most frequent
    //this is so that I can still reference words[] with the index number

    return counts[0];
}
