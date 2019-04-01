import sys
from collections import defaultdict

def norm(word):
    return ''.join(sorted(word.lower()))

def main():
    words = list()
    answer = list()
    dict_ = defaultdict(int)
    for line in sys.stdin:
        if '#' in line:
            break
        words.extend(line.split())
    for word in words:
        dict_[norm(word)] += 1
    for word in words:
        if dict_[norm(word)] == 1:
            answer.append(word)
    for word in sorted(answer):
        print(word)

if __name__ == '__main__':
    main()
