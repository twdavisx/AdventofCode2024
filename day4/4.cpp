#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int search(const vector<vector<char>> &matrix, int i, int k)
{
    int l = matrix.size();
    int w = matrix[0].size();
    int r = 0;

    vector<pair<int, int>> directions = {{1, 1}, {-1, -1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}};

    for (pair<int, int> dir : directions)
    {
        string xmas;

        for (int iter = 0; iter < 4; iter++)
        {
            int checkL = i + iter * dir.first;
            int checkW = k + iter * dir.second;

            if (checkL < 0 || checkL >= l || checkW < 0 || checkW >= w)
            {
                break;
            }

            xmas += matrix[checkL][checkW];
        }

        if (xmas == "XMAS")
        {
            r++;
        }
    }

    return r;
}

int main()
{
    int r = 0;
    string ll;
    ifstream inputFile("4.txt");
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

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int k = 0; k < matrix[i].size(); k++)
        {
            if (matrix[i][k] == 'X')
            {
                r += search(matrix, i, k);
            }
        }
    }
    cout << r << endl;
}