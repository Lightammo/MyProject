'''
获得用户输入的一个数字，替换其中 0~9 为中文字符“〇一二三四五六七八九”，
输出替换后结果。请完善代码。
'''
n = input("请输入一个数字：")
s = "〇一二三四五六七八九"
i=0
for c in "0123456789":
    n = n.replace(c,s[i])
    i+=1
print(n)