def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # Find the minimum element in the remaining unsorted part of the array
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Get input from the user
numbers = input("Enter a list of numbers separated by spaces: ").split()
numbers = [int(num) for num in numbers]

# Call the selection_sort function
selection_sort(numbers)

# Print the sorted list
print("Sorted list:", numbers)