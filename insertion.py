import time

def insertion_sort(arr):
    print("Before Insertion Sort:", arr)
    n = len(arr)
    comparison_count = 0  # Initialize comparison count
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        
        # Count comparisons in the while loop
        while j >= 0:
            comparison_count += 1
            if arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            else:
                break
        arr[j + 1] = key

        print(f"After inserting element {key}: {arr}")

    print("After Insertion Sort:", arr)
    print(f"Total comparisons: {comparison_count}")

def main():
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the array elements: ").split()))

    array_copy = array.copy()
    start = time.time()
    insertion_sort(array_copy)
    end = time.time()
    
    print(f"Insertion Sort took {(end - start) * 1_000_000:.2f} microseconds.")

if __name__ == "__main__":
    main()
