import sys
def result(name,roll_no,atten,c1=0,c2=0,c3=0,c4=0,c5=0):
    l = {"Name": "", "Roll_no": "", "Atten": "", "C1": 0, "C2": 0, "C3": 0, "C4": 0, "C5": 0, "marks": 0}
    l["Name"] = name
    l["Roll_no"] = roll_no
    l["Atten"] = atten
    l["C1"] = c1
    l["C2"] = c2
    l["C3"] = c3
    l["C4"] = c4
    l["C5"] = c5
    if(atten<75):
        print("Fail")
        sys.exit(0)
    s=[l["C1"],l["C2"],l["C3"],l["C4"],l["C5"]]
    s.sort()
    m1=s.pop()
    m2=s.pop()
    m3=s.pop()
    m4=s.pop()
    l["marks"]=(m1+m2+m3+m4)/4
    return l
print("Input format -(Enter name,roll no ,attendance ,M1,M2,M3,M4)")
n=input("Enter name")
r=int(input("Enter roll no"))
a=int(input("Enter attendeance"))
s1=int(input("Enter marks subject 1"))
s2=int(input("Enter marks subject 2"))
s3=int(input("Enter marks subject 3"))
s4=int(input("Enter marks subject 4"))
s5=int(input("Enter marks of minor subject 5"))
k=result(n,r,a,s1,s2,s3,s4,s5)
print(k)


