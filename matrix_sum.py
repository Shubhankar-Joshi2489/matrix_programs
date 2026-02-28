rows=int(input("Enter the no of rows  "))
cols=int(input("Enter the no of columns"))
matrix=[]
print("Enter elemts row wise")
for i in range(rows):
    row=[]
    for j in range(cols):
        e=int(input(f"Enter the element at {(i+1),(j+1)}"))
        row.append(e)
    matrix.append(row)
sum=0  
for i in range (rows):
    for j in range (cols):
       print(matrix[i][j],end="\t")
       sum=sum+matrix[i][j]
    print()

print(sum)   