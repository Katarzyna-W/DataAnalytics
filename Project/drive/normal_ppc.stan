generated quantities {
  // real mu = normal_rng(1425, 450); //standard deviation of that variable
  real mu = normal_rng(1300, 600);
  real <lower = 0> sigma = exponential_rng(0.005);
  real burglary = normal_rng(mu, sigma);
}