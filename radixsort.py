import time

def counting_sort(array, exp, comparison_count):
    n = len(array)
    output = [0] * n
    count = [0] * 10
    
    # Count occurrences of each digit
    for i in range(n):
        index = (array[i] // exp) % 10
        count[index] += 1
        comparison_count[0] += 1  # Increment comparisons for counting

    # Compute the cumulative count
    for i in range(1, 10):
        count[i] += count[i - 1]
        comparison_count[0] += 1  # Increment comparisons for cumulative count
    
    # Place the elements in sorted order
    i = n - 1
    while i >= 0:
        index = (array[i] // exp) % 10
        output[count[index] - 1] = array[i]
        count[index] -= 1
        i -= 1
        comparison_count[0] += 1  # Increment comparisons for placement
    
    # Copy the output array to array[], so that array[] contains sorted numbers
    for i in range(n):
        array[i] = output[i]

def radix_sort(array):
    # Initialize comparison count
    comparison_count = [0]
    
    # Find the maximum number to figure out the number of digits
    max_num = max(array)
    exp = 1  # Initialize exponent (1s, 10s, 100s, etc.)
    
    # Perform counting sort for each digit
    while max_num // exp > 0:
        counting_sort(array, exp, comparison_count)
        exp *= 10
    
    return comparison_count[0]

# Example usage:
if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the array elements: ").split()))
    
    print("The original array: ", array)
    
    # Measure time taken for Radix Sort
    array_copy = array.copy()
    start = time.time()
    comparisons = radix_sort(array_copy)
    end = time.time()
    
    print("The sorted array: ", array_copy)
    print(f"Radix sort took {(end - start) * 1_000_000: .2f} microseconds.")
    print(f"Total comparisons: {comparisons}")
