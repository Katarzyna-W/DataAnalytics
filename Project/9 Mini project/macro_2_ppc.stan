data {
  int N;
  real tbond[N];
}

generated quantities {
  real alpha = normal_rng(5, 1);
  real beta = lognormal_rng(0, 1);
  real sigma = exponential_rng(1);
  real unemp[N];
  for (i in 1:N) {
    unemp[N] = normal_rng(tbond[N]*beta + alpha, sigma);
  }
}
