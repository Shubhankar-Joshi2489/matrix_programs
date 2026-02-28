'''import os
if not os.path.exists("shubhankar.txt"):
    f=open("shubhankar.txt","x")
    f.close()
else:
    print("file already exsist") '''
try:
    f=open("shubhankar.txt","x")
    f.close()
except FileExistsError:
    print("file already exsist")