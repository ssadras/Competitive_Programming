# Created by:
# Sadra Setarehdan
# Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
# Date: 6-22-2022

def f(a):
    if a==1:
        return(1)
    else:
        return(a*f(a-1))
print(f(int(input())))
