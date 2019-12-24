#include <iostream>

/* recursion ver
 *
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
*/

long long gcd(long long m, long long n) {

  if (m < n)
    std::swap(m, n);

  long long tmp;
  while (m % n != 0) {
    tmp = n;
    n = m % n;
    m = tmp;
  }

  return n;
}

long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
