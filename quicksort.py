import time

n = int(input("Enter the size of the array: "))
array = list(map(int, input("Enter the array elements: ").split()))

# Validate the array length
if len(array) != n:
    print("Error: The number of elements does not match the specified size.")
    exit()

# Initialize a global variable for counting comparisons
comparisons = 0

def quick_sort(array, low, high):
    global comparisons
    if low < high:
        pivot = array[low]
        i = low + 1
        j = high
        
        while True:
            while i <= j and array[i] <= pivot:
                comparisons += 1  # Count comparisons
                i += 1
            while i <= j and array[j] > pivot:
                comparisons += 1  # Count comparisons
                j -= 1
            if i <= j:
                array[i], array[j] = array[j], array[i]
            else:
                break
        
        # Swap the pivot with the element at the partition index
        array[low], array[j] = array[j], array[low]
        
        # Recursively sort the sub-arrays
        quick_sort(array, low, j - 1)
        quick_sort(array, j + 1, high)

print("The original array: ", array)

# Measure time taken for Quick Sort
array_copy = array.copy()
start = time.time()
quick_sort(array_copy, 0, len(array_copy) - 1)
end = time.time()

print("The sorted array: ", array_copy)
print(f"Quick sort took {(end - start) * 1_000_000: .2f} microseconds.")
print(f"Total comparisons: {comparisons}")
