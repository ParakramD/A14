#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_NAMESIZE = 24;

struct Highscore
{
    char name[MAX_NAMESIZE];
    int scores;
};

int getArraySize(vector<int>::size_type currentSize);
void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
void displayData(const vector<Highscore>& scores);
int indexOfLargest(const vector<Highscore>& scores, int startingIndex);

int main()
{
    int size;

    getArraySize(size);

    vector<Highscore>highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);

    delete[] highScores;
}





int getArraySize(vector<int>::size_type currentSize) 
{
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}





void readData(vector<Highscore>& scores)
{
    for (vector<int>::iterator i = scores.begin(); i != scores.end(); i++)
    {
        cout << "Enter the name for score #" << (i + 1) << ": ";
        cin >> i->name;
        cin.ignore;

        cout << "Enter the score" << (i + 1) << ": ";
        cin >> i->scores;
        cin.ignore();
    }
    cout << endl;
}
void sortData(vector<Highscore>& scores)
{
    int largestIndex;
    Highscore tempRecord;

    for (vector<int>::iterator count = scores.begin(); count != scores.end(); count++)
    {
        largestIndex = indexOfLargest(highScores, count);
        tempRecord = highScores->largestIndex;
        highScores->largestIndex = highScores->count;
        highScores->count = tempRecord;
    }
}
void displayData(const vector<Highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (vector<int>::iterator index = scores.begin(); index != scores.end(); index++)
    {
        cout << *i->name << ": " << *i->score << endl;
    }
}




int indexOfLargest(const Highscore highScores[], int startingIndex)
{
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < size; count++) {
        if (highScores->count.score > highScores->targetIndex.score) {
            targetIndex = count;
        }
    }
    return targetIndex;
}
