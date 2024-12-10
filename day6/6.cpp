#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

pair<int, int> locate(const vector<vector<char>> &vec)
{
    for (int x = 0; x < vec[0].size(); x++)
    {
        for (int y = 0; y < vec.size(); y++)
        {
            if (vec[y][x] == '^')
            {
                pair<int, int> c = {x, y};
                return c;
            }
        }
    }
    pair<int, int> c = {0, 0};
    return c;
}

int main()
{
    string ll;
    ifstream inputFile("test.txt");

    vector<vector<char>> matrix;

    while (getline(inputFile, ll))
    {
        vector<char> line;
        for (char c : ll)
        {
            if (!isspace(c))
            {
                line.push_back(c);
            }
        }
        matrix.push_back(line);
    }

    reverse(matrix.begin(), matrix.end());

    pair<int, int> cords = locate(matrix);
    cout << cords.first << " " << cords.second << endl;
}