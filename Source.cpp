#include <iostream>
#include <vector>

using namespace std;
const vector<int>::size_type MAX_NAMESIZE = 24;

struct Highscore
{
    char name[MAX_NAMESIZE];
    vector<int>::size_type score;
};

void getArraySize(vector<int>::size_type& size);
void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
void displayData(const vector<Highscore>& scores);
vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& scores, vector<Highscore>::iterator startingIndex);

int main()
{
    vector<int>::size_type size;

    getArraySize(size);

    vector<Highscore>highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);
}





void getArraySize(vector<int>::size_type& size)
{
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}





void readData(vector<Highscore>& scores)
{
    vector<int>::size_type index = 0;

    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++)
    {
        cout << "\nEnter the name for score #" << index + 1 << ": ";
        cin.getline((*i).name, MAX_NAMESIZE, '\n');

        cout << "Enter the score " << index + 1 << ": ";
        cin >> (*i).score;
        cin.ignore();
        index++;
    }
    cout << endl;
}
void sortData(vector<Highscore>& scores)
{
    for (vector<Highscore>::iterator count = scores.begin(); count != scores.end(); count++)
    {
        vector <Highscore>::iterator largestIndex = indexOfLargest(scores, count);
        if (largestIndex != count)
        {
            swap((*count).name, (*largestIndex).name);
            swap((*count).score, (*largestIndex).score);
        }
    }
}
void displayData(const vector<Highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator index = scores.begin(); index != scores.end(); index++)
    {
        cout << (*index).name << ": " << (*index).score << endl;
    }
}




vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& scores, vector<Highscore>::iterator startingIndex)
{
    vector<Highscore>::iterator targetIndex = startingIndex;

    for (vector<Highscore>::const_iterator count = startingIndex++; count != scores.end(); count++)
    {
        if ((*count).score > (*targetIndex).score)
        {
            targetIndex = startingIndex;
        }
    }
    return targetIndex;
}
