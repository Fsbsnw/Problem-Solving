import sys
input = sys.stdin.readline

queue = []
for i in range(int(input())):
    command = input().split()
    if command[0] == "push":
        queue.append(command[1])
    elif command[0] == "size":
        print(len(queue))
    elif command[0] == "empty":
        print(1 if not len(queue) else 0)
    else:
        if queue:
            if command[0] == "front":
                print(queue[0])
            elif command[0] == "back":
                print(queue[-1])
            elif command[0] == "pop":
                print(queue.pop(0))
        else:
            print(-1)