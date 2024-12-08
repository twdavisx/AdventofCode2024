#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    unsigned int res = 0;
    vector<int> l;
    vector<int> r;
    
    string ll;
    ifstream inputFile("1.txt");


    while (getline(inputFile, ll)) {
        stringstream line;
        line << ll;
        int temp;
        line >> temp;
        l.push_back(temp);
        line >> temp;
        r.push_back(temp);
    }

    sort(l.begin(),l.end());
    sort(r.begin(),r.end());

    for(int i = 0; i<l.size(); i++)
    {
        res+=abs(l[i]-r[i]);
    }

    cout << res << endl;
    
    return 0;
}