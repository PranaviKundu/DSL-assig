def sentinel_search(arr, key):
    n = len(arr)
    last = arr[-1]
    arr[-1] = key

    i = 0
    while arr[i] != key:
        i += 1

    arr[-1] = last

    if i < n - 1 or arr[-1] == key:
        return True
    return False


# Main program
roll_numbers = [102, 215, 178, 110, 245, 190]  # Example array
print("Roll numbers of students who attended training program:")
print(roll_numbers)

# Input roll number to search
search_roll = int(input("\nEnter roll number to search: "))

# Sentinel search
if sentinel_search(roll_numbers, search_roll):
    print(f"Roll number {search_roll} attended the training (Sentinel Search).")
else:
    print(f"Roll number {search_roll} did not attend the training (Sentinel Search).")
