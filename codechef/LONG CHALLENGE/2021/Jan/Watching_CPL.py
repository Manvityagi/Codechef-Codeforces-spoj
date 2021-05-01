def solve():
        n, k = map(int, input().split()) 
        h = [int(e) for e in input().split()]
        h.sort(reverse=True)
        i, t1, t2, s1, s2 = 0, 0, 0, 0, 0
        while(i<n):
            s1 = s1 + h[i]
            if(s1 >= k):
                i += 1
                t1 = 1 
                break
            i+=1 
        if(t1 == 0): 
            print(-1,end="\n")
            return
        
        while(i<n):
            s2 = s2 + h[i]
            if(s2 >= k):
                i += 1
                t2 = 1 
                break
            i+=1 
        if(t2 == 0): 
            print(-1,end="\n")
            return
        
        print(i,end="\n")

def main():
    t = int(input())
    while t > 0: 
        solve()
        t-=1


if __name__ == "__main__":
    main()