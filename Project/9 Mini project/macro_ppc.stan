generated quantities {
  real mu = normal_rng(5, 1);
  real sigma = exponential_rng(1);
  real unemp_prior = normal_rng(mu, sigma);
}