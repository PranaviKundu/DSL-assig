#to take input of polynomial in 2 forms
  #one -- using an array to store cofficent of x in the index of their degee value
  #two -- using a list to store list of all the pairs of degree and cofficient


n=int(input("Enter the highest degree of the first polynomial: "))
arr = []
for i in range(0,n+1):
    ele=int(input(f"Enter the cofficient of the degree [{i}]: "))
    arr.append(ele)
     
n2=int(input("Enter the highest degree of the first polynomial: "))
arr2 = []
for j in range(0,n2+1):
    ele=int(input(f"Enter the cofficient of the degree [{i}]: "))
    arr2.append(ele)



# n = int(input("Enter number of elements: "))
# arr = []
# for i in range(n):
#     ele = int(input(f"Enter element {i+1}: "))
#     arr.append(ele)

# print(arr)