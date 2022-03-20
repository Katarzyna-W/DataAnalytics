data {
int<lower=1> N; //number of observations
vector[N] y; // observations
}

parameters {
real mu;
real<lower=0> sigma;
}

model {
//prior model
mu ~ normal(0,1);
sigmna ~ normal(0,1);

//observational model
y ~normal(mu, sigma);
}