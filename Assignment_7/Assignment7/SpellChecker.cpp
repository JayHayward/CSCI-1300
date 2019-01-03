//Justin Hayward
//CSCI 1300-106, Tom
//
//Assignment 7

#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"
using namespace std;

//default constructor
//initializes corRowCount and valRowCount
SpellChecker::SpellChecker()
{
    corRowCount=0;
    valRowCount=0;
}

//constructor that takes a string and sets the language of the class
//initializes corRowCount and valRowCount
SpellChecker::SpellChecker(string lang)
{
    corRowCount=0;
    valRowCount=0;
    language=lang;
}

//constructor that sets the language of the object as well as fill the arrays validWords[] and correctedWords[][]
//initializes corRowCount and valRowCount
SpellChecker::SpellChecker(string lang,string validFilename,string correctedFilename)
{
    corRowCount=0;
    valRowCount=0;
    language=lang;
    readValidWords(validFilename); //fills ValidWords[] in constructor
    readCorrectedWords(correctedFilename); //fills correctedWords[][] in constructor
}

SpellChecker::~SpellChecker()
{
    //dtor
}

//stripPunctS removes the punctuation at the beginning and end of words in a string
//function loops through a string and checks if every index is alphabetical
//if an index is not alphabetical and not a space, it checks either side of the index
//if either side of a non-letter is a space, the non-letter is removed
//finally the function tests the last index of the sentence, if it's non-letter it is deleted
//if there are non-letters surrounded by alpha characters it is kept
//function turns all capital characters into lowercase
//function returns the edited string
string stripPunctS(string sentence)
{
    int len=sentence.length();
    int i=0;
    while(i<len)
    {
        if((!isalpha(sentence[0]))&&(sentence[0]!=' '))
        {
            sentence.erase(0,1);
        }
        len=sentence.length();

        if((!isalpha(sentence[len-1]))&&(sentence[len-1]!=0))
        {
            sentence.erase(len-1, 1);
        }
        len=sentence.length();

        if(!isalpha(sentence[i]))
        {
            if((sentence[i-1]==' ')||(sentence[i+1]==' '))
            {
                sentence.erase(i,1);
            }
        }

        for(int i=0; (unsigned)i<len; i++)
        {
            if((sentence[i]>='A')&&(sentence[i]<='Z'))
            {
                sentence[i]=sentence[i]+32; //capital -> lowercase
            }
        }
        i++;
    }
    return sentence;
}

//readValidWords takes words from a file of valid words an parses them into an array
//function opens a file and reads each line, passing them into an array
//function returns true if the file is correctly opened, false if not
//function also counts the lines it goes through and counts the number of lines read
//function sets valRowCount to the number  of lines read
//function fills an array
bool SpellChecker::readValidWords(string filename)
{
    string line;
    ifstream valid;
    valid.open(filename);

    if(valid)
    {
        while(!valid.eof())
        {
            int i=valRowCount;
            while(getline(valid, line))  //call words line by line
            {
                validWords[i]=line;  //array is a list of words from file
                i++;
            }
            valRowCount=i;
        }

        return true;  //if file is opened
    }

    return false;  //if file fails
}

//readCorrectedWords takes a file and uses its contents to fill a 2D array
//the file contains misspelled and corrected words, separated by a tab
//the function is read in line by line and made into a string
//function uses stringstream to separate the file further to parse into a 2D array
//the first and second columns of the matrix are separated by tabs
//after every corrected word,the file is separated by new lines
//there are only 2 columns in the file, so the second index of the array is either 0 or 1
//function returns true if the file is read in correctly, false if not
//function fills in a 2D array
//function also sets corRowCount to the number of lines read
bool SpellChecker::readCorrectedWords(string filename)
{
    string line;
    ifstream corrected;  //file of misspelled and corrected words
    corrected.open(filename);

    if(corrected)
    {
        while(!corrected.eof())
        {
            int i=corRowCount;
            while(getline(corrected, line))
            {
                string first;
                string second;
                stringstream linestream(line);
                getline(linestream, first, '\t');  //first is words from the first column, delimiter tab
                getline(linestream, second, '\n');  //second is words from the second column, delimiter new line

                correctedWords[i][0]=first;  //first part(misspelled)
                correctedWords[i][1]=second;  //second part(corrected)
                i++;
            }
            corRowCount=i; //rows in misspelled/correct word file
        }

        return true;  //if file opens
    }

    return false;  //if file fails
}

