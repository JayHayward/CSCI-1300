//Justin Hayward
//CSCI 1300-106, Tom
//
//Assignment 7

#include <iostream>
#include <sstream>
#include "WordCounts.h"
#include "SpellChecker.h"
#include "SpellChecker.cpp"
#include "WordCounts.cpp"

using namespace std;

int main()
{
    SpellChecker sc;

    SpellChecker sc2("Spanish");
    cout<<"language is set as: "<<sc2.language<<endl;

    SpellChecker sc3("English", "VALID_WORDS_3000.txt", "MISSPELLED.txt");
    cout<<"language is set as: "<<sc3.language<<endl;
    cout<<"valid words read? "<<sc3.readValidWords("VALID_WORDS_3000.txt")<<endl;
    cout<<"corrected words read? "<<sc3.readCorrectedWords("MISSPELLED.txt")<<endl;
    cout<<endl;

    sc2.readValidWords("VALID_WORDS_3000.txt");
    sc2.readCorrectedWords("MISSPELLED.txt");
    sc2.readCorrectedWords("Text2English.txt");

    cout<<sc2.setStartMarker('#')<<'\t';
    cout<<sc2.getStartMarker()<<endl;
    cout<<sc2.setEndMarker('&')<<'\t';
    cout<<sc2.getEndMarker()<<endl;
    cout<<endl;

    cout<<sc2.repair("today")<<endl;  //in both files
    cout<<sc2.repair("todayy")<<endl;  //only in corrected
    cout<<sc2.repair("emotional")<<endl;  //only in valid
    cout<<sc2.repair("emotionall")<<endl;  //in neither
    cout<<sc2.repair("shskjdfh")<<endl;  //nonsense
    cout<<endl;

    cout<<sc2.repair("hello team")<<endl;  //multiword correct/correct
    cout<<sc2.repair("hallo midia")<<endl;  //multiword misspelled/misspelled
    cout<<sc2.repair("comedy world")<<endl;  //multiword valid/valid
    cout<<sc2.repair("comedy tem")<<endl;  //multiword valid/misspelled
    cout<<sc2.repair("***today***")<<endl;  //multiple non-alpha characters correct
    cout<<sc2.repair("&&&tod&ayy&&&")<<endl;  //multiple non-alpha characters misspelled
    cout<<sc2.repair("")<<endl;  //length of zero

    cout<<endl;

    WordCounts wc;
    wc.tallyWords("the blue brown fox fox");  //add string to wordsList
    wc.tallyWords("the the green cat");  //add string to wordsList
    cout<<wc.get_wordsList()<<endl;
    cout<<"frequency of \"the\": "<<wc.getTally("the")<<endl;
    cout<<"frequency of \"cat\": "<<wc.getTally("cat")<<endl;
    cout<<"frequency of \"fox\": "<<wc.getTally("fox")<<endl;
    cout<<endl;

    wc.set_wordsList("");  //reset wordsList
    wc.add_wordsList("this is added to wordList");
    cout<<wc.get_wordsList()<<endl;  //test get_wordsList
    wc.set_wordsList("");
    wc.resetTally();  //reset tally
    cout<<endl;

    wc.tallyWords("the the the the the the the the");
    wc.tallyWords("be be be be");
    wc.tallyWords("to to");
    wc.tallyWords("of");

    string wordArr[4];
    int countArr[4];

    wc.mostTimes(wordArr, countArr, 4);
    cout<<"Four most common English Words: "<<endl;

    for(int i=0; i<4; i++)
    {
        cout<<wordArr[i]<<"  "<<countArr[i]<<endl;
    }
}
