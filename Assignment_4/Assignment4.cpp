//Author: Justin Hayward
//CSCI 1300 - Rec 106,Tom Lillis
//
//Assignment 4

#include <iostream>
using namespace std;

//Finds a margin of error between two strings and returns 1-(margin of error)
float similarityScore(string sequence1, string sequence2)
{
    //int len = sequence1.length();

    if (sequence1.length() == sequence2.length()) //function only works if length are the same
    {
        int len = sequence1.length();

        int hamDistance = 0; //hammering distance = number of mismatches
        for (int i =0; i<sequence1.length(); i++)
        {
            //float hdistance; //hammering distance

            if(sequence1[i] != sequence2[i])
                hamDistance++;
        }
        float similarity_score; //the value I will return

        similarity_score = (((1.0*len-hamDistance))/len); //makes length a float
        return similarity_score;
    }
    return 0; //if initial "if" condition is satisfied, function will return 0
}

//function that counts the matches between a genome and sequence assuming its similarityScore is above min_score
int countMatches(string genome, string sequence1, float min_score)
{
    int matches = 0;
    int len = sequence1.length(); //simplifies calculations

    for(int i=0; i<=(genome.length()-sequence1.length()); i++)
        //a genome string will go over the limit of the sequence1 string. this ensures that that there isn't a time that i goes over a limit
    {
        float score = similarityScore(sequence1, genome.substr(i, len)); //finds the similarity variable of the genome and sequence 1
        //genome.substr(i, len) brings the genome sequence to the same length as sequence 1 so it can run in similarityScore
        if (score >= min_score)
        {
            //only resolves if its similarity score is greater than min_score
            matches++;
        }
    }
    return matches;
}

//function that finds a sequence with the least differences from genome
//difference is determined by similarityScore
//mainly used to call in part 4 of the assignment
float findBestMatch (string genome, string sequence)
{
    int len = sequence.length();

    float maxScore = 0; //variable to determine highest score
    for (int i=0; i<=(genome.length()-sequence.length()); i++)
    {
        float score = similarityScore(sequence, genome.substr(i, len));
        if (score > maxScore) //renews the highest score at every iteration
            maxScore = score;
    }
    return maxScore;
}

//finds the which genome 1,2, or 3,has the closest similarity between a given sequence
int findBestGenome(string genome1, string genome2, string genome3, string seq)
{
    float similG1, similG2, similG3; //variables that will store genome similarities to the sequence
    int bestGenome; //value to return

    //set variables that determine the similarities between the sequence and genomes
    similG1 = findBestMatch(genome1, seq);
    similG2 = findBestMatch(genome2, seq);
    similG3 = findBestMatch(genome3, seq);

    if ((similG1>similG2)&&(similG1>similG3)) //G1 >G2 & >G3
        bestGenome = 1;
    else if ((similG2>similG1)&&(similG2)>similG3) //G2 >G1 & >G3
        bestGenome = 2;
    else if ((similG3>similG1)&&(similG3>similG2)) //G3 >G1 & >G2
        bestGenome = 3;

    else
        return 0;

    return bestGenome;
}
