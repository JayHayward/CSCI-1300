//Author: Justin Hayward
//Recitation: 106-Tom
//
//Assignment 2
//Problem 2

#include <iostream>
#include <cmath>
using namespace std;

/*
 windChillCalculator is a function the uses our windchill function to calculate windchill from input values.
 windchill(F)=35.74+0.6215T-35.75(V^0.16)+0.4275T(V^0.16)
 the function uses parameters T and V as air temperature and wind velocity respectively
 the function returns wind_chill to be used in the main function.
*/
float windChillCalculator(float T, float V)
{
    float wind_chill;

    wind_chill = 35.74 + (0.6215*T) - 35.75*(pow(V, 0.16)) + 0.4275*T*(pow(V, 0.16));
    return (wind_chill);
}

/*
 printWindChill is a function that prints different wind chills derived from different wind speeds.
 To start the function sets V(wind velocity) as a lower parameter so that new iterations can be greater than it.
 The while loop assures that the primary purpose of the function can only be called if V is within the bounds of the low and high speeds
 Within the while loop, the function calls on data from our windChillCalculator function.
 While in the loop, the function fulfills its print purpose.
 The end of the loop defines a new iteration from the speed step
*/
void printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{
    float V=low_wind_speed;

    while ((V >= low_wind_speed)&&(V <= high_wind_speed))
    {
        float wind_chill=windChillCalculator(T, V);

        cout<<"The wind chill is "<<wind_chill<<" degrees F ";
        cout<<"for an air temperature of "<<T<<" degrees F ";
        cout<<"and a wind speed of "<<V<<" mph."<<endl;
        //Divided the cout into 3 parts to organize the outputs as well as make it easier to read.

        V=V+wind_speed_step;
    }
}

/*
 The main function simply calls the functions we defined earlier.
 It floats T and V as air temperature ans wind velocity to use as parameters in windChillCalculator
 It floats low_wind_speed, high_wind_speed, and wind_speed_step to use as parameters in printWindChill
 It floats the value wind_chill to simplify the value we are calling in the cout.
*/
int main()
{
    float T;
    float V;

    float wind_chill;
    wind_chill=windChillCalculator(T, V);

    cout<<"The wind chill is "<<wind_chill<<" degrees F."<<endl;

    float low_wind_speed;
    float high_wind_speed;
    float wind_speed_step;

    printWindChill(T, low_wind_speed, high_wind_speed, wind_speed_step);
}
