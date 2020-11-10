#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "Strathmore", "World", "from", "Ian Odundo", "at", "100446"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}