import random,string
random.seed(10)
chars = string.ascii_letters + string.digits
#code = [random.choice(chars) for i in range(20)]
for i in range(20):
    print(random.choice(chars),end='')