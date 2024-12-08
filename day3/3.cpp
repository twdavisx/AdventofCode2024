#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    ifstream inputFile("3.txt");
    string mul = "aaaa";
    string output = "";
    bool stage1 = true;
    string i1 = "";
    string i2 = "";
    int r = 0;

    char c;
    while( inputFile.get(c))
    {
        if(mul!="mul(" || !isdigit(c))
        {
            mul+=c;
            mul.erase(mul.begin());
            i1 = "";
            i2 = "";
            stage1 = true;
        }
        else
        {
            if(stage1)
            {
            i1+=c;
            if(inputFile.peek()==',')
            {
                inputFile.get(c);
                stage1=false;
            }
            } else
            {
                i2+=c;
                if(inputFile.peek()==')')
                {
                    r+=(stoi(i1)*stoi(i2));
                }
            }
        }

    }
    cout << r << endl;
}