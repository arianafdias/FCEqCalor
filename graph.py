import numpy as np
import matplotlib.pyplot as plt

with open("SolucaoNumerica001.txt") as file:
    lst = []
    for line in file:
        lst.append([float(x) for x in line.split()])
        
SN_i = [(x[0]) for x in lst]
SN_x = [(x[1]) for x in lst]

with open("SolucaoNumerica01.txt") as file:
    lst = []
    for line in file:
        lst.append([float(x) for x in line.split()])
        
SN_i01 = [(x[0]) for x in lst]
SN_x01 = [(x[1]) for x in lst]


with open("SolucaoAnalitica.txt") as file:
    lst = []
    for line in file:
        lst.append([float(x) for x in line.split()])
        
SA_x = [(x[0]) for x in lst]
SA_u = [(x[1]) for x in lst]


with open("SolucaoNumerica05.txt") as file:
    lst = []
    for line in file:
        lst.append([float(x) for x in line.split()])
        
SN_i05 = [(x[0]) for x in lst]
SN_x05 = [(x[1]) for x in lst]



plt.plot(SA_x[0:2000],SA_u[0:2000],'o', label = 'Sol. Analítica')
plt.plot(SN_i[0:200],SN_x[0:200],'o', label = r'$\Delta x$ = 0.01')
plt.plot(SN_i01[0:20],SN_x01[0:20], 'o', label = r'$\Delta x$ = 0.1')
plt.plot(SN_i05[0:4],SN_x05[0:4],'o', label = r'$\Delta x$ = 0.5')

plt.xlabel(r'Distância ao Reservatório, x', fontsize = 20)
plt.ylabel('Temperatura, $T_A$',fontsize = 20)
plt.xticks(fontsize = 20)
plt.yticks(fontsize = 20)
plt.legend( loc = 'upper right',fontsize = 20)


plt.show()
