#! /usr/bin/python3
import random 
Max =  10
num =  10

arr = []
for i in range(0, num):
    t = random.randint(0, Max - 1)
    arr.append(t)
print(arr)

file = open('./test.txt', 'w')

for i in arr:
    file.write(str(i) + '\n')

file.close()
