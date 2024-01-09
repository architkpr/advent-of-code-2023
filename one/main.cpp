#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;

void getPuzzleInput(vector<string>& fileLines) {

    string fileLine;
    const char filename[] = "input.txt";
    ifstream fileContents( filename );
    
    while( getline( fileContents, fileLine, '\n' ) ) {
        fileLines.push_back( fileLine );
    }

    fileContents.close();
}

void one(vector<string> fileLines) {

    vector<int> values;
    for ( int idx = 0; idx < fileLines.size(); idx++ )
    {
        int first = -1;
        int last = -1;
        string currentLine = fileLines[ idx ];
        for ( int idx2 = 0; idx2 < currentLine.length(); idx2++ )
        {
            char currentChar = currentLine.at(idx2);
            if ( isdigit(currentChar) )
            {
                first = first < 0? int(currentChar - '0') : first;
                last = last < 0? first : int(currentChar - '0');
            }
        }
        values.push_back( (10 * first) + last );
    }

    cout << accumulate(values.begin(), values.end(), 0);
}

void two(vector<string> fileLines) {

    vector<int> values;
    unordered_map<string, int> digitMap;
    digitMap["one"] = 1;
    digitMap["two"] = 2;
    digitMap["three"] = 3;
    digitMap["four"] = 4;
    digitMap["five"] = 5;
    digitMap["six"] = 6;
    digitMap["seven"] = 7;
    digitMap["eight"] = 8;
    digitMap["nine"] = 9;

    for( int idx = 0; idx < fileLines.size(); idx++ )
    {
        int first = -1;
        int last = -1;
        string currentLine = fileLines[idx];

        for( int i = 0; i < currentLine.length(); i++ )
        {
            char currentChar = currentLine.at(i);
            if( isdigit(currentChar) )
            {
                first = first < 0? int(currentChar - '0') : first;
                last = last < 0? first : int(currentChar - '0');
            }
            else
            {   
                string currentDigitWord;
                currentDigitWord += currentChar;
                for( int j = i+1; j < currentLine.length(); j++ )
                {
                    char nextChar = currentLine.at(j);
                    if( isdigit(nextChar) )
                    {
                        break;
                    }
                    else
                    {
                        currentDigitWord += nextChar;
                        if( digitMap.find(currentDigitWord) == digitMap.end() )
                        {
                            continue;
                        }
                        first = first < 0? digitMap[currentDigitWord] : first;
                        last = last < 0? first : digitMap[currentDigitWord];
                    }
                }
            }
            
        }
        values.push_back( (10 * first) + last );
    }
    cout << accumulate(values.begin(), values.end(), 0);
}

int main() {

    vector<string> fileLines;
    getPuzzleInput(fileLines);

    cout << "Puzzle 1" << '\n';
    one(fileLines);
    cout << '\n';

    cout << "Puzzle 2" << '\n';
    two(fileLines);
    cout << '\n';

    return 0;
}