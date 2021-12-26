#include<bits/stdc++.h>

using namespace std;
double mem[45210];
double img[800];
double c1[6][600], p1[6][150], c2[16][70], p2[16][20];
const int tmp[] = {
 0,  1,  2,  3,  4,
28, 29, 30, 31, 32,
56, 57, 58, 59, 60,
84, 85, 86, 87, 88,
112, 113, 114, 115, 116
};

int main() {
	string t_b, t_c;
	double t_d;
	ifstream win;
	
	cout << "Loading weights and input data...\n";
	// vvvvv change the path of input file here vvvvv
	win.open( "LeNet_All_b.txt" );
	for ( int i = 0 ; i < 45210 ; i++ ) {
		win >> t_b >> t_c >> t_d;
		mem[i] = t_d;
	}
	for ( int i = 44426, j = 0 ; i < 45210 ; i++, j++ )
	{
		img[j] = mem[i];
	}
	for(int r = 0; r<6; r++)
	{
		for(int i = 0, j; i<24; i++)
		{
			for(j = 0; j<24; j++)
				img[i*24+j];
			printf("\n");
		}
	}
//	for(int i = 0, j; i<28; i++)
//	{
//		for(j = 0; j<28; j++)
//			printf("%3.1lf ", img[i*28+j]);
//		printf("\n");
//	}
	win.close();
	cout << "done!\n";
    return 0;
}

