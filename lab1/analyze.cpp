#include <iostream>
#include <vector>
#include <string>

using namespace std;

//basic code for analysis by lexical analysis
int main()
{
    int i = 0;
    vector<string> msg{"Hello", "World", "from", "Ian", "Odundo", "at", "Strathmore", "-", "100446"};

    for (const string &word : msg)
    {
        i++;
        cout << word << " ";
    }

    cout << "\n"
         << i << " Words Displayed";

    cout << endl;
}