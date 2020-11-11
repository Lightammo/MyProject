# 3.4.2 lambda函数
便携式函数

eg1.
```py
sorted(alist,key=lambda x : (x[0],x[1]))#多排序依据
```

eg2.
```py
scores={'s':155,'a':112}
sorted(scores.items() ,key=lambda x : x[0] )#scores是字典 用items转换为可迭代的结构
sorted(scores.items()'''形成键值对的元组''' ,key=lambda x : sum(x[1]) )#总成绩

```

# 综合运用
读取文章，得出频率词汇
```py
sorted(iterable,*,key=None,reverse=False)
```
## 1.数据清洗:特殊符号清洗
```py
for ch in ",*.()=":
    txt = txt.replace(ch,"")
```
## 2.统计截取
```py
word_count={}
word_list = txt.lower().split()
for word in word_list:
    word_count[word]=word_count.get(word,0)+1
```

## 3.对字典排序
```py
sorted_count = sorted(word_count.items() ,key = lambda x :x[1],reverse= Ture)
```
## 4.输出
```py
for i in range(10):
    word , times = sorted_count[i]
    print("{:<10}{}".format(word,times))
```

# 3.4.3 map函数
map()是一个高阶的内主函数(sorted,map,filter)

接收函数和可迭代对象，返回迭代器
map(func,iterator)免去了循环的嵌套的书写

```py
number=[[]]#二维的list,内有一定的数据
def mean(num_list):
    return sum(num_list)/len(num_list)

pin = list(map(mean,numbers))
#lambda可以写 mean(num_list) <=> lambda x : sum(x)/len(x)

#map调用的函数可以根据这个函数要求的参数,来决定参数的个数
```

# 综合应用:九宫格
用map()去扩散同一种操作方式;
## 1.建立一个字典
将字符和行号对应起来
```py
key_pos = {row[0]:i for i,row in enumerate(keyboard)}
#enumerate生成位序,内容的元组
```
## 2.找行、列-打包成函数
```py
def getchar(group):
    row = key_pos[group] #找行
    count = len(keyboard[row])
    col = (len(group)-1)%count
    return keyboard[row][col]
```

## 3.利用map开始搞
```py
txt ="xxxx"
keys = map(getchar,txt.split())
print("".join(list(keys)))
```

# 3.4.4 filter函数
filter()是一个高阶的内主函数(sorted,map,filter)

接收函数和可迭代对象，返回一个由可迭代对象中的特定元素(该函数针对该元素会返回True)--true的保留,false的撒死
filter(func,iterator)

eg.
```py

```

===============函数式编程================

## 数据清洗例子
states=['xxhue8wf8392h#%*(#^%(*#%))']
1. 去除空格
2. 去除标点
3. 大小写

```py
def clean_strings(strings):
    result=[]
    for value in strings:
        value = value.strip()#去除空格
        for ch in ",*.()=":
            value = value.replace(ch,"")
        value = value.title()#首字母大写,其余小写
        result.append(value)
    return result
```

模块化设计~~~
```py
def clean_strings(strings,ops):
    result=[]
    for value in strings:
        for function in ops:
            value = function(value)
        result.append(value)
    return result
clean_operations = [str.strip,remove_pun,str.title]
states = clean_strings(states,clean_operators)
```

# 3.5 异常:有点像switch
1. 错误和异常
   - 错误:语法错误 SyntaxError
   - 异常:运行时引发错误 ZeroDivisionError NameError TypeError ValueError IndexError(越界) 

2. 读法 异常类型：异常信息
3. 处理异常：try-except捕获异常
   - try:试图执行的语句
   - except 异常类型1：异常类型1的处理语句块。一直找到一个匹配的异常类型，找不到就程序就停止了
   - else:如果不发生异常,就执行else的代码块(可能else里面有不需要处理的异常)
   - finally:无论发生异常与否,最后都会被执行finally的代码快

>eg.从小键盘上接受一个整数,输入不是有效整数的时候重新输入

- while True+break结构
- 知道用户输入的不是整数,except捕获ValueError
```py
while True:
    try:
        x = int(input())
        break
    except:#加什么异常就处理什么异常,什么都不加就是所有的异常
        print(not again)
print(x)
```
- eval()可以直接处理四则运算的字符串比如1+2
- as 意思是 ***视为***  类似于 Typedef 
4. 自定义异常
   1. 命名和创建
    - 用类的形式被创建
    - 一般以Error结尾
   2. 例子

```py
#以父类为Exception创建
class ScoreError(Exception)
    pass

try:
    score = int(input())
    if score <0 or score > 100:
        raise ScoreError('txt')
    print(score)
except ScoreError
```
- 用户输入的合法性
- 用 raise 和 class 自定义异常跳出循环

# 3.6 模块和第三方库
## 3.6.1 模块(module)
- 模块以.py为结尾
- 实现模块化设计,多人开发,便于管理
## 3.6.2 导入(import)
- import的搜索路径
  - 当前路径
    - 写文件的位置
    - 解释器的当前路径
  - Python系统路径 lib标准库

```gant
'import module'->'当前'
```

- 保证导入成功的办法
  - 文件：同目录
  - 交互式：系统路径要指向所在位置

- 模块与空间命名
  - import module
  - from module import* 导入全部
  - from module import fun1,fun2 导入f1 f2
- 如果模块很长就用as
  - from module import matplotlib as plt  视为plt
- 导入可以增加可读性、简洁性

## 3.6.3 主模块
- 被导入的模块中，如果还存在一些其他的语句，那么这些语句也会被执行
- 每个模块都有名字属性：__name__
- 发起运行的python程序的 __name__ 取值为 __main__ 也就是正在运行的模块的 __name__ 就是 __main__ 
  - 处理方法 if __name__ == "__main__"代码中
  - 检查该模块是否为主程序,只有当他为主程序的时候,该段代码才会被执行

## 3.6.4 Package 包
- Python的程序结构
  - 包 → 模块 → 函数
  - 包是一个分层次的目录结构，引用函数的时候需要加入 前缀 包名. eg. package.module.func
  - 备注:主要是为了防止重命名
  - Python的包: 包含 __init__.py 文件的文件夹
  - 创建包的办法:
    - 在创建一个文件夹,在文件夹里面建立一个__init__.py的文件,文件夹名,就是包的名字
  - 包可以套娃,包子子包 BZZB  下面两个都可以
    - 1. import package1.package2.fib
    - 2. from package1.package2 import fib