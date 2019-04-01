
if __name__ == '__main__':
    r = int(input())

    for i in range(r):
        word = input()
        if len(word) == 5:
            print(3)
        else:
            one = 'one'
            cnt = 0
            for w, o in zip(word, one):
                if w == o:
                    cnt += 1
            if cnt >=2:
                print(1)
            else:
                print(2)
