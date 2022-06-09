data {
   int N;
   real larceny[N];
}

generated quantities {
   real alpha = normal_rng(1300, 600);
   real beta1 = normal_rng(0.1, 0.2);
   real beta2 = normal_rng(0.1, 0.1);
   real <lower = 0> sigma = exponential_rng(0.005);
   real <lower = 0> burglary[N];
   for (i in 1:N) {
      burglary[i] = normal_rng(larceny[i]*beta1 + larceny[i]^2*beta2 + alpha, sigma);
   }
}