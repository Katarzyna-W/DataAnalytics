data {
int<lower=0> N;
int<lower=0, upper=1> y[N];
}

parameters {
real<lower=0, upper = 1> theta;
}

model{
theta ~ bta(1,1);
y~bernoulli(theta);
}