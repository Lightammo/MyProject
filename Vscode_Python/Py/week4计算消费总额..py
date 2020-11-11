'''
请补充横线处的代码。dictMenu 中存放了你的双人下午套餐（包括咖啡 2 份和点心 2 份）的价格，
计算并输出消费总额。
'''
#请删除横线，编辑文件，运行提交
dictMenu = {'卡布奇洛':32,'摩卡':30,'抹茶蛋糕':28,'布朗尼':26}
sum=0 
for i in dictMenu:
    sum +=  dictMenu[i]
print(sum)