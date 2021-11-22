def pack(d:list):
    b1=bytearray()
    j=0
    for i in d:
        b1.append(i.encode('UTF-8'))
    return b1

    
def unpack(d:bytearray):
    l1=list()
    for i in d:
        l1.append(i.decode('UTF-8'))
    return l1


a="123123"
a.encode

i = ['2018993', 'Andy Hu', 26, 'male', True, 175.3, 78, [12,99,77]]
assert(type(i) == list)

r = pack(i)
assert type(r)==bytearray or type(r)==bytes

o = unpack(r)
print(i==o)
