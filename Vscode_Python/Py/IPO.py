import datetime
id = input()
year = int(id[6:10])
month = int(id[10:12])
day = int(id[12:14])
now_year = datetime.datetime.now().year
now_month = datetime.datetime.now().month
now_day = datetime.datetime.now().day
age = now_year - year
if month > now_month:
    age-=1
elif month == now_month:
    if day > now_day:
        age-=1
print(str(age))