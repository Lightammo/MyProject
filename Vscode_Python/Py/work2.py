def means(List):
    return sum(List)/len(List)

def linearRegression(xlist,ylist):
    xmean,ymean = means(xlist),means(ylist)
    bNumerator = -len(xlist)*xmean*ymean
    bDenominator = -len(ylist)*xmean**2
    for x , y in zip(xlist,ylist):
        bNumerator += x*y
        bDenominator += x**2
    b = bNumerator/bDenominator
    a = ymean - b*xmean
    return b,a
    
def Datacollect():
    dataname , data = [] , []
    with open("F:\\User\\Documents\\Pythoncode\\data\\Gdata.txt", mode='r' , encoding = "utf-8") as f:
        for line in f:
            splitedLine = line.strip().split()
            if '批发和零售业' in splitedLine[0]:
                years = [int(x[:-1]) for x in splitedLine[1:]] 
            else:
                dataname.append('{:<10}'.format(splitedLine[0]))
                data.append([float(x) for x in splitedLine[1:]])
        for i in range(len(dataname)):
                for ch in " ":
                    dataname[i] = dataname[i].replace(ch,"")

    return years,dataname,data

def NumSolve(slope,intercept):
    return slope*2019+intercept,slope*2020+intercept,slope*2021+intercept,slope*2022+intercept

Year,Dataname,Data=Datacollect()

Year.reverse()
for i in range(len(Data)):
    Data[i].reverse()

for i in range(len(Data)):
    bData,aData = linearRegression(Year,Data[i])
    newdata = NumSolve(bData,aData)   
    for j in range(len(newdata)):
        Data[i].append(newdata[j])

for i in [2019,2020,2021,2022]:
    Year.append(i)

Dataname.insert(0,"年份/批发和零售业")
Data.insert(0,Year)
for i in range(1,len(Data)):
    for j in range(len(Data[0])):
        if i < 2:
            Data[i][j] = round(Data[i][j],0)
        elif i == 3:
            Data[i][j] = round(Data[i][j],1)
        else:
            Data[i][j] = round(Data[i][j],1)

print("{:=^150}".format("开始输出"))
for i in range(len(Dataname)):
    for j in range(len(Data[0])):
        print("{:<10}".format(Data[i][j]), end= '')
    print("{:<15}\n".format(Dataname[i]),end = '')
print("{:=^150}".format("结束输出"))