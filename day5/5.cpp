#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int r = 0;
    string ll;
    ifstream inputFile("5.txt");
    vector<vector<int> > matrix;
    matrix.resize(100);
    bool p1 = true;

    while (getline(inputFile, ll))
    {
        if(ll == "") 
        {
            p1 = false;
            getline(inputFile, ll);
        }
        if(p1 == true)
        {
            vector<char> line;
            for (char c : ll)
            {
                if (!isspace(c))
                {
                    line.push_back(c);
                }
            }
            string index = "";
            index+=line[0];
            index+=line[1];
            string temp = "";
            temp+=line[3];
            temp+=line[4];
            matrix[stoi(index)].push_back(stoi(temp));
        }
        else
        {
            vector<int> numbers;
            stringstream ss1(ll);
            string token;
            int works = 1;

            while (getline(ss1, token, ',')) {
                numbers.push_back(std::stoi(token));
            }
            for(int i = 1; i<numbers.size(); i++)
            {
                for(int k = 0; k<i; k++)
                {
                    if(find(matrix[numbers[i]].begin(), matrix[numbers[i]].end(), numbers[k])!=matrix[numbers[i]].end())
                    {
                        works = 0;
                    }
                }
            }

            r+=(numbers[numbers.size()/2]*works);
        }

    }
    cout << r << endl;
}