
def forward(pos, k, mask):
    cnt = 0
    while True:
        while not mask[pos]:
            pos = (pos + 1) % len(mask)
        cnt += 1
        if cnt >= k:
            break
        pos = (pos + 1) % len(mask)
    return pos
            

def backward(pos, m, mask):
    cnt = 0
    while True:
        while not mask[pos]:
            pos = (pos - 1 + len(mask)) % len(mask)
        cnt += 1
        if cnt >= m:
            break
        pos = (pos - 1 + len(mask)) % len(mask)
    return pos

def simulate(n, k, m):
    left = n
    mask = [0] + [1] * (n)
    A = 1
    B = n

    while left > 0:
        A = forward(A, k, mask)
        B = backward(B, m, mask)
        mask[A] = 0
        mask[B] = 0
        if A != B:
            print("{:3d}{:3d}".format(A, B), end='')
            left -= 2
        else:
            print("{:3d}".format(A), end='')
            left -= 1
        if left:
            print(",", end='')
        else:
            print()


def main():
    cfg = input()
    while cfg != '0 0 0':
        cfg = list(map(int, cfg.split()))
        simulate(cfg[0], cfg[1], cfg[2])
        cfg = input()


if __name__ == '__main__':
    main()
