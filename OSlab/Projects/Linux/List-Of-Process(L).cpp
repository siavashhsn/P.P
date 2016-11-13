#include <iostream>
#include <dirent.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <string>
#include <sys/prctl.h>
#include <fstream>

using namespace std;

void get_files()
{
    DIR *dir;
    string pname;
    struct dirent *ent;
    if ((dir = opendir ("/proc")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {

            cout << ent->d_name << endl;
            DIR *dir2;
            string p ="";
            struct dirent *ent2;


            const char * nn = ent->d_name;
            char ss[256] = {};
            //char sss[256] = {};
            // ss[0]='/';ss[1]='p';ss[2]='r';ss[3]='o';ss[4]='c';ss[5]='/';
            // sss[0]='/';sss[1]='p';sss[2]='r';sss[3]='o';sss[4]='c';sss[5]='/';


            strcpy(ss,"/proc/");
            strcat(ss,ent->d_name);
            // strcpy(sss,ss);

            int i = 6;
            int j;
            if((nn[0]>='0' && nn[0]<='9')){
  
                const char * s = ss;
                cout << s << endl;


                if ((dir2 = opendir (s)) != NULL) {
                    // ss[i]='/';ss[i+1]='s';ss[i+2]='t';ss[i+3]='a';ss[i+4]='t';ss[i+5]='u';ss[i+6]='s';
                    strcat(ss,"/status");

                    string line;
                    ifstream myfile (ss);

                    if (myfile.is_open())
                    {
                        while ( getline (myfile,line) )
                        {
                          cout << line << '\n';
                        }
                        myfile.close();
                    }
                    cout << endl <<"****************************************************************"<<endl;
                    closedir (dir2);
                }
                else
                    cout << "there is no directory" << endl;
            }
        }
        closedir (dir);
    }
    else
        cout << "there is no directory"<<endl;
}


int main()
{
    get_files();
    return 0;
}
