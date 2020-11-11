#去除data列表中的重复元素，结果按数据出现的先后次序排列
def distinct(data):
    date1 = date.sort()
    for i in range(len(date)-1):
        if date1[i]==date1[i+1]:
            del date1[i]
    for i in range(len(date)):
        for j in range(date1[i])
    #去重处理

    return data
        
#输入一个列表 
x = input()
x = x.strip('[')
x = x.strip(']')
xlist = x.split(',')
xlist = [int(xlist[i]) for i in range(len(xlist))]

print(distinct(xlist))