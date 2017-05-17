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
	//open the directory
    DIR *dir;
    string pname;
    struct dirent *ent;
	//open the /proc directory
    if ((dir = opendir ("/proc")) != NULL) { // posheye /proc ro baz mikonim 
		//read all files in /proc directory
        while ((ent = readdir (dir)) != NULL) {
            cout << ent->d_name << endl;
            DIR *dir2;
            string p ="";
            struct dirent *ent2;
            const char * nn = ent->d_name;
            char ss[256] = {};
            strcpy(ss,"/proc/");
            strcat(ss,ent->d_name);
           
            int i = 6;
            int j;
            if((nn[0]>='0' && nn[0]<='9')){

                const char * s = ss;
                cout << s << endl;

				//open each directory in /proc directory
                if ((dir2 = opendir (s)) != NULL) {
                    // ss[i]='/';ss[i+1]='s';ss[i+2]='t';ss[i+3]='a';ss[i+4]='t';ss[i+5]='u';ss[i+6]='s';
                    strcat(ss,"/status");

                    string line;
                    ifstream myfile (ss);
					
					//read each file in dir2/... and print information inside them
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
