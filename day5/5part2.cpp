#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


int is_correct(vector< vector <int> > & matrix, vector<int> & numbers)
{
    for(int i = 1; i<numbers.size(); i++)
    {
        for(int k = 0; k<i; k++)
        {
            if(find(matrix[numbers[i]].begin(), matrix[numbers[i]].end(), numbers[k])!=matrix[numbers[i]].end())
            {
                return 0;
            }
        }
    }
    return 1;
}

void reorder(vector< vector <int> > & matrix, vector<int> & numbers)
{
    for(int i = 1; i<numbers.size(); i++)
    {
        for(int k = 0; k<i; k++)
        {
            auto it = find(matrix[numbers[i]].begin(), matrix[numbers[i]].end(), numbers[k]);
            if(it!=matrix[numbers[i]].end())
            {
                swap(numbers[k], numbers[i]);
                if(is_correct(matrix, numbers)==0)
                {
                    reorder(matrix,numbers);
                }
            }
        }
    }
}

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

            works = is_correct(matrix, numbers);

            if(works==0)
            {
                reorder(matrix, numbers);
                r+=(numbers[numbers.size()/2]);
            }
        }

    }
    cout << r << endl;
}