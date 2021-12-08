l = []
while True:
    x = input()
    if x == '':
        break
    l.append(x.split(':'))
d = dict(l)
s = input('请输入要查询的课程：\n')
try:
    print(d[s])
except:
    print('没有该门课程')