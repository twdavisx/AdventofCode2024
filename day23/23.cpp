#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


int search(const map<string, vector<string> > & m,map<string, vector<string> >::iterator it)
{
    int r = 0;
    for(string s : it->second)
    {
        for(string s1 : m.at(s))
        {
            vector<string> q = m.at(s1);
            if(find(q.begin(), q.end(), it->first)!=q.end())
            {
                int t = (it->first[0]=='t' || s[0]=='t' || s1[0] == 't');
                r+=t;
            }
        }
    }
    return r;
}

int main()
{
    int r = 0;
    string ll;
    ifstream inputFile("23.txt");
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

    map<string, vector<string> > connections;
    for(vector<char> i : matrix)
    {
        string c1 = "";
        c1+=i[0];
        c1+=i[1];
        string c2 = "";
        c2=i[3];
        c2+=i[4];

        connections[c1].push_back(c2);
        connections[c2].push_back(c1);
    }

    map<string, vector<string> >::iterator it = connections.begin();
    while(it!=connections.end())
    {
        r+=search(connections,it);
        it++;
    }

    cout << r/6 << endl;

}