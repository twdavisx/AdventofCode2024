#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>

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

    for(int i : l)
    {
        res+=(i*count(r.begin(), r.end(), i));
    }
    
    cout << res << endl;

    return 0;
}