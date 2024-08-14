#fibonacci search

fibo_m_2=0
fibo_m_1=1
fibo_m=fibo_m_2 + fibo_m_1
def fibo_series(n):
    while(fibo_m<n):
        fibo_m_2=fibo_m_1
        fibo_m_1=fibo_m
        fibo_m= fibo_m_2 +fibo_m_1
        return fibo_m_2,fibo_m_1,fibo_m

offset =0
i=offset+fibo_m_2
n=int(input("Enter the number of elements in the array: "))
key=int(input("Enter the number to find in the array: "))
steps=0
arr=[n]
for i in range(0,n):
    element=int(input("Enter the element in the array: "))
    arr[i].append(element)
fibo_series(n)

for j in range(0,n):
    if(arr[i]<key):
        offset=i
        fibo_series(n-1)
    