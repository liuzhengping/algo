#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <conio.h>
#include <iostream.h>
using namespace std;
void permute( string prefix, string s )
{
    if ( s.size() <= 1  )
        cout << prefix << s << "\n";
    else
        for ( char p = s[0]; p < s[s.size()-1]; p++ )
        {
            char c = p;
            s.erase( p );
            permute( prefix + c, s );
            s.insert(s.end(), c);
        }
}
int main() {
    //int a[4] = {1, 2, 3, 4};
    permute("", "1234");
    printf("\nGotovo!");
    getch();
    return 0;
}    
    
