#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int n = 1e5 + 1;
void SieveOfEratosthenes(int N)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    ll cnt = 1;
    for (int p = 2; cnt <= N; p++)
    {
        if (prime[p]){
            cout << p << " ";
            cnt++;
        }
    }
}

// Driver Program to test above function
int main()
{
    int N;
    cin >> N;
    SieveOfEratosthenes(N);
    return 0;
}
