from random import randint, random, uniform

queries = randint(60, 65)

f= open("C:\\Users\\Pouya\\Desktop\\Test Cases For Avl Tree\\in\\input10.txt", "w")
print(queries)
f.write(str(queries) + "\n")
for i in range(0, queries):
    choice = randint(0, 3)
    if choice == 1:
        f.write("add " + str(round(uniform(0, 100), 1)) + "\n")
        print("add " + str(round(uniform(0, 100), 1)))
    elif choice == 2:
        f.write("remove " + str(round(uniform(0, 100), 1)) + "\n")
        print("remove " + str(round(uniform(0, 100), 1)))
    else:
        f.write("find " + str(round(uniform(0, 100), 1)) + "\n")
        print("find " + str(round(uniform(0, 100), 1)))