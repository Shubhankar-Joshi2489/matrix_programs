
a=input("Enter string 1")
b=input("enter string 2")
c=a.split()
uq1=set(c)
f1={items:c.count(items) for items in uq1}
d=b.split()
uq2=set(d)
f2={items:d.count(items) for items in uq2}
all=uq1|uq2
for i in all:
    fq1=f1.get(i,0)
    fq2=f2.get(i,0)
    diff=abs(fq1-fq2)
    if(diff>0):
        print(i*diff)
    
