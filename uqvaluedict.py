d={'A':[4,5,6,4],'B':[5,6,7,6],'c':[1,2,3,4]}
k={}
for i in d:
    k=set(d.get(i))
    print(i,k)
