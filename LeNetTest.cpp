#include<bits/stdc++.h>
#define _ps system("pause")

using namespace std;
double mem[45210];
double img[800];
double c1w[6][30], c1[6][600], p1[6][150], c2w[16][160], c2[16][70], p2[16][20];
const int offset_1[25] = {
  0,   1,   2,   3,   4,
 28,  29,  30,  31,  32,
 56,  57,  58,  59,  60,
 84,  85,  86,  87,  88,
112, 113, 114, 115, 116
}, offset_2[25] = {
 0,  1,  2,  3,  4,
12, 13, 14, 15, 16,
24, 25, 26, 27, 28,
36, 37, 38, 39, 40,
48, 49, 50, 51, 52
};

const int sixto16[16][6] = {
{1, 1, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0},
{0, 0, 1, 1, 1, 0}, {0, 0, 0, 1, 1, 1},
{1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 1},

{1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 0},
{0, 0, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 1},
{1, 1, 0, 0, 1, 1}, {1, 1, 1, 0, 0, 1},

{1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 1, 1},
{1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1},
};

inline double maxpooling1(int r, int p){
	return max(max(c1[r][p], c1[r][p+1]), max(c1[r][p+24], c1[r][p+25]));
}
inline double maxpooling2(int r, int p){
	return max(max(c2[r][p], c2[r][p+1]), max(c2[r][p+8], c2[r][p+9]));
}

int main() {
	string t_b, t_c;
	double t_d;
	ifstream win;
	_ps;
	cout << "Loading weights and input data...\n";
	// vvvvv change the path of input file here vvvvv
	win.open( "LeNet_All_b.txt" );
	for ( int i = 0 ; i < 45210 ; i++ ) {
		win >> t_b >> t_c >> t_d;
		mem[i] = t_d;
	}
	//conv 1 weight
	for(int r = 0, i, j; r<6; r++)
	{
		for (i = 0+r*26, j = 0 ; j < 26 ; i++, j++ )
		{
			c1w[r][j] = mem[i];
		}
	}
	//conv 2 weight
	for(int r = 0, i, j; r<16; r++)
	{
		for (i = 156+r*151, j = 0 ; j < 151 ; i++, j++ )
		{
			c2w[r][j] = mem[i];
		}
	}
	//img
	for ( int i = 44426, j = 0 ; i < 45210 ; i++, j++ )
	{
		img[j] = mem[i];
	}
	//conv 1 calc
	double tmp;
	for(int r = 0, i, j, k; r<6; r++)
	{
		for(i = 0; i<24; i++)
		{
			for(j = 0; j<24; j++)
			{
				//calc
				for(tmp = 0.0, k = 0; k<25; k++)
				{
					tmp += c1w[r][k] * img[i*28 + j + offset_1[k]];
				}
				c1[r][i*24 + j] = max(0.0, tmp + c1w[r][25]);
				//printf("%4.1lf ", tmp+c1w[r][25]);
			}
			//printf("\n");
		}
	}
	//maxpooling 1 calc
	for(int r = 0, i, j, k; r<6; r++)
	{
		for(i = 0; i<12; i++)
		{
			for(j = 0; j<12; j++)
			{
				p1[r][i*12 + j] = maxpooling1(r, i*48 + j*2);
			}
		}
	}
	//conv 2 calc
	for(int r, s = 0, i, j, k; s<16; s++)
	{
		for(i = 0; i<8; i++)
		{
			for(j = 0; j<8; j++)
			{
				//calc
				for(tmp = 0.0, r = 0; r<6; r++)
				{
					for(k = 0; k<25; k++)
					{
						tmp += sixto16[s][r] * c2w[r][r*25 + k] * p1[r][i*12 + j + offset_2[k]];
					}
				}
				c2[s][i*8 + j] = max(0.0, tmp+c2w[r][150]);
				//printf("%4.1lf ", c2[s][i*8+j]);
			}
			//printf("\n");
		}
		//printf("\n");
	}
	for(int r = 0, i, j, k; r<16; r++)
	{
		for(i = 0; i<4; i++)
		{
			for(j = 0; j<4; j++)
			{
				p2[r][i*4 + j] = maxpooling2(r, i*16 + j*2);
				printf("%4.1lf ", p2[r][i*4 + j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	win.close();
	cout << "done!\n";
    return 0;
}

