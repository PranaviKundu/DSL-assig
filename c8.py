def fibo_series(n):
    fibo_m_2 = 0  # (m-2)'th Fibonacci number
    fibo_m_1 = 1  # (m-1)'th Fibonacci number
    fibo_m = fibo_m_2 + fibo_m_1  # m'th Fibonacci number

    while fibo_m < n:
        fibo_m_2 = fibo_m_1
        fibo_m_1 = fibo_m
        fibo_m = fibo_m_2 + fibo_m_1

    return fibo_m_2, fibo_m_1, fibo_m


def fibonacci_search(arr, key):
    n = len(arr)
    fibo_m_2, fibo_m_1, fibo_m = fibo_series(n)

    offset = -1  # Initial offset set to -1

    while fibo_m > 1:
        # Check the valid index
        i = min(offset + fibo_m_2, n - 1)

        if arr[i] < key:
            # Move to the right subarray
            fibo_m = fibo_m_1
            fibo_m_1 = fibo_m_2
            fibo_m_2 = fibo_m - fibo_m_1
            offset = i

        elif arr[i] > key:
            # Move to the left subarray
            fibo_m = fibo_m_2
            fibo_m_1 = fibo_m_1 - fibo_m_2
            fibo_m_2 = fibo_m - fibo_m_1

        else:
            return i  # Key found at index i

    # Check if the last element matches the key
    if fibo_m_1 and offset + 1 < n and arr[offset + 1] == key:
        return offset + 1

    return -1  # Key not found


# Main program
n = int(input("Enter the number of elements in the array: "))
arr = []

for i in range(n):
    element = int(input(f"Enter element {i + 1}: "))
    arr.append(element)

# Sort the array (Fibonacci search requires a sorted array)
arr.sort()
print(f"Sorted array: {arr}")

key = int(input("Enter the number to find in the array: "))

index = fibonacci_search(arr, key)

if index != -1:
    print(f"Element found at index {index}")
else:
    print("Element not found")
