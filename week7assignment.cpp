#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

//declare constants for the number of rows and number of columns
const int numrows = 10;
const int numcol = 5;
const int numcolbig = 6;

//declare structure
struct bowling
{
    string bowlerName;
    int bowlerScores[numcol];
    int bowlerAverage;
};


//function to read and store data into array of structures
void GetBowlingData(string txtfile, struct bowling arrbowling[])
{
    //declare and open file
    ifstream inFile;
    inFile.open(txtfile);

    //decalare new array to pool all data initially into
    string totalarray[numrows][numcolbig];
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < numcolbig; c++)
        {
             inFile >> totalarray[r][c];   
        }
    }
    //transfer the first column of data from the data pool array so that it only takes the names
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 1; c++)
        {
            arrbowling[r].bowlerName = totalarray[r][c];   
        }
    }
    //transfer the everything except the first column of data (only the scores)
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 1; c < numcolbig; c++)
        {
            arrbowling[r].bowlerScores[c-1] = stoi(totalarray[r][c]);   
        }
    }
}

//function to calculate the average for each player
void GetAverageScore(struct bowling arrbowling[])
{
    //double loop to parse and add scores for each row (player) together
    for (int r = 0; r < numrows; r++)
    {
        int total = 0;
        for (int c = 0; c < numcol; c++)
        {
            total = total + arrbowling[r].bowlerScores[c];  
        }
        //divide each row total by the number of scores and insert into array of structures
        arrbowling[r].bowlerAverage = total / numcol;
    }
}

//function to print array of structures to screen
void PrettyPrintResults(struct bowling arrbowling[])
{
    //loop to print each players data in mini segments together
    for (int r = 0; r < numrows; r++)
    {
        cout << "Player name: " << arrbowling[r].bowlerName << endl;
        cout << "Scores: ";
        for (int c = 0; c < numcol; c++)
        {
            cout << arrbowling[r].bowlerScores[c] << " ";
        }
        cout << endl;
        cout << "Average score: " << arrbowling[r].bowlerAverage << endl;
        cout << " " << endl;
    }
}


int main()
{
    //declare struct array
    bowling arrbowling[numrows];

    //call functions
    GetBowlingData("BowlingScores.txt", arrbowling);
    GetAverageScore(arrbowling);
    PrettyPrintResults(arrbowling);
    return 0;
}