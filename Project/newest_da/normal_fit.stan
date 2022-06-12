data {
    int N;
    real burglaries[N];
}

parameters {
   real mu;
   real <lower = 0> sigma;
}

model {
    mu ~ normal(1300, 600);
    sigma ~ exponential(0.005);
    burglaries ~ normal(mu, sigma);
}

generated quantities {
    vector[N] log_lik;
    for (j in 1:N)
    {
        log_lik[j] = normal_lpdf(burglaries[j] | mu, sigma);
    }
    real burglary = normal_rng(mu, sigma);
}