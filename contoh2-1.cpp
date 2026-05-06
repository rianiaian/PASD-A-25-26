#include <iostream>
#include <string>
using namespace std;

typedef int angka;
typedef float pecahan;
typedef char huruf;
int main(){
	angka umur;
	pecahan pecah;
	huruf nama[5];
	huruf karakter;
	cout <<"masukan umur			: ";cin>>umur;
	cout<<"Umur anda = "<<umur<<endl;
	cout<<endl;
	cout<<"masukan bilangan pecah	: ";cin>>pecah;
	cout<<"bilangan pecha = "<<pecah<<endl;
	cout<<endl;
	cout<<"masukan nama				: ";cin>>nama;
	cout<<"nama anda = "<<nama<<endl;
	cout<<endl;
	cout<<"masukan satu huruf		: ";cin>>karakter;
	cout<<"huruf = "<<karakter<<endl;
	cin.get();
}