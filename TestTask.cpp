#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    
    char* ch = new char[255];
    for (int i = 0; i < 5; i++)
    {
        cin.getline(ch, 255, '\n');
        String str = String(ch);
        str.Sort();
        str.Show();
    }
}
