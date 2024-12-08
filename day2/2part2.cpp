#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool checkList(const vector<int>& list, int index){
        int t = 1;
        int c;
        vector<int> levels = list;
        levels.erase(levels.begin()+index);

        for(int i = 0; i<levels.size()-1; i++)
        {
            if(i == 0)
            {
                c = (levels[i] - levels[i+1] > 0);
            }
            if (abs(levels[i]-levels[i+1]) > 3 || (levels[i] - levels[i+1] > 0)!=c || (levels[i]-levels[i+1])==0)
            {
                return false;
            }
        }
        return true;
}

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
        for(int i = 0; i<levels.size(); i++)
        {
            if(checkList(levels, i))
            {
                r+=1;
                break;
            }
        }
    }


    cout << r << endl;
}