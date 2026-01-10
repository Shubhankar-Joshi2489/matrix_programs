rows=int(input("Enter no of rows"))
colums=int(input("Enter no of columns"))
matrix=[]
print("Enter the elements row wise")
for i in range (rows):
    row=[]
    for j in range (colums):
        e=int(input(f"Enter element at position {(i+1),(j+1)}"))
        row.append(e)
    matrix.append(row)
for i in range (rows):
    for j in range (colums):
       print(matrix[i][j],end="\t")
    print()