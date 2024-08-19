def selection_sort(arr):
    # Traverse through all elements in the array
    for i in range(len(arr)):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap the found minimum element with the first unsorted element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def main():
    # Take input from the user
    user_input = input("Enter the array elements separated by spaces: ")
    # Convert the input string to a list of integers
    arr = list(map(int, user_input.split()))

    # Print the original array
    print("Original array:", arr)

    # Sort the array
    selection_sort(arr)

    # Print the sorted array
    print("Sorted array:", arr)

if __name__ == "__main__":
    main()
