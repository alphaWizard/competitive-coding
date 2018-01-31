#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int P[300000];
void calculate_prime_factors(int M = 300000) {  //P[i] is largest prime
    for (int i = 1; i <= M; i++) P[i] = 0;
    for (int i = 2; i <= M; i++) {
        if (P[i] == 0) { // hasn't touched i yet so it is prime
            // set i as the prime factor of all its multiples
            for (int j = i; j <= M; j += i) {
                P[j] = i;
            }
        }
    }
}  

int factorize(int n, int *ps, int *es) {
    // writes the factorization of n into ps and es
    int count = 0;
    while (n > 1) {
        int p = P[n];
        int e = 0;
        while (n % p == 0) {
            e++;
            n /= p;
        }
        ps[count] = p;
        es[count] = e;
        count++;
    }
    return count;
}  

int main() {

calculate_prime_factors();

//cout<<P[630];
int ps[1000],es[1000]; //prime factors detail
int t=factorize(630,ps,es);
for(int i=0;i<t;++i)
{
    cout<<ps[i]<<"= "<<es[i]<<endl;
}
 

    return 0;
}
