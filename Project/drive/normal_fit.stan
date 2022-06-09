data {
    int N;
    real burglaries [N];
}

parameters {
   real mu;
   real <lower = 0> sigma;
}

model {
    // mu ~ normal(1400, 600);
    // sigma ~ exponential(0.005);
    mu ~ normal(1300, 600);
    sigma ~ exponential(0.005);
    burglaries ~ normal(mu, sigma);
}

generated quantities {
    vector[N] log_lik;
    array [N] real burglary;
    // int j = 0;
    for (j in 1:N)
    {
        burglary[j] = normal_rng(mu, sigma);
        log_lik[j] = normal_lpdf(burglaries[j] | mu, sigma);
    }
}