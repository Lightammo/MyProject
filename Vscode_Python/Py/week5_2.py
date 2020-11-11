#coding=???

'''

    @author:Lyn
    @create:2020.10.14

'''

#=======================要求============================#
'''

    输入三组序列数据（列表或者字符串），按照位序组合三组数据，按照字典的形式输出

'''
#=======================Start===========================#
Elems1 = eval(input())
Elems2 = eval(input())
Elems3 = eval(input())
LenD=min(len(Elems1),len(Elems2),len(Elems3))
Dic={}
for i in range(1,LenD+1):
    Dic[i]=Elems1[i-1],Elems2[i-1],Elems3[i-1]
print(Dic)