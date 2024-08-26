import time

def bubble_sort(arr):
    print("Before Bubble Sort:", arr)
    n = len(arr)
    for i in range(n - 1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        # Print the array after each pass
        print(f"After pass {n - i}: {arr}")
    print("After Bubble Sort:", arr)

def main():
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the array elements: ").split()))

    array_copy = array.copy()
    start = time.time()
    bubble_sort(array_copy)
    end = time.time()
    
    print(f"Bubble Sort took {(end - start) * 1_000_000:.2f} microseconds.")

if __name__ == "__main__":
    main()
