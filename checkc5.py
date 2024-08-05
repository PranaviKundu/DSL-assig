m=int(input("Rows:"))
n=int(input("Cols:"))
v=int(input("Values:"))
l1=[m,n,v]
sparse=[]
sparse.append(l1)
for i in range(0,v):
    a=int(input("Row value:"))
    b=int(input("Col Value:"))
    c=int(input("Value:"))
    if a>m-1:
        continue
    if b>n-1:
        continue
    l=[a,b,c]
    sparse.append(l)
print(sparse)
def simpletrans(m):
    mt=[]
    mt.append([m[0][1], m[0][0],m[0][2]])
    nocol=m[0][1]
    values=m[0][2]
    for i in range(0,nocol):
        for j in range(1,values+1):
            if i== m[j][1]:
                y=[i,m[j][0], m[j][2]]
                mt.append(y)
    print(mt)
    
simpletrans(sparse)