//Justin Hayward: CS 1300 Fall 2017
//Recitation: 106, Tom
//
//Assignment 2

#include <iostream>
using namespace std;

/*howMany
 *algorithm that will calculate the US population in a year
 *receives an input of initial US population
 *outputs a number that represents population in 1 year
 */
int howMany(int pop0)
{
    /*1 birth every 8 seconds
    *1 death every 12 seconds
    *1 immigrant every 33 seconds
    */

    //fist find seconds in one year
    float sec;
    sec = 60*60*24*365; //seconds*minutes*hours*days

    //set variables for births, deaths, immigrants
    float B;
    float D;
    float I;

    //(people/sec)*seconds
    B=(1.0/8.0)*sec;
    D=(1.0/12.0)*sec;
    I=(1.0/33.0)*sec;

    int pop1; //pop1 is population in 1 year

    pop1=pop0+B-D+I;
    return pop1;
}

/*howLong
 *algorithm that will convert seconds into an understandable time
 *receives an input of seconds
 *uses modulo functions to find remainders after a conversion to use in the next step
 *outputs the time in days, hours, minutes, and seconds
 */
void howLong(int tm)
{
    int dy, hr, mn, sc;

    dy=(tm/86400);

    hr=(tm%86400)/3600;

    mn=(tm%3600)/60;

    sc=tm%60;

    cout<<dy<<" days "<<hr<<" hours "<<mn<<" minutes "<<sc<<" seconds"<<endl;
}
/*howHot
 *algorithm that will convert temperature in Celsius to Fahrenheit
 receives an input of temperature in Celsius
 outputs the temperature in Fahrenheit
 */
int howHot(int C)
{
    //F=(9/5)C + 32
    int F=(9*C/5)+32;
    return F;
}

int main()
{
    /*int pop1;
    pop1 = howMany();*/
    int pop0=0;
    cout<<"Given the initial population of "<<pop0;
    cout<< " your estimate finds a population of ";
    cout<<howMany(pop0)<<endl<<endl;

    /*howLong();*/
    int tm=0;
    cout<<"Given the seconds value of "<<tm;
    cout<<" your output is: "<<endl;
    howLong(tm);
    cout<<endl;

    /*int temp;
    temp = howHot();*/
    int temp=0;
    cout<<"Given temperature "<<temp;
    cout<<" degrees Celsius you caluclate ";
    cout<<howHot(temp)<<" degrees Fahrenheit"<<endl;

    return 0;
}
