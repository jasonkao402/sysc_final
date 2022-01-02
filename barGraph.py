import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt

res_float = {
0: -6.31587,
1: 1.51689,
2: -4.51784,
3: 1.89325,
4: -9.96772,
5: -1.01239,
6: -10.5921,
7: 15.3189,
8: -4.72124,
9: -1.65421,
}
res_scInt = {
0: -6.39941,
1: 1.00879,
2: -4.43848,
3: 2.13965,
4: -10.7549,
5: -0.944336,
6: -10.6797,
7: 15.8906,
8: -4.82812,
9: -1.25977,
}

objects = np.arange(10)
x_pos = np.arange(10)
float_val = [res_float[a] for a in objects]
scInt_val = [res_scInt[a] for a in objects]

plt.title('LeNet Outputs (float)')
bplt = plt.bar(x_pos, float_val, align='center', alpha=0.5)
for value in bplt:
    height = value.get_height()
    plt.text(value.get_x(),
             0.9*height, f'{height:.3f}', ha='left', va='center')

plt.xticks(x_pos, objects)
plt.ylabel('Value')

plt.savefig('LeNet_float.png')
plt.show()

plt.title('LeNet Outputs (sc_int)')
bplt = plt.bar(x_pos, scInt_val, align='center', alpha=0.5)
for value in bplt:
    height = value.get_height()
    plt.text(value.get_x(),
             0.9*height, f'{height:.3f}', ha='left', va='center')
plt.xticks(x_pos, objects)
plt.ylabel('Value')

plt.savefig('LeNet_scInt.png')
plt.show()