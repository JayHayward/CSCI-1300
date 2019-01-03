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

    string language; //member
    string valid;
    string corrected;

    bool readValidWords(string);
    bool readCorrectedWords(string);
    string repair(string);

    bool set_start_marker(char);
    bool set_end_marker(char);

    char get_start_marker();
    char get_end_marker();

    void set_array_index();
    int get_array_index();

private:
    char start_marker;
    char end_marker;
    int array_index;
    string validWords[];
    string correctedWords[][2];
    int rowCount;
};
#endif // SPELLCHECKER_H
