def merg_sort(lis):
    index0 = 0
    indexn = len(lis)
    if indexn < 2:
        return lis[0]
    midval = indexn // 2
    left = lis[:midval]
    right = lis[midval:]

    return merg_sort(left) + merg_sort(right)



nlis = [1, 3, 2, 5, 4, 7, 6, 9, 8, 0, 3]

merg_sort(nlis)
