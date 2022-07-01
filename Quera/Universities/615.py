# Created by:
# Sadra Setarehdan
# Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
# Date: 6-22-2022

a=int(input())
b=[0]*4
for i in range(4-1,-1,-1):
    b[i]=str(a%10)
    a=a//10
print('saal:'+str(b[0]+b[1]))
print('maah:'+str(b[2]+b[3]))
