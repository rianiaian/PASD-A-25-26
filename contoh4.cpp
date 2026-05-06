#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
	int i;
	char *namaKu, NM[6]= {'A','D','R','I','A','N'};
	cout<<"  Nama Ku  "<<endl;
	cout<<"-----------"<<endl;
	for(i=0;i<6;i++) {
		namaKu = &NM[i];
		cout<<" "<<*namaKu<<endl;
	}
	cin.get();
}