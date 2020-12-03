#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

const int MAX_NAMESIZE = 24;

struct Highscore
{
    char name[MAX_NAMESIZE];
    int scores;
};

void getArraySize(vector<int>::size_type currentSize);
void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
void displayData(const vector<Highscore>& scores);
vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& constScores, vector<Highscore>::iterator startingIndex);

int main()
{
    int size;

    getArraySize(size);

    vector<Highscore>highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);
}





void getArraySize(vector<int>::size_type currentSize)
{
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}





void readData(vector<Highscore>& scores)
{
    for (vector<Highscore>::iterator index = scores.begin(); index != scores.end(); index++)
    {
        cout << "Enter the name for score #" << *index + 1 << ": ";
        cin >> index -> name;
        cin.ignore();

        cout << "Enter the score" << *index + 1 << ": ";
        cin >> index -> scores;
        cin.ignore();
    }
    cout << endl;
}
void sortData(vector<Highscore>& scores)
{
    int largestIndex;
    Highscore tempRecord;

    for (vector<Highscore>::iterator count = scores.begin(); count != scores.end(); count++)
    {
        largestIndex = indexOfLargest(highScores, count);
        tempRecord = highScores.largestIndex;
        highScores->largestIndex = highScores.count;
        highScores->count = tempRecord;
    }
}
void displayData(const vector<Highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator index = scores.begin(); index != scores.end(); index++)
    {
        cout << *index->name << ": " << index->scores << endl;
    }
}




vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& scores, vector<Highscore>::iterator startingIndex)
{
    vector<Highscore>::iterator targetIndex = startingIndex;

    for (vector<Highscore>::const_iterator count = scores.begin(); count != scores.end(); count++)
    {
        if (highScores(count.scores) > highScores(targetIndex.scores))
        {
            targetIndex = count;
        }
    }
    return targetIndex;
}
