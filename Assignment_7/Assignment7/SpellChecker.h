//Justin Hayward
//CSCI 1300-106, Tom
//
//Assignment 7

#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>
using namespace std;

class SpellChecker
{
public:
    SpellChecker();
    SpellChecker(string);
    SpellChecker(string, string, string);

    ~SpellChecker();

    string language; //member

    bool readValidWords(string);
    bool readCorrectedWords(string);
    string repair(string);

    bool setStartMarker(char);
    bool setEndMarker(char);

    char getStartMarker();
    char getEndMarker();

private:
    char start_marker;
    char end_marker;
    string validWords[10000];
    string correctedWords[10000][2];
    int corRowCount;
    int valRowCount;
};
#endif // SPELLCHECKER_H
