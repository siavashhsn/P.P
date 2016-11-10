#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	cin >> a;
	string s;
	cin >> s;
	vector<int> v;
	for(int i=0; i<a; i++){
		v.push_back(s[i]-48);
	}
	vector<int> vv, vvv,_vv,_vvv;
	for(int i=0; i<v.size(); i++){
		if(v[i]!=0){
			if(v[i]!=7 && v[i]!=8 && v[i]!=9){
				vvv.push_back(v[i]+3);
			}
			else{
				if(v[i]==8)
					vvv.push_back(0);
				else
					vvv.push_back(-1);
			}
			if(v[i]!=3){
				vv.push_back(v[i]-3);
			}
			else{
				vv.push_back(-1);
			}

			if(v[i]==3 || v[i]==6 || v[i]==9)
				_vv.push_back(-1);
			else
				_vv.push_back(v[i]+1);

			if(v[i]==1 || v[i]==4 || v[i]==7){
				_vvv.push_back(-1);
			}
			else
				_vvv.push_back(v[i]-1);
		}
		else{
			vv.push_back(8);
			vvv.push_back(-1);
			_vv.push_back(-1);
			_vvv.push_back(-1);
		}

	}


	bool f1=false, f2=false;
	bool f3=false, f4=false;
	for(int i=0; i<v.size(); i++){

		if(vv[i]<0)
			f1=true;
		if(vvv[i]<0)
			f2=true;
		if(_vv[i]<0)
			f3=true;
		if(_vvv[i]<0)
			f4=true;
	}
	if(f1 == true && f2==true && f3==true && f4==true)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}



// for(int i=0; i<v.size(); i++){
	// 	cout << vv[i];
	// }
	// cout << endl;
	// for(int i=0; i<v.size(); i++){
	// 	cout << vvv[i];
	// }
	// cout << endl;
	// for(int i=0; i<v.size(); i++){
	// 	cout << _vv[i];
	// }
	// cout << endl;
	// for(int i=0; i<v.size(); i++){
	// 	cout << _vvv[i];
	// }
	// cout << endl;
