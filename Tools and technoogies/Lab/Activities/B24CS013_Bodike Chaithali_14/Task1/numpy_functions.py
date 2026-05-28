import numpy as np

def f1(x):
    return np.sin(x) * np.exp(-0.1 * x) + np.cos(x**2) / (x**2 + 1)

def f2(x):
    return np.log(x**2 + 1) + np.sqrt(np.sin(x) + 2)

def f3(x):
    return np.exp(-np.sin(x)) * np.cosh(0.5 * x) - np.arctan(x)

def f4(x):
    return (x**3 - 2 * x + 1) / (x**2 + 1) + np.sin(3 * x) * np.cos(x**2)

def f5(x):
    return np.sqrt(np.abs(x)) * np.sin(1 / (x + 0.1)) + np.log(x**2 + 2)

def f6(x):
    return (np.sin(x) * np.cos(3 * x)) / (1 + np.exp(-x)) + (x**2 + 1)**(1/3)

def f7(x):
    return np.exp(-x**2) * np.sin(5 * x) + np.log(x + 2) / (x + 1)

def f8(x):
    return np.tanh(x) + (np.cos(x) / (1 + x**2)) + np.exp(-x/5)

def f9(x):
    return np.sin(x**3) * np.exp(-0.5 * x) + (1 / (1 + x**4))

def f10(x):
    return np.sqrt(np.abs(np.sin(x))) + np.cosh(x / 2) - (np.log(x**2 + 1) / (x + 1))


x = [0.5, 1.0, 1.5, 2.0, 2.5]

functions = [f1, f2, f3, f4, f5, f6, f7, f8, f9, f10]

print(f"{'x':>5}", end="")
for i in range(1, 11):
    print(f"{'f'+str(i):>12}", end="")
print("\n",end="")

for i in x:
    print(f"{i:5.2f}", end="")
    for f in functions:
        print(f"{f(i):12.6f}", end="")
    print()
