while True:
    try:
        input()
        print(*sorted(list(map(int, input().split()))))
    except EOFError:
        break
