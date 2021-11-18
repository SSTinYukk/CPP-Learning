def find_stu(N):
    stu_list = [0] * N
    for i in range(N):
        stu_list[i] = input().split() 

    sum = []
    sum0 = 1
    for i in range(N):
        for j in range(3):
            stu_list[i][j] = int(stu_list[i][j])
            sum0 = sum0 * stu_list[i][j]
        sum.append(sum0)
        sum0 = 1
    i=sum.index(max(sum))
    name2 = stu_list[i][3]
    i=sum.index(min(sum))
    name1 = stu_list[i][3]
    print ("%s took clay from %s." % (name2, name1))

    n = int(input())
    if n != -1:
        find_stu(n)
    else:
        pass

n = int(input())
if n != -1:
    find_stu(n)
else:
    pass