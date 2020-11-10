#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i = 0;
    vector<string> msg{"Hello", "Strathmore", "World", "from", "Ian", "Odundo", "at", "100446"};

    for (const string &word : msg)
    {
        i++;
        cout << word << " ";
    }

    cout << "\n"
         << i << " Words Displayed";

    cout << endl;
}