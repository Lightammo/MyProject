from random import random
from math import sqrt
import time
DARTS = 1000
hits = 0
for i in range(1,DARTS):
    x,y = random(),random()
    dist = sqrt( x**2 + y**2 )
    if dist <= 1.0:
        hits = hits +1
pi = 4 * (hits/DARTS)
print(pi)