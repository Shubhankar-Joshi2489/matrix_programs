s="helloworld!helloworld!helloworld!helloworld!"
k=s.split('!')
l=s.split('!')
k.pop()
print(k)
print("@ is used for encoding")
for i in range(len(k)):
    k[i]='@'
print("compressed string after encoding",k)
print("decompressed string after decoding",l)

