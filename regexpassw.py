import re
s=input("Enter all the  passwords sepated by comma")
l=s.split(",")
for i in l:
    pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[\$#@])[\sa-zA-Z0-9\$#@]{6,12}$"
    if(re.match(pattern,i)):
        print("Valid",i)
    else:
        print("Not Valid")