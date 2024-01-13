import sys
input = sys.stdin.readline

a, b = map(int, input().split())
arr = []
people = {}
for i in range(a + b):
    person = input().rstrip()
    try:
        people[person] += 1
        arr.append(person)
    except:
        people[person] = 1
arr.sort()
print(len(arr))
for _ in arr:
    print(_)