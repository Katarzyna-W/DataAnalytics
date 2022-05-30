data {
  int N;
  real unemp_data[N];
}

parameters {
  real mu;
  real<lower=0> sigma;
}

model {
  mu ~ normal(5, 1);
  sigma ~ exponential(1);
  unemp_data ~ normal(mu, sigma);
}

generated quantities {
  vector[N] log_lik;
  for (i in 1:N) {
    log_lik[i] = normal_lpdf(unemp_data[i] | mu, sigma);
  }
  real unemp_posterior = normal_rng(mu, sigma);
}