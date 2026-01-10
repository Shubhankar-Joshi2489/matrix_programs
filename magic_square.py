r=int(input("Enter the no of rows "))
c=int(input("Enter the no of columns"))

print("Enter element row wise")
m=[]
for i in range (r):
    rows=[]
    for j in range(c):
        row=int(input(f"Enter the element at {i+1}{j+1}"))
        rows.append(row)
    m.append(rows)
    
def magic_matrix(m):
    mgno=sum(m[0])  #First row sum as magic const   
    for i in m: #checking for row sum
        if(mgno!=sum(i)):
            return False
    for j in range(c):#column sum
        col_sum=sum(m[i][j] for i in range(r))
        if(mgno!=col_sum):
            return False
    diag1_sum=sum(m[i][i] for i in range(r))# main diagonal
    if(mgno!=diag1_sum):
        return False
    diag2_sum = sum(m[i][r- 1 - i] for i in range(r)) #anti-diagonal
    if(mgno!=diag2_sum):
        return False
    return True
if magic_matrix(m):
    print("Yes, it is a Magic Square!")
else:
    print("No, it is not a Magic Square.")