//setStartMarker sets the value of the variable start_marker
//function checks the variable, if it correctly set, function returns true
bool SpellChecker::setStartMarker(char sMark)
{
    start_marker=sMark;
    if(start_marker==sMark)
    {
        return true;
    }
    return false;
}

//setEndMarker sets the value of the variable end_marker
//function checks the variable, if it correctly set, function returns true
bool SpellChecker::setEndMarker(char eMark)
{
    end_marker=eMark;
    if(end_marker==eMark)
    {
        return true;
    }
    return false;
}

//getStartMarker checks the value of the variable start_marker and returns is
//function returns a character
char SpellChecker::getStartMarker()
{
    return start_marker;
}

//getEndMarker checks the value of the variable end_marker and returns it
//function returns a character
char SpellChecker::getEndMarker()
{
    return end_marker;
}

//repair takes a string sentence and checks the spelling of each word
//function returns the sentence with correct spelling
//function first checks if any word appears in both validWords and removes the one from validWords if it does
//function strips the punctuation from the sentence
//function uses stringstream to separate the sentence into multiple words to be checked
//once a word is corrected, it is added to a new string, fixedSentence to be returned
//function first checks if the word appears in valid words.
//If it does, that word is spelled correctly and is added to fixedSentence
//function next checks if a word appears in the first column of corrected words.
//If so, it is misspelled and the correct spelling is in the second column. Second column is added to fixedSentence
//function checks if the word is in the second column of correctedWords
//if so, that word is spelled correctly and added to fixedSentence
//each check ends in a break to avoid duplication of words
//if the word does not appear in either file, it gets markers added to either side of it and added to fixedSentence
//finally, function checks for remaining spaces and deletes them from the sentence
//function returns the correctly spelled sentence
string SpellChecker::repair(string sentence)
{
    for(int i=0; i<valRowCount; i++)
    {
        for(int j=0; j<corRowCount; j++)
        {
            if(validWords[i]==correctedWords[j][1]) //if the word appears in both files
            {
                validWords[i]="";
            }
        }
    }

    sentence=stripPunctS(sentence);

    stringstream senstream(sentence);
    string line; //line will be the word element in the sentence

    string fixedSentence;

    while(getline(senstream, line, ' '))
    {
        bool found=false;
        for(int i=0; i<valRowCount; i++)
        {
            if(validWords[i]==line)
            {
                fixedSentence=fixedSentence+line+' '; //add the correct word
                found=true;
                break;
            }
        }

        for(int j=0; j<corRowCount; j++)
        {
            if(correctedWords[j][0]==line)
            {
                fixedSentence=fixedSentence+correctedWords[j][1]+' '; //replaced misspelled word with corrected one
                found=true;
                break;
            }

            if(correctedWords[j][1]==line)
            {
                fixedSentence=fixedSentence+line+' '; //add the correct word
                found=true;
                break;
            }
        }

        if(found==false)
        {
            sentence=stripPunctS(line);
            string markedWord=sentence;  //misspelled word
            //char x=getStartMarker();
            //char y=getEndMarker();
            markedWord=getStartMarker()+markedWord+getEndMarker();

            fixedSentence=fixedSentence+markedWord+' ';
        }
    }
    if(fixedSentence[fixedSentence.length()-1]==' ')
    {
        fixedSentence.erase(fixedSentence.length()-1, 1);
    }

    return fixedSentence;
}
