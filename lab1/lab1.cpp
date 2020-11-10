#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int isKeyword(char buffer[])
{
    //This array of keywords was retrieved from https://en.cppreference.com/w/cpp/keyword. Left some less common ones out i.e atomic_commit and focused on the 32 carried over from C.
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int i;
    bool flag = false;

    for (i = 0; i < 32; ++i)
    {
        //check if the char[] in the buffer is a keyword
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

int main()
{
    //defining char for token, buffer for lexemes and array for operators, unsure if << and >>  are operators as used to cout and cin, so I left them out
    char ch, buffer[15], operators[] = "+-*/%=";

    //please set to actual file location. My generated .exe file is outside the lab1 folder, hence my current fstream pointer
    ifstream fin("lab1/analyze.cpp");
    int i, j = 0;

    if (!fin.is_open())
    {
        cout << "Unable to open the file\n";
        exit(0);
    }

    while (!fin.eof())
    {
        //get and hold next token
        ch = fin.get();

        //Using both the longest match rule and rule priority we'll chack for operators first, then if its a number, then for keywords before assigning the lexeme as an identifier
        for (i = 0; i < 6; ++i)
        {
            //check if the token is an operator, loop through all 6 operators
            if (ch == operators[i])
                cout << ch << " is operator\n";
        }

        //check to see if the token is alphanumeric
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        //if the next token is an empty space or a new line we determine it is a lexeme
        else if ((ch == ' ' || ch == '\n' || ch == '{' || ch == '<' || ch == '>') && (j != 0))
        {
            //clear the final token from the buffer
            buffer[j] = '\0';
            j = 0;

            //check if the lexeme is a keyword
            if (isKeyword(buffer))
                cout << buffer << " is keyword\n";
            else
                cout << buffer << " is indentifier\n";
        }
    }

    //close the file
    fin.close();

    return 0;
}
//noted shortcomings include handling operators in string and comments