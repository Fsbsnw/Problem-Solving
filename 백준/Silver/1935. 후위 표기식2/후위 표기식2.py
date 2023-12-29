import sys
input = sys.stdin.readline

def calc(num1, oper, num2):
    result = 0
    if oper == '+':
        result = num2 + num1
    elif oper == '-':
        result = num2 - num1
    elif oper == '*':
        result = num2 * num1
    else:
        result = num2 / num1
    return result

n = int(input())
s = input().rstrip()
stack = []
alpha = {}

for i in sorted(set(s)):
    if i.isalpha():
        alpha[i] = float(input())

for i in s:
    if i.isalpha():
        stack.append(alpha[i])
    else:
        if len(stack) >= 2:
            stack.append(calc(stack.pop(), i, stack.pop()))
print("{:.2f}".format(*stack))