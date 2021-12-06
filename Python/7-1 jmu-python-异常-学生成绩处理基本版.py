def basic():
    n=eval(input())
    nums=[]
    for i in range(0,n):
        i_stream=input()
        for j in i_stream:
            if(j==' '):
                continue
            elif(j>='0' and j<='9'):
                num=i_stream[i_stream.index(j):len(i_stream)+1]
                try:
                    nums.append(int(num))
                    break
                except ValueError:
                     print("Error for data \"%s\"! Break\nProcess Completed" %(i_stream))
                     return
            else:
                print("Error for data \"%s\"! Break\nProcess Completed" %(i_stream))
                return
    ave=0.0
    for i in nums:
        ave=ave+i
    ave=ave/len(nums)
    print("All OK\navg grade = %.2f\nProcess Completed" %(ave))
basic()