generated quantities {
  real mu = normal_rng(1300, 600);  //1300 - mean based on research, 600 - std based on research
  real <lower = 0> sigma = exponential_rng(0.005); //uncertainty is 200, 1/0.005 = 200
  real burglary = normal_rng(mu, sigma);
}