#include <iostream>
using namespace std;

class mahasiswa {
	public:
    char NPM[9];
    char nama[20];
    float ipk;
};
int main(){
	mahasiswa mhs;
	cout<<"NPM				: "; cin >> mhs.NPM;
	cout<<"Nama Mahasiswa	: "; cin >> mhs.nama;
	cout<<"IPK				: "; cin >> mhs.ipk;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"NPM				= "<<mhs.NPM<<endl;
	cout<<"Nama Mahasiswa	= "<<mhs.nama<<endl;
	cout<<"IPK				= "<<mhs.ipk<<endl;
	cin.get();
}