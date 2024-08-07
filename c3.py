def input_matrix(rows, cols):
  matrix = []
  for i in range(rows):
      row = []
      for j in range(cols):
          element = int(input(f"Enter the element [{i}][{j}]: "))
          row.append(element)
      matrix.append(row)
  return matrix

n = int(input("Enter the number of rows: "))
m = int(input("Enter the number of columns: "))
matrix = input_matrix(n, m)

while True:
  print("\nSelect an operation:")
  print("1. Check whether the matrix is upper triangular or not.")
  print("2. Compute summation of diagonal elements.")
  print("3. Compute transpose of a matrix.")
  print("4. Add, subtract, and multiply two matrices.")
  print("5. Determine the location of saddle points in the matrix.")
  print("6. Find if a matrix is a magic square or not.")
  print("7. Exit")

  a = int(input("Enter the number of the operation you want to run: "))

  if a == 1:
      if n != m:
          print("Matrix is not square; cannot be upper triangular.")
      else:
          upper_triangular = True
          for i in range(n):
              for j in range(m):
                  if i > j and matrix[i][j] != 0:
                      upper_triangular = False
                      break
              if not upper_triangular:
                  break
          if upper_triangular:
              print("YES, it is an upper triangular matrix.")
          else:
              print("NO, it is not an upper triangular matrix.")

  elif a == 2:
      if n != m:
          print("Matrix is not square; cannot compute diagonal sums.")
      else:
          diagonal_sum = sum(matrix[i][i] for i in range(n))
          anti_diagonal_sum = sum(matrix[i][n - 1 - i] for i in range(n))
          print("The sum of the diagonal is:", diagonal_sum)
          print("The sum of the anti-diagonal is:", anti_diagonal_sum)

  elif a == 3:
      transpose_matrix = [[matrix[j][i] for j in range(n)] for i in range(m)]
      print("The transpose of the matrix is:")
      for row in transpose_matrix:
          print(row)

  elif a == 4:
      print("Enter one more matrix to find the addition, subtraction, and multiplication of the two matrices:")

      rows2 = int(input("Enter the number of rows: "))
      cols2 = int(input("Enter the number of columns: "))

      if n != rows2 or m != cols2:
          print("Matrices must be of the same order for addition and subtraction.")
      else:
          matrix2 = input_matrix(rows2, cols2)

          # Addition
          sum_matrix = [[matrix[i][j] + matrix2[i][j] for j in range(m)] for i in range(n)]
          print("Sum matrix of both matrices is:")
          for row in sum_matrix:
              print(row)

          # Subtraction
          sub_matrix = [[matrix[i][j] - matrix2[i][j] for j in range(m)] for i in range(n)]
          print("Subtraction matrix of both matrices is:")
          for row in sub_matrix:
              print(row)

          # Multiplication
          if m != rows2:
              print("Matrix multiplication not possible; incompatible dimensions.")
          else:
              result = [[sum(matrix[i][k] * matrix2[k][j] for k in range(m)) for j in range(cols2)] for i in range(n)]
              print("Multiplication result of both matrices is:")
              for row in result:
                  print(row)

  elif a == 5:
      saddle_points = []
      for i in range(n):
          row_min = min(matrix[i])
          col_indices = [j for j in range(m) if matrix[i][j] == row_min]
          for j in col_indices:
              if all(matrix[k][j] >= row_min for k in range(n)):
                  saddle_points.append((i, j))
      if saddle_points:
          print("Saddle points are at:")
          for point in saddle_points:
              print(f"Row: {point[0]+1}, Column: {point[1]+1}")
      else:
          print("No saddle points found.")

  elif a == 6:
      if n != m:
          print("Matrix is not square; cannot be a magic square.")
      else:
          magic_sum = sum(matrix[0])
          is_magic = all(sum(matrix[i]) == magic_sum for i in range(n)) and \
                     all(sum(matrix[j][i] for j in range(n)) == magic_sum for i in range(n)) and \
                     sum(matrix[i][i] for i in range(n)) == magic_sum and \
                     sum(matrix[i][n - 1 - i] for i in range(n)) == magic_sum

          if is_magic:
              print("The matrix is a magic square.")
          else:
              print("The matrix is not a magic square.")

  elif a == 7:
      print("Exiting program.")
      break

  else:
      print("Invalid operation. Please select a valid option.")
