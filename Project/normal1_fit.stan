data {
  int N;
  real larceny_data[N];
}

parameters {
  real mu;
  real<lower=0> sigma;
}

model {
  mu ~ normal(2568, 878);
  sigma ~ exponential(878);
  larceny_data ~ normal(mu, sigma);
}

generated quantities {
  vector[N] log_lik;
  for (i in 1:N) {
    log_lik[i] = normal_lpdf(larceny_data[i] | mu, sigma);
  }
  real larceny_posterior = normal_rng(mu, sigma);
}