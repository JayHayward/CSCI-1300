//Author:Justin Hayward
//Recitation: 106-Tom
//
//Assignment 3
//Problem 1

#include <iostream>
using namespace std;



/*
 story1 is called from the menu function if the user selects 1 from menu
 the function prompts the user for a plural noun, occupation, animal name, and place
 these inputs are stored as strings to be referenced later in the function
 the function outputs a story using the user's entered information
*/
void story1(void)
{
    //set up the strings
    string noun;
    string occ;
    string ani;
    string pla;

    cout<<"Enter a plural noun:  ";
    cin>>noun;

    cout<<"Enter an occupation:  ";
    cin>>occ;

    cout<<"Enter an animal name:  ";
    cin>>ani;

    cout<<"Enter a place:  ";
    cin>>pla;

    //story output
    cout<<endl<<"In the book War of the "<<noun<<", the main character is an anonymous "<<occ<<" who records the arrival of the "<<ani<<"s in "<<pla<<"."<<endl;

    //main();
}

/*
 story2 is called from the menu function if the user selects 2 from menu
 the function prompts the user for a name and a state or country
 these inputs are stored as strings to be referenced later in the function
 the function outputs a story using the user's entered information
*/
void story2(void)
{
    string nam;
    string pla;

    cout<<"Enter a name:  ";
    cin>>nam;

    cout<<"Enter a state/country: ";
    cin>>pla;

    cout<<endl<<nam<<", I've got a feeling we're not in "<<pla<<" anymore."<<endl;

    //main();
}

/*
 story3 is called from the menu function if the user selects 3 from menu
 the function prompts the user for a first name, relative, and verb
 these inputs are stored as strings to be referenced later in the function
 the function outputs a story using the user's entered information
*/
void story3(void)
{
    string nam;
    string rel;
    string verb;

    cout<<"Enter a first name:  ";
    cin>>nam;

    cout<<"Enter a relative:  ";
    cin>>rel;

    cout<<"Enter a verb:  ";
    cin>>verb;

    cout<<endl<<"Hello. My name is "<<nam<<". You killed my "<<rel<<". Prepare to "<<verb<<"."<<endl;

    //main();
}

/*
 menu is a function that asks the user what story they want to use
 the function uses the string story to prompt input
 the user us asked in input 1, 2, or 3 which will lead them to the corresponding story
 the user may also press q to exit the program
 if the user's input is not 1, 2, 3, or q, the function tells them that answer isn't valid and prompts the question again
*/
void menu(void)
{
    cout<<"Which story would you like to play?"<<endl;
    cout<<"Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;

    string story;
    cin>>story;

    if (story=="q")
    {
        cout<<endl<<"good bye"<<endl;
        return; //q exits the function
    }

    if (story != "1" && story != "2" && story != "3")
    {
        cout<<"Valid choice not selected."<<endl<<endl;
        menu();
    }

    if (story == "1")
    {
        cout<<endl;
        story1();
    }

    if (story == "2")
    {
        cout<<endl;
        story2();
    }

    if (story == "3")
    {
        cout<<endl;
        story3();
    }
}

/*
 the main function calls the menu function, where the program's main purpose is fulfilled
*/
int main(void)
{
    menu();

    /*string story;

    int story_select;
    story_select=menu();

    if (story_select == 1)
        story1();

    if (story_select == 2)
        story2();

    if (story_select == 3)
        story3();

    /*
    string yn;

    cout<<endl<<"Would you like to play again? Y or N  ";
    cin>>yn;

    if (yn == "y")
    {
        menu();
        cout<<endl;
    }

    else
        cout<<"good bye";
    */

    return(0);
    //cout<<"test"<<endl;
}
