import sys
import re

def main():
    answer = set()
    for line in sys.stdin:
        line = line.lower()
        regex = re.compile('[^a-z ]')
        line = regex.sub(' ', line).split()
        for word in line:
            answer.add(word)
    for word in sorted(list(answer)):
        print(word)


if __name__ == '__main__':
    main()    
