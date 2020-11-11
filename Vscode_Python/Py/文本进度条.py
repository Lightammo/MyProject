'''
文本进度_version 1.0
'''
import time
scale = 20
print("{:=^30}".format("Start"))
for i in range(scale+1):
    a = "*"*(i)
    b = "."*(scale-i)
    c = i/scale
    print("\r{:>4.0%} [{}->{}]".format(c,a,b),end="")
    time.sleep(0.3)
print("\n{:=^30}".format("End"))