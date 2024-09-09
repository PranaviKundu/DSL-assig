def linear_search(nums, target):
    comparisons = 0
    for i in range(len(nums)):
        comparisons += 1
        if nums[i] == target:
            return i, comparisons
    return -1, comparisons

def binary_search(nums, target):
    comparisons = 0
    low = 0
    high = len(nums) - 1

    while low <= high:
        comparisons += 1
        mid = (low + high) // 2

        if target == nums[mid]:
            return mid, comparisons
        elif target < nums[mid]:
            high = mid - 1
        else:
            low = mid + 1
    
    return -1, comparisons

if __name__ == "__main__":
    while True:
        try:
            size = int(input("Enter the size of the array: "))
            if size <= 0:
                print("Array size must be greater than 0.")
                continue
            break
        except ValueError:
            print("Please enter a valid integer for the size.")
    
    nums = []
    print("Enter the elements of the array:")
    for i in range(size):
        while True:
            try:
                num = int(input(f"Element {i + 1}: "))
                nums.append(num)
                break
            except ValueError:
                print("Please enter a valid integer for the element.")
    
    # Sort the array for binary search
    nums.sort()
    
    while True:
        try:
            target = int(input("Enter the number you want to search for: "))
            break
        except ValueError:
            print("Please enter a valid integer for the target.")
    
    index_linear, comparisons_linear = linear_search(nums, target)
    index_binary, comparisons_binary = binary_search(nums, target)
    
    if index_linear != -1:
        print(f"(Linear Search) Target {target} found at index: {index_linear}. Comparisons made: {comparisons_linear}")
    else:
        print(f"(Linear Search) Target {target} not found in the list. Comparisons made: {comparisons_linear}")
    
    if index_binary != -1:
        print(f"(Binary Search) Target {target} found at index: {index_binary}. Comparisons made: {comparisons_binary}")
    else:
        print(f"(Binary Search) Target {target} not found in the list. Comparisons made: {comparisons_binary}")
