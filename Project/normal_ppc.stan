data{
    int data_mu;
    int data_sigma;
}

generated quantities {
  // real mu = normal_rng(2500, 0.3*2500); //standard deviation of that variable
  // real sigma = normal_rng(500, 0.3*500);
  // real prior = normal_rng(mu, sigma);
  real mu = normal_rng(data_mu, 0.3*data_mu); //standard deviation of that variable
  real sigma = normal_rng(data_sigma, 0.3*data_sigma);
  real prior = normal_rng(mu, sigma);
}