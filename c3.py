
n= int(input("Enter the size of the row:"))
m= int(input("Enter the size of the column:"))
matrix=[]
print("Enter the elements row wise:")
for i in range(n):
    row=[]
    for j in range(m):
        element=int(input("Enter the element [{i}][{j}]:"))
        row.append(element)
    matrix.append(row) 
print("1.Check whether the matrix is upper triangular or not." )
print("2.Compute summation of diagonal elements.")
print("3.compute transpose of a matrix.")
print("4.Add, substract and multiply two matrices.")
print("5.To determine the location of saddle point of a matrix.")
print("6.To find if a matrix is magic square or not."/n)

a=int(input("Enter the number of the operation you want to run."))
if a==1:
    for row in range(1,n+1):
        for element in range(0,row-1):
            if matrix[row] [element]!=0:
                print("NO it is not a upper triangular matrix")
                break
        break
        print("YES it is a upper triangular matrix")
#diagonal sum
elif a==2:
    sum=0
    anti_dig_sum=0
    for i in range(0,n): 
        sum=sum+matrix[i][i]
        anti_dig_sum += matrix[i][n-1-i]
    print("The sum of the diagonal is:", sum)
    print("The sum of the anti diagonal is:", anti_dig_sum)
elif a==3:
    transpose_matrix=[]
    for i in range(0,n):
        for j in range(0,m):
            transpose_matrix[i][j]==matrix[j][i]
    print("The transpose of the matrix is:", transpose_matrix)
elif a==4:
    print("Enter one more matrix to find the addition, subtraction and multiplication of the two matrix")
    
    # Taking input for the dimensions of the matrix
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))

    matrix2 = []
    print("Enter the elements row-wise:")

    # Taking input for each element of the matrix
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Enter element [{i}][{j}]: "))
            row.append(element)
        matrix2.append(row)
    if n!=rows & m!=cols:
        print("As boh the matrix are not of the same order addition and subtraction not possible.")
    else:
        sum_matrix=[]
        for i in range(0,n):
            for j in range(0,m):
                sum_matrix[i][j]=matrix[i][j]+matrix2[i][j]
        print("Sum matrix of both the matrices is:", sum_matrix)
        sub_matrix=[]
        for i in range(0,n):
            for j in range(0,m):
                sub_matrix[i][j]=matrix[i][j]-matrix2[i][j]
        print("Subtraction matrix of both the matrices is:", sub_matrix)
        # multiplicaton of matrices
        result=[]
        for i in range(len(matrix)):
            l=[0]*len(matrix2[0])
            result.append(l)
        for x in range(len(matrix)):
            for y in range(len(matrix[0])):
                for z in range(len(matrix[0])):
                    result[x][y]+=matrix[x][z] * matrix2[z][y]
                    print(result)
elif(a==5):
    saddle_point=[]
    row=len(matrix)
    col=len(matrix[0])
    for i in range(row):
        row_min=matrix[i][0]
        min_col_i=[0]
        for j in range(i,col):
            if matrix[i][j]<row_min:
                min_col_i=[j]
            elif matrix[i][j]==row_min:
                min_col_i.append(j)
        for col_i in min_col_i:
            is_saddle=True
            for k in range(row):
                if matrix[k][col+1]>row_min:
                    is_saddle=False
                    break
            if is_saddle:
                saddle_point.append((i+1,col_i+1))
            print(saddle_point)
elif(a==6):
    n=len(matrix)
    common_sum=sum(matrix[0])
    is_magic=True


else:
    print("Invalid operation")
        
