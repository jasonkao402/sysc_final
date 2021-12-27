#include <bits/stdc++.h>
#define _ps system("pause")

using namespace std;
double mem[45210];
double img[800];
double c1w[6][30], c1[6][600], p1[6][150], c2w[16][70], c2[16], p2[16][20];
const int tmpos[25] = {0,  1,  2,  3,  4,  28, 29, 30,  31,  32,  56,  57, 58,
                       59, 60, 84, 85, 86, 87, 88, 112, 113, 114, 115, 116};

int main() {
    string t_b, t_c;
    double t_d;
    ifstream win;

    cout << "Loading weights and input data...\n";
    // vvvvv change the path of input file here vvvvv
    win.open("LeNet_All_b.txt");
    for (int i = 0; i < 45210; i++) {
        win >> t_b >> t_c >> t_d;
        mem[i] = t_d;
    }
    // conv 1
    for (int r = 0, i, j; r < 6; r++) {
        for (int i = 0 + r * 26, j = 0; j < 26; i++, j++) {
            c1w[r][j] = mem[i];
        }
    }
    // img
    for (int i = 44426, j = 0; i < 45210; i++, j++) {
        img[j] = mem[i];
    }
    double tmp;
    for (int r = 0, i, j, k; r < 6; r++) {
        for (i = 0; i < 24; i++) {
            for (j = 0; j < 24; j++) {
                // calc
                for (tmp = 0.0, k = 0; k < 25; k++) {
                    tmp += c1w[r][k] * img[i * 28 + j + tmpos[k]];
                }
                // printf("%4.1lf ", tmp+c1w[r][25]);
            }
            // printf("\n");
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
