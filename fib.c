//Alex Nguyen

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_MEMO_SIZE 1000 

   unsigned long long memo_r[MAX_MEMO_SIZE];
   unsigned long long memo_i[MAX_MEMO_SIZE];

  
   unsigned long long fib_r_core(unsigned long long n) {
      if (n <= 1)
         return n;
      return fib_r_core(n - 1) + fib_r_core(n - 2);
   }

   
   unsigned long long fib_r(unsigned long long n) {
      if (n <= 1)
         return n;

      if (memo_r[n] != 0)
         return memo_r[n]; 

      memo_r[n] = fib_r_core(n);
      return memo_r[n];
   }

   
   unsigned long long fib_i_core(unsigned long long n) {
      if (n <= 1)
         return n;

      unsigned long long prev = 0;
      unsigned long long curr = 1;
      unsigned long long next;

      for (unsigned long long i = 2; i <= n; ++i) {
         next = prev + curr;
         prev = curr;
         curr = next;
      }
      return curr;
   }

   
   unsigned long long fib_i(unsigned long long n) {
      if (n <= 1)
         return n;

      if (memo_i[n] != 0)
         return memo_i[n]; 

      memo_i[n] = fib_i_core(n);
      return memo_i[n];
   }

   int main(int argc, char *argv[]) {

      unsigned long long number = strtoull(argv[1], NULL, 10);
      
      char method = argv[2][0];

      number = number - 1;
      for (int i = 0; i < MAX_MEMO_SIZE; i++) {
         memo_r[i] = 0;
         memo_i[i] = 0;
      }

      unsigned long long result;
      if (method == 'r') {
       
         result = fib_r(number);
      } 
      else if (method == 'i') {
      
         result = fib_i(number);
      }
      //printf ("%llu\n", number);
      printf("%llu\n", result);
     
      return 0;
   }
