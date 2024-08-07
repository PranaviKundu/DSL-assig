# Function to read matrix input from the user
def read_matrix():
    n = int(input("Enter number of non-zero elements in the matrix: "))
    row = int(input("Enter number of rows in the matrix: "))
    col = int(input("Enter the number of columns in the matrix: "))

    matrix = []
    for i in range(row):
        rows = []
        for j in range(col):
            element = int(input(f"Enter the element[{i}][{j}]: "))
            rows.append(element)
        matrix.append(rows)

    return matrix, row, col, n

# Function to create a sparse matrix representation
def create_sparse_matrix(matrix, row, col, n):
    sparse_matrix = [[0 for _ in range(3)] for _ in range(n + 1)]
    sparse_matrix[0] = [row, col, n]

    index = 1
    for i in range(row):
        for j in range(col):
            if matrix[i][j] != 0:
                sparse_matrix[index] = [i, j, matrix[i][j]]
                index += 1

    return sparse_matrix

# Function to transpose a sparse matrix
def transpose_sparse_matrix(sparse_matrix):
    if len(sparse_matrix) <= 1:
        return sparse_matrix

    rows, cols, non_zero_count = sparse_matrix[0]
    transpose_matrix = [[0 for _ in range(3)] for _ in range(non_zero_count + 1)]
    transpose_matrix[0] = [cols, rows, non_zero_count]

    for i in range(1, non_zero_count + 1):
        row, col, value = sparse_matrix[i]
        transpose_matrix[i] = [col, row, value]

    return transpose_matrix

# Function to add two sparse matrices
def add_sparse_matrices(sparse_a, sparse_b):
    if sparse_a[0][0] != sparse_b[0][0] or sparse_a[0][1] != sparse_b[0][1]:
        raise ValueError("Matrices must have the same dimensions for addition.")

    result_sparse = []
    result_dict = {}

    for i in range(1, sparse_a[0][2] + 1):
        row, col, value = sparse_a[i]
        result_dict[(row, col)] = result_dict.get((row, col), 0) + value

    for i in range(1, sparse_b[0][2] + 1):
        row, col, value = sparse_b[i]
        result_dict[(row, col)] = result_dict.get((row, col), 0) + value

    for (row, col), value in result_dict.items():
        if value != 0:
            result_sparse.append([row, col, value])

    # Add header
    result_sparse.insert(0, [sparse_a[0][0], sparse_a[0][1], len(result_sparse)])
    return result_sparse

# Main execution
matrix, row, col, n = read_matrix()
sparse_matrix = create_sparse_matrix(matrix, row, col, n)

print("Sparse Matrix Representation:")
for r in sparse_matrix:
    print(r)

transposed_sparse_matrix = transpose_sparse_matrix(sparse_matrix)
print("Transposed Sparse Matrix Representation:")
for r in transposed_sparse_matrix:
    print(r)

# Reconstruct the transposed matrix
transposed_matrix = [[0 for _ in range(row)] for _ in range(col)]
for i in range(1, len(transposed_sparse_matrix)):
    transposed_row, transposed_col, value = transposed_sparse_matrix[i]
    transposed_matrix[transposed_row][transposed_col] = value

print("Transposed Main Matrix (non-zero values only):")
for r in transposed_matrix:
    print(' '.join(map(str, r)))

# Example for adding two sparse matrices
print("\n--- Adding Two Sparse Matrices ---")
print("Matrix A:")
sparse_a = create_sparse_matrix(matrix, row, col, n)
for r in sparse_a:
    print(r)

print("Matrix B:")
sparse_b = create_sparse_matrix(matrix, row, col, n)  # You can modify this to read a second matrix
for r in sparse_b:
    print(r)

result_sparse = add_sparse_matrices(sparse_a, sparse_b)
print("Result Sparse Matrix after Addition:")
for r in result_sparse:
    print(r)
