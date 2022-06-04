data{
    int data_mu;
    int data_sigma;
}

generated quantities {
  real mu = normal_rng(data_mu, 0.3*data_mu); //standard deviation of that variable
  real sigma = normal_rng(data_sigma, 0.3*data_sigma);
  real prior = normal_rng(2500, 500);
  // real mu = normal_rng(data_mu, 0.3*data_mu); //standard deviation of that variable
  // real sigma = normal_rng(data_sigma, 0.3*data_sigma);
  // real prior = normal_rng(mu, sigma);
}