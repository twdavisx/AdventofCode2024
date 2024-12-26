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

int func(vector< vector <char> > & m, pair<int, int> pos, pair<int, int> dir, map<pair <int, int>, vector< pair<int, int> > > & newm)
{
    while(true)
    {
        if(find(newm[dir].begin(), newm[dir].end(), pos)==newm[dir].end())
        {
            m[pos.first][pos.second] = 'X';
            //printM(m);
            newm[dir].push_back(pos);
            while(true){
                if(pos.first+dir.first >= m.size() || pos.second+dir.second >= m[0].size() || pos.first+dir.first < 0 || pos.second+dir.second < 0)
                {
                    return 0;
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
        }
        else
        {
            return 1;
        }
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
                func(matrix,p,d,mp);
                map<pair <int, int>, vector< pair<int, int> > > newm;
                for(int j = 0; j<matrix.size(); j++)
                {
                    for(int q = 0; q<matrix[0].size(); q++)
                    {
                        if(i!=j || k!=q)
                        {
                            pair<int,int> o(j,q);
                            bool run = false;
                            for(auto iter = mp.begin(); iter!=mp.end(); iter++)
                            {
                                if(find(iter->second.begin(), iter->second.end(), o)!=iter->second.end())
                                {
                                    run = true;
                                }
                            }
                            if(run == true)
                            {
                                vector <vector <char > > copy = matrix;
                                copy[j][q] = '#';
                                r+=func(copy,p,d,newm);
                                newm.clear();
                                //cout << r << endl;
                            }
                        }

                    }
                }
            }
        }
    }
    cout << r << endl;

}