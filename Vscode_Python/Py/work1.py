import xlrd,string
data = xlrd.open_workbook('D:\\workmap.xls')
table = data.sheets()[0]
strtables =""
for rown in range(4496):
    strtables += str(table.cell_value(rown,0))+ " "
    
for ch in ",*<>=#&$!?":
    strtables = strtables.replace(ch," ")

word_count={}
word_list = strtables.split()
for word in word_list:
    word_count[word]=word_count.get(word,0)+1

sorted_count = sorted(word_count.items() ,key = lambda x :x[1],reverse= True)

Chemical_count = {x[0]:x[1] for x in sorted_count if str(x[0][0]) in string.ascii_uppercase}
chemi_count = sorted(Chemical_count.items() ,key = lambda x :x[1],reverse= True)
for i in range(500):
    (word,times) = chemi_count[i]
    print("{:<20}{}".format(word,times))

