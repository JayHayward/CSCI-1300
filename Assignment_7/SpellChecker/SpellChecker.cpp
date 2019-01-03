#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"
using namespace std;

//function that takes a string and removes all punctuation
string stripPunct(string sentence)
{
    string noPunct="";

    for(int i=0; (unsigned)i<sentence.length(); i++)
    {
        if((sentence[i]>='A')&&(sentence[i]<='Z'))
        {
            sentence[i]=sentence[i]+32;  //capital -> lowercase
        }

        if(((sentence[i]>='a')&&(sentence[i]<='z'))||(sentence[i]==' '))
        {
            noPunct=noPunct+sentence[i];  //punctuation removed
        }
    }
    return noPunct;
}

SpellChecker::SpellChecker()  //constructor
{

}

SpellChecker::SpellChecker(string lang)  //constructor
{
    language=lang;
}

SpellChecker::SpellChecker(string lang, string validFilename, string correctedFilename)  //constructor
{
    language=lang;
    valid=validFilename;
    corrected=correctedFilename;
    //array_index=-1;  //index that transcends functions
}

bool SpellChecker::set_start_marker(char sMark)
{
    start_marker=sMark;
    if(start_marker==sMark)
    {
        return true;
    }
    return false;
}

bool SpellChecker::set_end_marker(char eMark)
{
    end_marker=eMark;
    if(end_marker==eMark)
    {
        return true;
    }
    return false;
}

char SpellChecker::get_start_marker()
{
    return start_marker;
}

char SpellChecker::get_end_marker()
{
    return end_marker;
}

//calls transcendental index
int SpellChecker::get_array_index()
{
    return array_index;
}

bool SpellChecker::readValidWords(string filename)
{
    string line;
    ifstream valid;
    valid.open(filename);

    if(valid)
    {
        while(!valid.eof())
        {
            //int i=get_array_index()+1;
            int i=0;
            while(getline(valid, line))  //call words line by line
            {
                validWords[i]=line;  //array is a list of words from file
                i++;
            }
            //array_index=i;
        }

        return true;  //if file is opened
    }

    return false;  //if file fails
}

bool SpellChecker::readCorrectedWords(string filename)
{
    string line;
    ifstream corrected;  //file of misspelled and corrected words
    corrected.open(filename);

    if(corrected)
    {
        while(!corrected.eof())
        {
            //int i=get_array_index()+1; //is this necessary? Am I creating a new list or expanding off one I already have?
            int i=0;
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
            //array_index=i;
            rowCount=i;
        }

        return true;  //if file opens
    }

    return false;  //if file fails
}

string SpellChecker::repair(string sentence)
{
    sentence=stripPunct(sentence);
    //if correctedWords[i][0], return correctedWords[i][1]
    for(int i=0; i<rowCount; i++)
    {
        for(int j=0; j<rowCount; j++)
        {
            if(sentence==validWords[j])
            {
                validWords[j];
            }
        }

        if(correctedWords[i][0]==sentence)  //if the sentence is on the list of misspelled
        {
            return correctedWords[i][1];  //return corrected
        }

        if(i==rowCount)  //if no valid misspelled word is found
        {
            string markedWord=correctedWords[i][0];  //misspelled word
            char x=get_start_marker();
            char y=get_end_marker();
            markedWord=x+markedWord+y;

            return markedWord;
        }
    }
}
