#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

//litte messy since misread the question

std::map<pair <int, int>, vector< pair<int, int> > > mp;

void printM(vector< vector < char > > m)
{
    reverse(m.begin(),m.end());
    for(int i = 0; i<m.size();i++)
    {
        for(int k = 0; k<m[0].size();k++)
        {
            cout << m[i][k];
        }
        cout << endl;
    }
}
void rotate(pair <int, int> & dir)
{
    if(dir.first==1)
    {
        dir.first=0;
        dir.second=1;
    }
    else if (dir.second == 1)
    {
        dir.first=-1;
        dir.second=0;
    }
    else if (dir.first==-1)
    {
        dir.first=0;
        dir.second=-1;
    }
    else
    {
        dir.first = 1;
        dir.second = 0;
    }
}

int func(vector< vector <char> > & m, pair<int, int> & pos, pair<int, int> & dir, int & count)
{
    if(find(mp[dir].begin(), mp[dir].end(), pos)==mp[dir].end())
    {
        count+=1;
        //m[pos.first][pos.second] = 'X';
        //printM(m);
        mp[dir].push_back(pos);
        while(true){
            if(pos.first+dir.first >= m.size() || pos.second+dir.second >= m[0].size() || pos.first+dir.first < 0 || pos.second+dir.second < 0)
            {
                //rotate(dir);
                return count;
            }
            else if (m[pos.first+dir.first][pos.second+dir.second]=='#')
            {
                rotate(dir);
            }
            else
            {
                break;
            }
        }
        pos.first+=dir.first;
        pos.second+=dir.second;
        func(m, pos, dir, count);
    }
    else
    {
        return count;
    }
}

int main()
{
    int r = 0;
    string ll;
    ifstream inputFile("6.txt");

    vector<vector<char> > matrix;

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
    for(int i = 0; i<matrix.size(); i++)
    {
        for(int k = 0; k<matrix[i].size(); k++)
        {
            if(matrix[i][k] == '^')
            {
                pair<int, int> p(i,k);
                pair<int, int> d(1,0);
                func(matrix, p, d, r);
            }
        }
    }
    set<pair <int, int> > a;

    for(auto iter = mp.begin(); iter!=mp.end(); iter++)
    {
        for(auto i : iter->second)
        {
            a.insert(i);
        }
    }
    cout << a.size() << endl;
    
}