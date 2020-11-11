#十进制->任意进制转换
def getSign(a):
    if a>=0:
        return ""
    else:
        return "-"

def getString(absA,b):
    if absA==0:
        return str(0)
    listtemp=[]
    TempX=['A','B','C','D','E','F']
    while(absA!=0):
        if absA%b<10:
            listtemp.append(absA%b)
        else:
            listtemp.append(str(TempX[absA%b-10]))
        absA=absA//b
    listtemp.reverse()
    strtemp="".join([str(i) for i in listtemp])
    return strtemp

a=int(input())
b=int(input())

mark=getSign(a)
bitString=getString(abs(a),b)

print(mark+bitString)