def toInt(time):
    return int(''.join(time.split(':')))

def isInclude(nowX, nowY, preX, preY):
    if nowX >= preY or nowY <= preX:
        return False
    return True

def solution(book_time):
    book_time.sort(key = lambda x : x[0])
    # print(book_time)
    arr = []
    for i in range(len(book_time)):
        checkIn = toInt(book_time[i][0])
        if toInt(book_time[i][1]) % 100 >= 50:
            checkOut = toInt(book_time[i][1]) + 50
        else:
            checkOut = toInt(book_time[i][1]) + 10
        cnt = 1
        
        for j in range(i, -1, -1):
            if i == j:
                continue
            checkInCompare = toInt(book_time[j][0])
            if toInt(book_time[j][1]) % 100 >= 50:
                checkOutCompare = toInt(book_time[j][1]) + 50
            else:
                checkOutCompare = toInt(book_time[j][1]) + 10
            if isInclude(checkIn, checkOut, checkInCompare, checkOutCompare):
                cnt += 1
                # print(cnt, i, j)
                # print(checkIn, checkOut, checkInCompare, checkOutCompare)
        arr.append(cnt)
    return max(arr)