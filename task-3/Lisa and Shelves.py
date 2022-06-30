a=int(input())
b=0
for i in range(1,int(a**(0.5))+1):
  if a%i==0  :
    if a/i==i:
      b+=1
    else:
      b+=2
print(b)