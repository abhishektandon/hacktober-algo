def divide_and_conquer(arr1,arr2):
    if len(arr1) == len(arr2) == 1:
        return arr1[0] + arr2[0]
    elif len(arr1) == 1:
        return arr1[0] + divide_and_conquer(arr2[0:1],arr2[1:])
    elif len(arr2) == 1:
        return arr2[0] + divide_and_conquer(arr1[:1],arr1[1:])
    else:
        return divide_and_conquer(arr1[0:int(len(arr1)/2)],arr1[(int(len(arr1)/2)) + 1:]) + divide_and_conquer(arr2[0:int(len(arr2)/2)],arr2[(int(len(arr2)/2)) + 1:])

def arr_sum(arr):
    return divide_and_conquer(arr[0:int(len(arr)/2)+1],arr[(int(len(arr)/2)) + 1:])
def get_arr():
    arr = [int(item) for item in input("Enter the list items : ").split()]
    return arr

print(arr_sum(get_arr())) 
