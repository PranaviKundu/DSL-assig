n = int(input("Enter the total number of students in class: "))
cri_count = int(input("Enter the number of students who play cricket: "))
badi_count = int(input("Enter the number of students who play badminton: "))
fobl_count = int(input("Enter the number of students who play football: "))

cr_list = []
badi_list = []
fobl_list = []

# Input collection for cricket players
for i in range(cri_count):
    user_input = input("Enter roll number of students who play cricket: ")
    cr_list.append(user_input)

# Input collection for badminton players
for i in range(badi_count):
    user_input = input("Enter roll number of students who play badminton: ")
    badi_list.append(user_input)

# Input collection for football players
for i in range(fobl_count):
    user_input = input("Enter roll number of students who play football: ")
    fobl_list.append(user_input)

# Initialize lists to store results
x1 = []
x2 = []
x3 = []
x4 = []
x5 = []
x6 = []
x7 = []

# Calculate results
for roll_number in range(1, n+1):
    if str(roll_number) in cr_list and str(roll_number) in badi_list:
        x1.append(str(roll_number))
    if str(roll_number) in cr_list or str(roll_number) in badi_list:
        if str(roll_number) not in fobl_list:
            x2.append(str(roll_number))
    if str(roll_number) not in cr_list and str(roll_number) not in badi_list:
        x3.append(str(roll_number))
    if str(roll_number) in cr_list and str(roll_number) in fobl_list and str(roll_number) not in badi_list:
        x4.append(str(roll_number))
    if str(roll_number) not in cr_list and str(roll_number) not in badi_list and str(roll_number) not in fobl_list:
        x5.append(str(roll_number))
    if str(roll_number) in cr_list or str(roll_number) in badi_list or str(roll_number) in fobl_list:
        x6.append(str(roll_number))
    if str(roll_number) in cr_list and str(roll_number) in badi_list and str(roll_number) in fobl_list:
        x7.append(str(roll_number))

# Print results
print("Students who play both cricket and badminton:", x1)
print("Students who play either cricket or badminton but not football:", x2)
print("Students who play neither badminton nor cricket:", x3)
print("Students who play both cricket and football but not badminton:", x4)
print("Students who do not play any game:", x5)
print("Students who play at least one game:", x6)
print("Students who play all the games:", x7)
