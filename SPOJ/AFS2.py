t=input()
while t>0:
    n=input()
    prev=n
    i=2
    ans= - (n*(n+1))/2

    while prev > n/i:
        ans=ans+ (i-1)*( ((prev)*(prev+1))-((n/i)*(n/i+1)))/2
        prev=n/i
        i=i+1
    while prev>0:
        ans=ans+ prev*(n/prev)
        prev=prev-1
    print ans
    t=t-1
