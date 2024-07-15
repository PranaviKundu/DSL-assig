n = int(input("Enter no. of stuednts: "))
l = []
for i in range(0,n):
    x = int(input("Enter marks: "))
    l.append(x)

mx = l[0]
mn = l[0]
sum = 0
freq = 0
absent = 0
pa = 0

for i in range(0,n):
    if(l[i]<mn and l[i] != -1):
        mn = l[i]
    if(l[i]>mx):
        mx = l[i]

    if(l[i] != -1):
        sum += l[i]

    if(l[i] == -1):
        absent += 1

    if(l[i] >= 33):
        pa += 1

students_passed = pa/n * 100
max_freq = 0
hi = 0
for i in range(0,n):
    freq = 0
    for j in range(0,n):
        if(l[i] == l[j] and l[i] != -1):
            freq += 1
    
    if(freq>max_freq):
        max_freq = freq
        hi = l[i]

print("maximum marks is: ",mx)
print("minimum marks is: ",mn)
print("number of absent students:",absent)
print("average marks :", sum/(n-absent))
print("percentage of students: ",students_passed)
print("percentage of student faled: ",100 - students_passed)
print("marks with highest frequency: ",hi)