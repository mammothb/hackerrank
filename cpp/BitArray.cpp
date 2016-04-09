#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  unsigned long long n;
  unsigned long long s;
  unsigned long long p;
  unsigned long long q;
  std::cin >> n >> s >> p >> q;

  unsigned long long p_231 = static_cast<unsigned long long>(pow(2, 31));
  unsigned long long a0 = s % p_231;
  unsigned long long counter = 1;

  auto f = [=](unsigned long long x) {
    return (x * p + q) % p_231;
  };

  // https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
  unsigned long long tortoise = f(a0);
  unsigned long long hare = f(tortoise);

  while (tortoise != hare) {
    if (counter++ >= n) {
      std::cout << n << std::endl;
      return 0;
    }
    tortoise = f(tortoise);
    hare = f(f(hare));
  }

  unsigned long long mu = 0;
  tortoise = a0;
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    ++mu;
  }

  unsigned long long lambda = 1;
  hare = f(tortoise);
  while(tortoise != hare) {
    hare = f(hare);
    ++lambda;
  }
  std::cout << lambda + mu << std::endl;

  return 0;
}
