data {
   int N;
   vector[N] larceny;
   real burglaries[N];
}

parameters {
   real alpha;
   real beta;
   real <lower=0> sigma;
}

transformed parameters {
   vector[N] mu = larceny*beta+alpha;
}

model {
   alpha ~ normal(1300, 600);
   beta ~ lognormal(0, 1);
   sigma ~ exponential(0.00167);
   burglaries ~ normal(mu, sigma);
}

generated quantities {
   array [N] real burglary;
   vector[N] log_lik;
   for (i in 1:N) {
       burglary[i] = normal_rng(mu[i], sigma);
       log_lik[i] = normal_lpdf(burglaries[i] | mu[i], sigma);
   }
}