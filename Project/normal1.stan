data{
    int data_mu;
    int data_sigma;
}

generated quantities {
  real mu = normal_rng(data_mu, data_sigma);
  real sigma = exponential_rng(data_sigma);
  real prior = normal_rng(mu, sigma);
}