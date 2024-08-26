def insertion_sort(arr):
    comparisons = 0  # Initialize comparison count

    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0:
            comparisons += 1  # Count each comparison
            if key < arr[j]:
                arr[j + 1] = arr[j]
                j -= 1
            else:
                break  # Exit the loop if no more comparisons are needed

        arr[j + 1] = key
        print(arr)  # Optional: Print the array after each insertion

    return comparisons  # Return the number of comparisons

def main():
    n = int(input("Enter number of elements: "))

    print("Enter the elements:")
    array = []
    for _ in range(n):
        array.append(int(input()))

    # Print the original array
    print("Original array:")
    print(array)

    # Sort the array and get the number of comparisons
    comparisons = insertion_sort(array)

    # Print the sorted array
    print("Sorted array:")
    print(array)

    # Print the number of comparisons
    print(f"Total number of comparisons: {comparisons}")

if __name__ == "__main__":
    main()
