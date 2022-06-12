generated quantities {
  // real mu = normal_rng(1425, 450); //standard deviation of that variable
  real mu = normal_rng(1, 0.5);
  real  sigma = exponential_rng(0.8);
  real burglary = normal_rng(mu, sigma);
}