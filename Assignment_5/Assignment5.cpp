#include <iostream>
#include <cmath>
using namespace std;

//sumArray adds together all the values in an array
//it takes an array of floats and an integer size as parameters
//function iterates through an array adding each number to a float, sum
//after the last iteration, function returns sum as a float
float sumArray(float array[], int size)
{
    float sum=0;
    for(int i=0; i<size; i++)
    {
        sum=sum+array[i];
    }
    return sum;
}

//search finds the position of a target integer inside an array of integers
//function takes an integer array, the size of the array, and a target integer as parameters
//the function iterates through an array, checking every value to the target integer
//once it finds the target integer, it returns its position in the array as an int
//if the function does not find the target, it returns -1
int search(int arr[], int size, int target)
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

//calculateDifference finds the sum of the squared difference of two arrays
//for every index of the two arrays, the function uses (a[i]-b[i]) and squares it
//function takes two arrays and their size as an integer as parameters
//this function utilizes the pow function in <cmath>
//every time the function runs its equation through an index, it adds the result to a float sum
//function returns sum as a float
float calculateDifference(int a[], int b[], int size)
{
    float sum=0;
    for(int i=0; i<size; i++)
    {
        sum=sum+pow((a[i]-b[i]), 2);
    }
    return sum;
}

//sortArray takes an unsorted array and sorts it into ascending numerical value
//function takes an array of floats and the size of the array as parameters
//the functions uses a basic bubble sort algorithm on the array
//it runs a loop iterating through the array. at every index, if the value is greater than the following, the values are swapped
//this loops until the entire array is sorted
//functions does not return a value, but sorts the array
void sortArray(float unsortArray[], int size)
{
    bool sort=false;
    for(int i=0; sort==false; i++)
    {
        sort=true;
        for (i=0; i<size-1; i++)
        {
            if (unsortArray[i]>unsortArray[i+1])
            {
                swap(unsortArray[i], unsortArray[i+1]);
                sort=false;
            }
        }
    }
}

//copyArray makes a copy of a given array
//the function is given two float arrays and a size as parameters
//the the source array is the array being copied, dest array is the array that will be the copy
//the function iterates through the source array. At every index, it takes the value of source and puts it into dest at the same index
//the function does not return a value, but changes an array
void copyArray(float source[], int size, float dest[])
{
    for(int i=0; i<size; i++)
    {
        dest[i]=source[i];
    }
}

//convert relates every index of an array to a given string expression
//function takes an array of integers,its size, and an empty array of strings as parameters
//given a chart of values and their respective string expressions, the function loops through the integer array and creates an array of the resulting strings at every index
//values -5,-3,0,1,3,5 have related strings, if the array has a value separate, the string "INVALID" is placed at that index
//function does not return a value, but manipulates an array
void convert(int rating[], string text[], int size)
{
    for(int i=0; i<size; i++)
    {
        if(rating[i]==-5) //-5,0
            text[i]="Terrible";
        else if(rating[i]==-3) //-3,2
            text[i]="Disliked";
        else if(rating[i]==0) //0,5
            text[i]="Not-read";
        else if(rating[i]==1) //1,6
            text[i]="Average";
        else if(rating[i]==3) //3,8
            text[i]="Good";
        else if(rating[i]==5) //5,10
            text[i]="Excellent";

        else
            text[i]="INVALID";
    }
}

//findMedian finds the median of values of an array of floats
//function takes an array of floats and its size as parameters
//the function first makes a copy of the given array so that it does not manipulate the original array
//the copy, newArray, is sorted using a basic bubble sort, which was defined earlier
//if newArray has an odd number of values, it returns the value at the middle of the array
//if newArray is even, it takes the middle two values and returns their average
float findMedian(float array[], int size)
{
    float newArray[size];

    //set newArray equal to array
    for(int i=0; i<size; i++)
    {
        newArray[i]=array[i];
    }

    //sort newArray
    bool sort=false;
    for(int i=0; sort==false; i++)
    {
        sort=true;
        for (i=0; i<size-1; i++)
        {
            if (newArray[i]>newArray[i+1])
            {
                swap(newArray[i], newArray[i+1]);
                sort=false;
            }
        }
    }
    if (size%2 != 0)
    {
        int med = (size/2);
        return newArray[med];
    }
    else if (size%2 == 0)
    {
        int med = (size/2);
        float x;
        x = newArray[med]+newArray[med -1];
        return x/2.0;
    }
}

//function used for test cases, disregard
void printArray(float a[],int size)
{
    for(int i=0; i<size; i++)
        cout<<a[i]<<" ";
}

/*
int main()
{

    //float arr[]={5,8,10,3};
    //string strArr[3];
    //sortArray(arr, 5);
    //cout<<findMedian(arr, 4)<<endl;
    //convert(arr, strArr, 3);
    //cout<<strArr[2];

    //printArray(arr, 5);
}
*/
