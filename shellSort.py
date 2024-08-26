import time

def shell_sort(arr):
    print("Before Shell Sort:", arr)
    n = len(arr)
    gap = n // 2
    
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp

        print(f"After gap {gap}: {arr}")
        
        gap //= 2
    
    print("After Shell Sort:", arr)

def main():
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the array elements: ").split()))

    array_copy = array.copy()
    start = time.time()
    shell_sort(array_copy)
    end = time.time()
    
    print(f"Shell Sort took {(end - start) * 1_000_000:.2f} microseconds.")

if __name__ == "__main__":
    main()
