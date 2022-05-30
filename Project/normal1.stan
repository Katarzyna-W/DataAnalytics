generated quantities {
  real mu = normal_rng(2568, 878);
  real sigma = exponential_rng(878);
  real prior = normal_rng(mu, sigma);
}