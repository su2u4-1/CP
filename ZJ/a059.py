from math import isqrt

DD = (0, 1, 5, 14, 30, 55, 91, 140, 204, 285, 385, 506, 650, 819, 1015, 1240, 1496, 1785, 2109, 2470, 2870, 3311, 3795, 4324, 4900, 5525, 6201, 6930, 7714, 8555, 9455, 10416, 11440)
for i in range(int(input())):
    a, b = int(input()), int(input())
    print(f"Case {i + 1}:", DD[isqrt(b)] - DD[isqrt(max(a - 1, 0))])
