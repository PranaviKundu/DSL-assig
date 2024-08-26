import time

def insertion_sort(arr):
    print("Before Insertion Sort:", arr)
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

        print(f"After inserting element {key}: {arr}")

    print("After Insertion Sort:", arr)

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
