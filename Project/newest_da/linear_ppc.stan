data {
   int N;
   real larceny[N];
}

generated quantities {
   real alpha = normal_rng(1275, 600);
   real beta = normal_rng(0.1, 0.085);
   // real beta = lognormal_rng(0.5, 1);
   real <lower = 0> sigma = exponential_rng(0.005);
   real <lower = 0> burglary[N];
   for (i in 1:N) {
      burglary[i] = normal_rng(larceny[i]*beta + alpha, sigma);
   }
}