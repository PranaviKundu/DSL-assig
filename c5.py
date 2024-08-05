# Read input values
n = int(input("Enter number of non-zero elements in the matrix: "))
row = int(input("Enter number of rows in the matrix: "))
col = int(input("Enter the number of columns in the matrix: "))

# Initialize the matrix
matrix = []

for i in range(row):
    rows = []
    for j in range(col):
        element = int(input(f"Enter the element[{i}][{j}]: "))
        rows.append(element)
    matrix.append(rows)  # Append 'rows' instead of 'row'

# Initialize the sparse matrix
sparse_matrix = [[0 for _ in range(3)] for _ in range(n + 1)]
sparse_matrix[0][0] = row
sparse_matrix[0][1] = col
sparse_matrix[0][2] = n

# Fill the sparse matrix with non-zero elements
index = 1  # Start filling from the second row of sparse_matrix
for i in range(row):
    for j in range(col):
        if matrix[i][j] != 0:
            sparse_matrix[index][0] = i
            sparse_matrix[index][1] = j
            sparse_matrix[index][2] = matrix[i][j]
            index += 1

print("Sparse Matrix Representation:")
for row in sparse_matrix:
    print(row)

# Transpose of the sparse matrix
def transpose_sparse_matrix(sparse_matrix):
    if len(sparse_matrix) <= 1:
        return sparse_matrix

    rows = sparse_matrix[0][0]
    cols = sparse_matrix[0][1]
    non_zero_count = sparse_matrix[0][2]
    
    transpose_matrix = [[0 for _ in range(3)] for _ in range(non_zero_count + 1)]
    transpose_matrix[0][0] = cols
    transpose_matrix[0][1] = rows
    
    for i in range(1, non_zero_count + 1):
        row, col, value = sparse_matrix[i]
        transpose_matrix[i] = [col, row, value]
    
    transpose_matrix[0][2] = non_zero_count
    return transpose_matrix

# Calculate the transpose of the sparse matrix
transposed_sparse_matrix = transpose_sparse_matrix(sparse_matrix)
print("Transposed Sparse Matrix Representation:")
for row in transposed_sparse_matrix:
    print(row)

# Reconstruct the transposed matrix from the transposed sparse matrix
transposed_matrix = [[0 for _ in range(row)] for _ in range(col)]

for i in range(1, len(transposed_sparse_matrix)):
    transposed_row, transposed_col, value = transposed_sparse_matrix[i]
    transposed_matrix[transposed_row][transposed_col] = value

print("Transposed Main Matrix (non-zero values only):")
for r in transposed_matrix:
    print(' '.join(map(str, r)))
