#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeTest()
{
    ofstream myfile;
    myfile.open("text.txt");
    myfile<<"This line has 28 characters.\n"<<"This line has 17.";
    myfile.close();
}

void buildFile()
{
    ofstream myfile;
    myfile.open("filename.txt");
    myfile<<"A1, A2, A3, A4, A5\n"<<"90.2, 80, 0, 75.4, 98.2\n";
    myfile<<"94, 93.5, 92, 88, 87.5\n";
    myfile.close();
}

void bustFile()
{
    remove("filename.txt");
}

void buildQ3()
{
    ofstream myfile;
    myfile.open("Q3.txt");
    myfile<<"Value1, Value2, Value3, Value4, Value5\n";
    myfile<<"4, 1, 2, 3, 5\n";
    myfile<<"2, 3, 4, 1, 0\n";
    myfile<<"6, 4, 0, 2, -1\n";
    myfile<<"5, -3, 2, 1, 0\n";
    myfile<<"6, 2, -7, 3, 0";
    myfile.close();
}

int main()
{
    writeTest();

    buildQ3();

    buildFile();

    string line;
    ifstream myfile;
    myfile.open("Q3.txt");

    if (myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile, line);
            cout<<line<<endl;
        }
    }
}
