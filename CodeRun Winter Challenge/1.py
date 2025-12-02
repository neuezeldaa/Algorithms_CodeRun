import math

def main():
    R,B = map(int,input().split())
    total_area = R+B
    WH = (R+4)//2

    discriminant = WH * WH - 4*total_area

    d = math.isqrt(discriminant)

    w = (WH + d) // 2
    h = (WH - d) // 2

    print(w, h)

if __name__ == '__main__':
    main()
