#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{


    int r = 0;

    string ll;
    ifstream inputFile("2.txt");
    while (getline(inputFile, ll)) {
        stringstream ss;
        ss << ll;
        vector<int> levels;
        while (!ss.eof())
        {
            int temp;
            ss >> temp;
            levels.push_back(temp);
        }
        int t = 1;
        int c;
        for(int i = 0; i<levels.size()-1; i++)
        {
            if(i == 0)
            {
                c = (levels[i] - levels[i+1] > 0);
            }
            if (abs(levels[i]-levels[i+1]) > 3 || (levels[i] - levels[i+1] > 0)!=c || (levels[i]-levels[i+1])==0)
            {
                t = 0;
                break;
            }
        }
        r+=t;
    }
    cout << r << endl;
}