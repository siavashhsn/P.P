#include <iostream>
#include <string>
using namespace std;

int main()
{
    while(true)
    {
        string a, b;

        cin >> a >> b;

        string br;

        for (int var = b.length()-1; var >= 0 ; --var) {
            br += b[var];
        }

        int counter4 = 0;
        int counter7 = 0;

        if(a == br)
        {
            cout << 1;
        }
        else
        {
            for (unsigned int var = 0; var < a.length(); ++var) {
                if(a[var] == '4' &&  b[var] == 7)
                    counter4++;
                else if(a[var] == '7' &&  b[var] == 4)
                    counter7++;
            }

            int minim;
            if(counter4 != 0 && counter7 != 0)
            {
                if(counter4 > counter7)
                    cout << counter7;
                else
                    cout << counter4;
            }
            else if(counter4 == 0)
                cout << counter7;
            else
                cout << counter4;
        }
    }

    return 0;
}
