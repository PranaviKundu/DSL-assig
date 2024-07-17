n = int(input("Enter the size of the row: "))
m = int(input("Enter the size of the column: "))
matrix = []
print("Enter the elements row wise:")
for i in range(n):
    row = []
    for j in range(m):
        element = int(input(f"Enter the element [{i}][{j}]: "))
        row.append(element)
    matrix.append(row)

print("1. Check whether the matrix is upper triangular or not.")
print("2. Compute summation of diagonal elements.")
print("3. Compute transpose of a matrix.")
print("4. Add and subtract of two matrices.")
print("5. Multiplication of two matrix.")
print("6. To determine the location of saddle point of a matrix.")
print("7. To find if a matrix is magic square or not.\n")

a = int(input("Enter the number of the operation you want to run: "))

if a == 1:
    is_upper = True
    for i in range(1, n):
        for j in range(i):
            if matrix[i][j] != 0:
                is_upper = False
                break
        if not is_upper:
            break
    if is_upper:
        print("YES, it is an upper triangular matrix")
    else:
        print("NO, it is not an upper triangular matrix")

# Diagonal sum
elif a == 2:
    sum_diag = 0
    anti_dig_sum = 0
    for i in range(0, n):
        sum_diag += matrix[i][i]
        anti_dig_sum += matrix[i][n - 1 - i]
    print("The sum of the diagonal is:", sum_diag)
    print("The sum of the anti diagonal is:", anti_dig_sum)

elif a == 3:
    transpose_matrix = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(n):
        for j in range(m):
            transpose_matrix[j][i] = matrix[i][j]
    print("The transpose of the matrix is:")
    for row in transpose_matrix:
        print(row)

elif a == 4:
    print("Enter one more matrix to find the addition, subtraction of the two matrices")
    
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    matrix2 = []
    print("Enter the elements row-wise:")
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Enter element [{i}][{j}]: "))
            row.append(element)
        matrix2.append(row)
    
    if n != rows or m != cols:
        print("As both matrices are not of the same order, addition and subtraction are not possible.")
    else:
        sum_matrix = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                sum_matrix[i][j] = matrix[i][j] + matrix2[i][j]
        print("Sum matrix of both the matrices is:")
        for row in sum_matrix:
            print(row)
        
        sub_matrix = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                sub_matrix[i][j] = matrix[i][j] - matrix2[i][j]
        print("Subtraction matrix of both the matrices is:")
        for row in sub_matrix:
            print(row)
elif a==5:
    print("Enter one more matrix to find the multiplication of the two matrices")
    
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    matrix2 = []
    print("Enter the elements row-wise:")
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Enter element [{i}][{j}]: "))
            row.append(element)
        matrix2.append(row)
    result = [[0 for _ in range(cols)] for _ in range(n)]
    for i in range(n):
        for j in range(cols):
            for k in range(m):
                result[i][j] += matrix[i][k] * matrix2[k][j]
    print("Multiplication matrix of both the matrices is:")
    for row in result:
        print(row)
 
# To find the saddle point of a matrix                    
elif a == 6:
    saddle_points = []
    for i in range(n):
        row_min = min(matrix[i])
        min_col_indices = [j for j in range(m) if matrix[i][j] == row_min]
        for col_index in min_col_indices:
            col_max = max(matrix[row][col_index] for row in range(n))
            if col_max == row_min:
                saddle_points.append((i + 1, col_index + 1))
    print("Saddle points of the matrix are at:")
    for point in saddle_points:
        print(point)

# To find if the given matrix is magic square or not
elif a == 7:
    common_sum = sum(matrix[0])
    is_magic = True
    for row in matrix:
        if sum(row) != common_sum:
            is_magic = False
            break
    if is_magic:
        for col in range(n):
            if sum(matrix[row][col] for row in range(n)) != common_sum:
                is_magic = False
                break
    if is_magic:
        if sum(matrix[i][i] for i in range(n)) != common_sum:
            is_magic = False
    if is_magic:
        if sum(matrix[i][n - 1 - i] for i in range(n)) != common_sum:
            is_magic = False
    if is_magic:
        print("YES, it is a magic square")
    else:
        print("NO, it is not a magic square")

else:
    print("Invalid operation")
