#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H

#include <iostream>
using namespace std;

class WordCounts
{
    public:
        WordCounts();
        void tallyWords(string sentence);
        int getTally(string word);
        void resetTally();

        string get_wordsList();
        void set_wordsList(string words);
        void add_wordsList(string words);

        int mostTimes(string words[], int counts[], int n);

    private:
        int tally;
        string wordsList;
};

#endif
