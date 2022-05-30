data {
  int N;
  vector[N] ffrate;
  real unemp_data[N];
}

parameters {
  real alpha;
  real beta;
  real<lower=0> sigma;
}

transformed parameters {
  vector[N] mu = ffrate*beta + alpha;
}

model {
  alpha ~ normal(5, 1);
  beta ~ lognormal(0, 1);
  sigma ~ exponential(1);
  unemp_data ~ normal(mu, sigma);
}

generated quantities {
  vector[N] log_lik;
  real unemp_posterior[N];
  for (i in 1:N) {
    log_lik[i] = normal_lpdf(unemp_data[i] | mu[i], sigma);
    unemp_posterior[i] = normal_rng(mu[i], sigma);
  }
}
