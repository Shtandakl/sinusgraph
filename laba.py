import re
import pandas as pd
import matplotlib.pyplot as plt

def read_file(filename):
    result = {"angles": [], "values": []}
    with open(filename) as file:
        for line in file:
            parts = line.split(" = ")
            parts[0] = re.sub("sin\(|\)", "", parts[0])

            result["angles"].append(int(parts[0]))
            result["values"].append(float(parts[1].rstrip()))

    return result

taylor = read_file('./Taylor.txt')
func_sin = read_file('./sin.txt')

df = pd.DataFrame({
    'angle': taylor["angles"],
    'value_taylor': taylor["values"],
    'value_func_sin': func_sin["values"]
})

plt.plot(df['value_taylor'])
plt.plot(df['value_func_sin'])

plt.show()