#include <iostream>
#include <string>
using namespace std;

struct Koordinat {
	int X;
	int Y;
};

void Tampil_Posisi(Koordinat Posisi);

int main() {
	Koordinat Posisi;
	Posisi.X = 56;
	Posisi.Y = 53;
	cout<<endl;
	Tampil_Posisi(Posisi);
	cin.get();
}

void Tampil_Posisi(Koordinat Posisi) {
	cout<<"Posisi Ordinat X adalah "<<Posisi.X<<endl;
	cout<<"Posisi Ordinat Y adalah "<<Posisi.Y<<endl;
}