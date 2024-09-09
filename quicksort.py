#quick sort
n = int(input("Enter the size of the array: "))
array = list(map(int, input("Enter the array elements: ").split()))
pivot=array[0]
i=array[1]
j=array[n-1]
def quick_sort(pivot,array, i,j):
    if i>j and array.index(pivot)<n:
        for p in range(n):
            if pivot<array[p]:
                i=array[p]
        for q in range(-1,-(n-1)):
            if pivot>array[q]:
                j=array[q]
        array[i], array[j]=array[j], array[i]
    if j<=i and array.index(pivot)<n:
        pivot=array[j]
        arr1=[]
        arr2=[]
        for s in range(0,j-1):
            arr1.append(array(s))
        for t in range(j+1,n):
            arr2.append(array(t))
        for u in range(n):
            if pivot<array[u]:
                i=array[u]
        for r in range(-1,-(n-1)):
            if pivot>array[r]:
                j=array[r]
        arr2[i], arr2[j]=arr2[j], arr2[i]
        arr1[i], arr1[j]=arr1[j], arr1[i]
        arr1= arr1.append(arr2)
print("The original array: ",array)
print("The sorted array: ",arr1 )
