N = int(input())
num = list(map(int, input().split()))
op = list(map(int, input().split()))

maximum = -1e9
minimum = 1e9


def dfs(depth, result, plus, minus, multiply, divide):
    global maximum, minimum
    if depth == N:
        maximum = max(result, maximum)
        minimum = min(result, minimum)
        return
    if plus:
        dfs(depth + 1, result + num[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfs(depth + 1, result - num[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfs(depth + 1, result * num[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfs(depth + 1, int(result / num[depth]), plus, minus, multiply, divide - 1)


dfs(1, num[0], op[0], op[1], op[2], op[3])
print(maximum)
print(minimum)