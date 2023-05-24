def selection_sort(arr):
    n=len(arr)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if arr[j]<arr[min_index]:
                min_index=j
        arr[i],arr[min_index]=arr[min_index],arr[i]
numbers=input("Enter list: ").split()
numbers=[int(num) for num in numbers]

selection_sort(numbers)

print("Sorted list: ",numbers)



from nltk.chat.util import Chat,reflections

pairs=[
    [r'hello',
     ['hi',]],
    []
]

def chatty():
    chat=Chat(pairs,reflections)
    chat.converse()


if __name__=="__main__":
    chatty()