#include <bits/stdc++.h>
#define _ps system("pause")

using namespace std;
double mem[45210];
double img[800];
double c1w[6][30], c1[6][600], p1[6][150], c2w[16][160], c2[16][70], p2[16][20];
double d1w[30840], d2w[10164], d3w[850], d1[120], d2[84], d3[10];
const int offset_1[25] = {0,  1,  2,   3,   4,   28,  29, 30, 31,
                          32, 56, 57,  58,  59,  60,  84, 85, 86,
                          87, 88, 112, 113, 114, 115, 116},
          offset_2[25] = {0,  1,  2,  3,  4,  12, 13, 14, 15, 16, 24, 25, 26,
                          27, 28, 36, 37, 38, 39, 40, 48, 49, 50, 51, 52};

const int sixto16[16][6] = {
    {1, 1, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 1},

    {1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1}, {1, 1, 0, 0, 1, 1}, {1, 1, 1, 0, 0, 1},

    {1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1},
};

inline double maxpooling1(int r, int p) {
    return max(max(c1[r][p], c1[r][p + 1]), max(c1[r][p + 24], c1[r][p + 25]));
}
inline double maxpooling2(int r, int p) {
    return max(max(c2[r][p], c2[r][p + 1]), max(c2[r][p + 8], c2[r][p + 9]));
}

int main() {
    string t_b, t_c;
    double t_d;
    ifstream win;
    ofstream wout;
    //_ps;
    cout << "Loading weights and input data...\n";
    // vvvvv change the path of input file here vvvvv
    win.open("LeNet_All_b.txt");
    wout.open("pool2.txt");
    for (int i = 0; i < 45210; i++) {
        win >> t_b >> t_c >> t_d;
        mem[i] = t_d;
    }
    win.close();
    cout << "read done!\n";
    // conv 1 weight
    for (int r = 0, i, j; r < 6; r++) {
        for (i = 0 + r * 26, j = 0; j < 26; i++, j++) {
            c1w[r][j] = mem[i];
        }
    }
    // conv 2 weight
    for (int r = 0, i, j; r < 16; r++) {
        for (i = 156 + r * 151, j = 0; j < 151; i++, j++) {
            c2w[r][j] = mem[i];
        }
    }
    // dense 1 weight
    for (int i = 2572, j = 0; i < 33412; i++, j++) {
        d1w[j] = mem[i];
    }
    // dense 2 weight
    for (int i = 33412, j = 0; i < 43576; i++, j++) {
        d2w[j] = mem[i];
    }
    // dense 3 weight
    for (int i = 43576, j = 0; i < 44426; i++, j++) {
        d3w[j] = mem[i];
    }
    // img
    for (int i = 44426, j = 0; i < 45210; i++, j++) {
        img[j] = mem[i];
    }
	// conv 1 calc
    double tmp;
    for (int r = 0, i, j, k; r < 6; r++) {
        for (i = 0; i < 24; i++) {
            for (j = 0; j < 24; j++) {
                // calc
                for (tmp = c1w[r][25], k = 0; k < 25; k++) {
                    tmp += c1w[r][k] * img[i * 28 + j + offset_1[k]];
                }
                c1[r][i * 24 + j] = max(0.0, tmp);
                // printf("%4.1lf ", tmp+c1w[r][25]);
            }
            // printf("\n");
        }
    }
    // maxpooling 1 calc
    for (int r = 0, i, j, k; r < 6; r++) {
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                p1[r][i * 12 + j] = maxpooling1(r, i * 48 + j * 2);
            }
        }
    }
    // conv 2 calc
    for (int r, s = 0, i, j, k; s < 16; s++) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                // calc
                for (tmp = c2w[s][150], r = 0; r < 6; r++) {
                    for (k = 0; k < 25; k++) {
                        tmp += c2w[s][r * 25 + k] *
                               p1[r][i * 12 + j + offset_2[k]];
                    }
                }
                c2[s][i * 8 + j] = max(0.0, tmp);
                // printf("%4.1lf ", c2[s][i*8+j]);
            }
            // printf("\n");
        }
        // printf("\n");
    }
    for (int r = 0, i, j, k; r < 16; r++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                p2[r][i * 4 + j] = maxpooling2(r, i * 16 + j * 2);
                //int t = i * 16 + j * 2;
                //wout << t << " " <<t+1 << "\n" << t+8 << " " << t+9 << "\n\n";
            }
            //wout << "\n";
        }
        //wout << "\n";
    }
    // dense 1
    for(int i = 0, j; i < 120; i++){
    	for(j = 0, tmp = d1w[i*257+256]; j < 256; j++)
    	{
    		tmp += d1w[i*257 + j] * p2[j&15][j>>4];
		}
		d1[i] = max(0.0, tmp);
	}
	// dense 2
    for(int i = 0, j; i < 84; i++){
    	for(j = 0, tmp = d2w[i*121+120]; j < 120; j++)
    	{
    		tmp += d2w[i*121+j] * d1[j];
		}
		d2[i] = max(0.0, tmp);
	}
	// dense 3
    for(int i = 0, j; i < 10; i++){
    	for(j = 0, tmp = d3w[i*85+84]; j < 84; j++)
    	{
    		tmp += d3w[i*85] * d2[j];
		}
		d3[i] = max(0.0, tmp);
	}
	// output
	for(int i = 0; i<10; i++)
		printf("%d : %lf\n", i, d3[i]);
		
    cout << "calc done!\n";
    return 0;
}
