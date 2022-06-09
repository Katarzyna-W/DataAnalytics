generated quantities {
  real mu = normal_rng(data_mu, 0.3*data_mu); //standard deviation of that variable
  // real sigma = normal_rng(data_sigma, 0.3*data_sigma); //sigma dodatnia
  real sigma = abs(normal_rng(0, 1));
  real y = normal_rng(mu, sigma);
}