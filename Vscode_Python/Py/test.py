#coding = UTF-8
'''
    @功能 : 根据身高、体重计算BMI
    @author : 
    @create : 2020.9.20
'''
#=============程序开始=============#
#输入身高体重
height=float(input("请输入您的身高: "))
weight=float(input("请输入您的体重: "))

bmi=weight/(height*height)
print("宁的BMI指数为: "+str(bmi))

if bmi<18.5:
    print("您的体重过于轻盈~@_@~")
if bmi>=18.5 and bmi<24.9:
    print("正常")
if bmi>=24.9 and bmi<29.9:
    print("过重")
if bmi>=29.9:
    print("肥猪")