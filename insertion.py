def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print(arr)

def main():
    n = int(input("Enter number of elements: "))

    print("Enter the elements:")
    array = []
    for _ in range(n):
        array.append(int(input()))

    insertion_sort(array)

    print("Sorted array:")
    print(array)

if __name__ == "__main__":
    main()
