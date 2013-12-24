/*	NIM : 10111143
 *	Nama : Mohammad Abdul Iman Syah
 *	Kelas : IF-8
 */

#include <cstdlib>
#include <iostream>
#define max 100
#define honor 1000000

using namespace std;

float pJabatan(int g);
float pPendidikan(int p);
float Lembur(int j);
float Pajak(float tJ, float tP, float l);
float Pendapatan(float tJ, float tP, float l, float k);
void Info();
void Banyak(int *jumlah);
void Input(int b, char n[][14], int g[], int p[], int j[]);
void Proses(int b, int g[], int p[], int j[], float tJ[], float tP[], float l[], float k[], float d[], float *t);
void Field();
void Output(int b, char n[][14], float tJ[], float tP[], float l[], float k[], float d[], float t);

int main(int argc, char** argv) 
{	
	char nama[max][14];	
	int jabatan[max];
	int pendidikan[max];
	int jam[max];
	float tJabatan[max];
	float tPendidikan[max];
	float lembur[max];
	float pajak[max];
	float pendapatan[max];	
	float gaji;
	int jumlah;	
		 	
	Banyak(&jumlah);
	Input(jumlah,nama,jabatan,pendidikan,jam);
	Proses(jumlah,jabatan,pendidikan,jam,tJabatan,tPendidikan,lembur,pajak,pendapatan,&gaji);	
	Output(jumlah,nama,tJabatan,tPendidikan,lembur,pajak,pendapatan,gaji);	
	printf("\n\n");
	system("pause");
	return 0;
}

float pJabatan(int g){	
	switch(g){
		case 1 	: return 0.05 * honor;
				  break;
		case 2 	: return 0.10 * honor;
				  break;
		case 3 	: return 0.15 * honor; 
				  break;
		default : return 0.00;
	}
}

float pPendidikan(int p){
	switch(p){
		case 1 	: return 0.025 * honor;
				  break;
		case 2 	: return 0.05 * honor;
				  break;
		case 3 	: return 0.075 * honor; 
				  break;
		default : return 0.00;
	}
}

float Lembur(int j){
	if(j < 240){
		return 0.0;
	} else {
		j -= 240;
		return j * 2500;
	}
}

float Pajak(float tJ, float tP, float l){
	return (honor + tJ + tP + l) * 0.1;
}

float Pendapatan(float tJ, float tP, float l, float k){
	return honor + tJ + tP + l - k;
}

void Info(){
	cout << "\n\t  Tunjangan Jabatan \t\t      Tunjangan Pendidikan\n"
		 << "\t--------------------- \t\t ------------------------------\n"
		 << "\tGolongan   Persentase \t\t Kode   Pendidikan   Persentase\n"
		 << "\t--------------------- \t\t ------------------------------\n"
		 << "\t    1          5% \t\t   1       SMU          2,5%\n"
		 << "\t    2         10% \t\t   2        D3            5%\n"
		 << "\t    3         15% \t\t   3        S1          7,5%\n"
		 << "\t--------------------- \t\t ------------------------------\n\n\n";
}

void Banyak(int *n){
	Info();
	cout << "\tMasukkan Jumlah Karyawan : "; cin >> *n;
	printf("\n\n");
}

void Input(int b, char n[][14], int g[], int p[], int j[]){
	for(int i=0; i<b; i++){
		printf("\tKaryawan Ke - %i\n",i+1);
		printf("\t---------------------------------------\n");
		cout << "\tNama Karyawan      : "; fflush(stdin); gets(n[i]); 
		do{		
			cout << "\tGolongan (1/2/3)   : "; cin >> g[i];
		}while(g[i] > 3);
		do{
			cout << "\tPendidikan (1/2/3) : "; cin >> p[i];
		}while(p[i] > 3);			
		cout << "\tJumlah Jam Kerja   : "; cin >> j[i];
		printf("\t---------------------------------------\n");
		printf("\n");
	}
}

void Proses(int b, int g[], int p[], int j[], float tJ[], float tP[], float l[], float k[], float d[], float *t){
	float z;
	for(int i=0; i<b; i++){
		tJ[i] = pJabatan(g[i]);
		tP[i] = pPendidikan(p[i]);
		l[i] = Lembur(j[i]);
		k[i] = Pajak(tJ[i],tP[i],l[i]);
		d[i] = Pendapatan(tJ[i],tP[i],l[i],k[i]);
		z += d[i];
	}
	*t = z;
}

void Field(){
	system("cls");
	cout << " \n ------------------------------------------------------------------------------\n"
		 << "                            Tunjangan\n"
		 << "           Nama      ----------------------  Honor                  Pendapatan\n"
		 << "  No     Karyawan     Jabatan   Pendidikan      Lembur    Pajak       Bersih\n"
		 << " ---- -------------- --------- ------------ ----------- ---------- ------------\n";		 	
}

void Output(int b, char n[][14], float tJ[], float tP[], float l[], float k[], float d[], float t){
	Field();
	for(int i=0; i<b; i++){
		printf(" %3i  %-14s %9.2f  %10.2f  %11.2f %10.2f %11.2f\n",i+1,n[i],tJ[i],tP[i],l[i],k[i],d[i]);
	}
	cout << " ------------------------------------------------------------------------------\n";		 	
	printf( "                                Total Gaji yang dikeluarkan  Rp. %13.2f",t);
}
