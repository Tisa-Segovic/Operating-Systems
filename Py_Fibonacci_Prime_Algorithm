def main():
    N = int(input('Enter an integer: \n> '))
    print(fib_prime(N,check_prime(N),check_fib(N)))

def check_prime(N):
    prime = ['P'] * (N+1)
    prime[0] = 'N'
    prime[1] = 'N'

    for i in range(2,N+1):
        if prime[i] == 'P':
            for j in range(2*i,N+1,i):
                prime[j] = 'N'
                
    prime_list = []
    num = 0
    for c in prime:
        if c == 'P':
            prime_list.append(num) # Now stored in the list
        num += 1
    return(prime_list)

def check_fib(N):
    og_list = []
    for i in range(0,N+1):
        og_list.append(i)

    fib_list = [0,1]
    i = 3
    for num in range(1,len(og_list)):
        if num == 1:
            one_r = fib_list[0]+fib_list[1]
            fib_list.append(one_r)
        elif num == int((fib_list[i-1]+fib_list[i-2])):
            fib_list.append(num)
            i += 1
    return fib_list
            
def fib_prime(N,prime_list,fib_list):
    prime_set = set(prime_list)
    fib_set = set(fib_list)
    N = []

    for number in prime_set.intersection(fib_set):
        N.append(number)
    return N

main()
