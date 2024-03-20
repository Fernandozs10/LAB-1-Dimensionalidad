import matplotlib.pyplot as plt

data = []

#lee los datos del archivo creado
with open('datos50.txt', 'r') as file:
    for line in file:
        data.append(float(line.strip()))
        
#creamos el histograma con los datos
plt.hist(data, bins=50, edgecolor='black')
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.title('50 dimensiones')
plt.grid(True)
plt.show()
