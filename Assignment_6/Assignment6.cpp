//Author: Justin Hayward
//Recitation 106-Tom
//
//Assignment 6

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//avgCharsPerLine reads through a file and finds the average number of letters used
//Function takes a file as a parameter and returns a float value
//Function takes a file, opens it, then checks for success
//If successful, function runs a loop that takes every line and counts the characters
//For every line, it adds 1 to a line counter
//At the end of the loop it takes the number of characters divided by number of lines, returns that value as a float
float avgCharsPerLine(string filename)
{
    string line;
    int lines=0;
    int chars=0;
    ifstream myfile;
    myfile.open(filename);

    if(myfile.is_open())  //if file is not open, disregard code, return -1
    {
        while(!myfile.eof())
        {
            getline(myfile, line);
            for(int i=0; i<line.length(); i++)
            {
                chars++;
            }
            lines++;
        }
        return 1.0*chars/lines;  //find average as a float
    }
    else
        return -1;

    myfile.close();
}

//fillArray takes a file and uses its values to fill a 2D array
//Function takes a file and a 2D array of floating points as parameters and returns the number of lines in the file
//Function must sort through a string of numbers, separating them into single floats
//Function utilizes stringstream to simplify what a split function would have done
//Function turns every line of the file into a stream, separated by a comma
//Function loops through 2 variables, lines and rows
//Function fills the array at every index with the stringstream value associated with that position in the file
//Function fills an array and returns the number of lines in the file
int fillArray(string filename, float arr[][5])
{
    ifstream dataFile;
    string line, headerLine, element;
    int lineCount=0;
    dataFile.open(filename);

    getline(dataFile, headerLine); //calls the first line but does nothing with it.
    //function will now disregard first line.

    if(dataFile.is_open())
    {
        int i=0, j=0;

        while(getline(dataFile, line))  //gets line from datafile
        {
            stringstream linestream(line);  //line is now linestream
            while(getline(linestream, element, ','))  //line, seperated by ',' equals element
            {
                arr[i][j]=stof(element);
                j++;  //moves to next column
            }
            j=0;  //reset columns back to zero

            i++;  //moves to next row
            lineCount++;
        }
    }
    return lineCount;
    dataFile.close();
}

//arrayStats takes the sum of the mean sum of every other row and every other column in an array
//Function takes a file and a 2D array of floats as parameters and returns a float
//Function first takes a file and translates it into an array by calling fillArray
//Function has two for loops, each with a nested loop
//One loop goes through every other row for every column and makes a sum
//Second loop goes through every other column for every row and makes a sum
//Both sums are divided by their respective parameters and added as a total sum
float arrayStats(string filename, float numbers[][5])
{
    int lineCount=fillArray(filename, numbers);  //call fillArray to get a lineCount AND fill the array

    string line, evenLine, element;
    float sumTotal=0;
    float rowSum=0, rowMean=0;
    float colSum=0, colMean=0;
    //I now have a matrix, no need to call file

    //sum of rows (all j, every other i)
    for(int i=1; i<lineCount; i+=2)  //i=row count //i+=2 same as i=i+2
    {
        for(int j=0; j<5; j++)  //j=column count
        {
            rowSum = rowSum + numbers[i][j];  //each sum adds to the previous
        }
    }
    rowMean = rowMean + (rowSum/5);

    //sum of columns (all i, every other j)
    for(int j=1; j<5; j+=2)
    {
        for(int i=0; i<lineCount; i++)  //number of rows is not a set value
        {
            colSum = colSum + numbers[i][j];
        }
    }
    colMean = colMean + (colSum/(lineCount*1.0));

    sumTotal = rowMean + colMean;
    return sumTotal;
}

//search is a function that searches for a specific string in an array of strings
//Function takes an array of strings, size of the array, and a target string and returns an array index as an integer
//Function is a derivation from "search" in assignment 5
//Function is created for use in Part 4
int search(string arr[], int size, string target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}

//countLines reads through a file and counts the number of lines
//Function takes a file as a parameter and returns an integer
//Very fundamental function, created for simplicity and tidiness in Part 4
int countLines(string filename)
{
    string line;
    int count;
    ifstream file;
    file.open(filename);

    if(file)
    {
        while(!file.eof())
        {
            getline(file, line);
            count++;
        }
    }
    file.close();
    return count;
}

//addBookRatings reads a list of users and gathers information on their ratings of different books
//Function takes a file, and array of uses, and a table of ratings as parameters
//Function does not return a value, but fills a 2D array
//Function must first initialize a table to be retrofitted later
//Function reads through every line after the header and separates each value so that they may each be used effectively
//Function first looks for any repetition in users and disregards the repeated name
//Function uses values within a stringstream to fill values of the ratings table at each index
//Function fills the array of users and 2D table of ratings
void addBookRatings(string filename, string users[], int ratings[][50])
{
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<100; j++)
        {
            ratings[i][j]=0;  //initializes the 2D array
        }
    }

    ifstream dataFile;
    dataFile.open(filename);
    string line, header, user, book, rating;
    int count=countLines(filename);  //calls countLines to find number of lines in the file
    int repeat=0;  //integer value that will determine whether or not a user is already listed
    getline(dataFile, header);  //eliminates the first line from the file, as to not include it in the array

    if(dataFile)
    {
        int j=0;
        while(getline(dataFile, line))
        {
            stringstream linestream(line);  //stringstream for simplicity
            getline(linestream, user, ',');  //separates users from the lines
            getline(linestream, book, ',');  //separates book index from the lines
            getline(linestream, rating, ',');  //separates ratings from the lines

            repeat = search(users,50,user);  //returns -1 if user name is repeated
            if(repeat == -1)
            {
                users[j] = user;
                ratings[j][stoi(book)] = stoi(rating);  //creates value at each index of the array
                j++;
            }

            else
            {
                ratings[repeat][stoi(book)] = stoi(rating);
            }
        }
    }

    dataFile.close();
}

int main()
{
    cout<<avgCharsPerLine("Q1.txt")<<endl<<endl;

    float arr[3][5];
    cout<<fillArray("Q2.txt", arr)<<endl;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl<<endl;

    float num[5][5];
    arrayStats("part3.txt", num);
    cout<<arrayStats("part3.txt", num)<<endl;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<num[i][j]<<" ";
        }
    }
    cout<<endl<<endl;

    string users[22];
    int ratings[3][50];
    addBookRatings("part4.txt", users, ratings);

    //this cout only occasionally works and I'm not sure why
    for(int i=0; i<22; i++)
    {
        cout<<users[i];
    }

    //this loop returns a segmentation fault when it should not
    for(int j=0; j<22; j++)
    {
        for(int k=0; k<50; k++)
        {
            cout<<ratings[j][k]<<endl;
        }
    }
}
