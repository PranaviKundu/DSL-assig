# Input number of students and counts for each game
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
x1 = []  # Cricket and Badminton
x2 = []  # Cricket or Badminton but not Football
x3 = []  # Neither Cricket nor Badminton
x4 = []  # Cricket and Football but not Badminton
x5 = []  # No games
x6 = []  # At least one game
x7 = []  # All games

# Calculate results
for roll_number in range(1, n+1):
    roll_number_str = str(roll_number)
    
    plays_cricket = roll_number_str in cr_list
    plays_badminton = roll_number_str in badi_list
    plays_football = roll_number_str in fobl_list
    
    # Students who play both cricket and badminton
    if plays_cricket and plays_badminton:
        x1.append(roll_number_str)
    
    # Students who play either cricket or badminton but not football
    if (plays_cricket or plays_badminton) and not plays_football:
        x2.append(roll_number_str)
    
    # Students who play neither cricket nor badminton
    if not plays_cricket and not plays_badminton:
        x3.append(roll_number_str)
    
    # Students who play both cricket and football but not badminton
    if plays_cricket and plays_football and not plays_badminton:
        x4.append(roll_number_str)
    
    # Students who do not play any game
    if not plays_cricket and not plays_badminton and not plays_football:
        x5.append(roll_number_str)
    
    # Students who play at least one game
    if plays_cricket or plays_badminton or plays_football:
        x6.append(roll_number_str)
    
    # Students who play all the games
    if plays_cricket and plays_badminton and plays_football:
        x7.append(roll_number_str)

# Print results
print("Students who play both cricket and badminton:", x1)
print("Students who play either cricket or badminton but not football:", x2)
print("Students who play neither badminton nor cricket:", x3)
print("Students who play both cricket and football but not badminton:", x4)
print("Students who do not play any game:", x5)
print("Students who play at least one game:", x6)
print("Students who play all the games:", x7)
