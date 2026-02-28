row=int(input("Enter the no of rows"))
colm=int(input("Enter the no of columns"))
print("Enter elements row wise")
m=[]
for i in range(row):
    rows=[]
    for j in range(colm):
        r=int(input(f"Enter element at position  {i+1} {j+1} "))
        rows.append(r)
    m.append(rows)    
for j in range(colm):
    k=[]
    for i in range(row):
        k.append(m[i][j])
    print(k[::-1])
