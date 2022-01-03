import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt

float_val = [
-6.31587,
1.51689,
-4.51784,
1.89325,
-9.96772,
-1.01239,
-10.5921,
15.3189,
-4.72124,
-1.65421, 
]
scInt_val = [
-6.39941,
1.00879,
-4.43848,
2.13965,
-10.7549,
-0.944336,
-10.6797,
15.8906,
-4.82812,
-1.25977,
]

objects = np.arange(10)
x_pos = np.arange(10)
plt.title(f'LeNet Outputs (float, fullConnect), diff = { sum(abs(a - float_val[7]) for a in float_val):.3f}')
bplt = plt.bar(x_pos, float_val, align='center', alpha=0.5)
for value in bplt:
    height = value.get_height()
    plt.text(value.get_x(),
             0.9*height, f'{height:.3f}', ha='left', va='center')

plt.xticks(x_pos, objects)
plt.ylabel('Value')

plt.savefig('LeNet_float_fullConnect.png')
plt.show()

plt.title(f'LeNet Outputs (sc_int, fullConnect), diff = {sum(abs(a - scInt_val[7]) for a in scInt_val):.3f}')

bplt = plt.bar(x_pos, scInt_val, align='center', alpha=0.5)
for value in bplt:
    height = value.get_height()
    plt.text(value.get_x(),
             0.9*height, f'{height:.3f}', ha='left', va='center')
plt.xticks(x_pos, objects)
plt.ylabel('Value')

plt.savefig('LeNet_scInt_fullConnect.png')
plt.show()