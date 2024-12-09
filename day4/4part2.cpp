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

    vector<pair<int, int>> directions = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    if (i + 1 < l && i - 1 >= 0 && k + 1 < w && k - 1 >= 0)
    {
        string xmas = "";
        for (pair<int, int> p : directions)
        {
            xmas += matrix[i + p.first][k + p.second];
        }
        r += (xmas == "MSMS");
        r += (xmas == "SMSM");
        r += (xmas == "SMMS");
        r += (xmas == "MSSM");
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
            if (matrix[i][k] == 'A')
            {
                r += search(matrix, i, k);
            }
        }
    }
    cout << r << endl;
}