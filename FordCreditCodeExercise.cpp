//Ford Credit Code exercise 1 - Trang Leminh 
//FordCreditCodeExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

#include <string>

using namespace std;

//This function serves to parse the strings into vectors & verifies if the coordinates are valid
vector<string> parseStrings(string line1)
{
    vector<string> vec;

    for (int i = 0; i < line1.length(); i++)
    {
        if ((isalpha(line1[i]) && line1[i] != ',') || line1.length() < 5)       //here we are checking to see if there exists letters or empty coordinates
        {
            return vec;                                                         //if contains any invalid characters, the empty vector is returned
        }
    }

    for (int j = 0; j < line1.length(); j++)
    {

        if (line1[j] == ',')
        {
            vec.push_back(line1.substr(1, j));                                  //the contents before and after the comma are recorded and appended into the vector
            vec.push_back(line1.substr(j + 1, line1.length() - 2));
        }
    }

    return vec;
}

//This function does all of the function calling necessary to parse strings and also calculate the distance between valid coordinates
void calcDist(string line1,string line2)
{
    vector<string> vec1 = parseStrings(line1);
    vector<string> vec2 = parseStrings(line2);
    if (vec1.size() > 0 && vec2.size() > 0)             //here we are checking for empty vectors or invalid vectors
    {
        //converting string values to int values to calculate
        cout << "The distance between the two coordinates is: " << (abs(std::stoi(vec1[0]) - std::stoi(vec2[0])) + abs(std::stoi(vec1[1]) - std::stoi(vec2[1]))) << endl;
    }
    else
    {
        cout << "Invalid parameters\n";
    }
}

//The main function will test five use cases with differing parameters

int main()
{ 
    string lineA = "(-1, 2)";
    string lineB = "(7, -2)";
    cout << "********************Test1: Testing single digit coordinates with spaces*****************************\n"
        << "First coordinate is: " << lineA << " second coordinate is: " << lineB <<endl;
    cout << "The calculated distance should be: 12\n";
    calcDist(lineA, lineB);
    cout << "*************************************End of Test1****************************************\n\n\n";


    lineA = "(-10,90)";
    lineB = "(80, -40)";
    cout << "********************Test2: Testing double digit coordinates with no spaces AND spaces*****************************\n"
        << "First coordinate is: " << lineA << " second coordinate is: " << lineB << endl;
    cout << "The calculated distance should be: 220\n";
    calcDist(lineA, lineB);
    cout << "*************************************End of Test2****************************************\n\n\n";


    lineA = "(,)";
    lineB = "(,)";
    cout << "********************Test3: Testing empty coordinates*****************************\n"
        << "First coordinate is: " << lineA << " second coordinate is: " << lineB << endl;
    cout << "There should be an invalid errror output\n";
    calcDist(lineA, lineB);
    cout<< "*************************************End of Test3****************************************\n\n\n";

    lineA = "(a,b)";
    lineB = "(c,d)";
    cout << "********************Test4: Testing non-digit coordinates*****************************\n"
        << "First coordinate is: " << lineA << " second coordinate is: " << lineB << endl;
    cout << "There should be an invalid errror output\n";
    calcDist(lineA, lineB);
    cout << "*************************************End of Test4****************************************\n\n\n";


    lineA = "(10,b)";
    lineB = "(c,5)";
    cout << "********************Test5: Testing non-digit and numbers coordinates*****************************\n"
        << "First coordinate is: " << lineA << " second coordinate is: " << lineB << endl;
    cout << "There should be an invalid errror output\n";
    calcDist(lineA, lineB);
    cout << "*************************************End of Test5****************************************\n\n\n";


    return 0;
}
