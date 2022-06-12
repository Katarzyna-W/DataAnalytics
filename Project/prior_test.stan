data {
   int N;
   real dane[N];
   real std;
   real mean;
}

generated quantities {
   real alpha = normal_rng(1200, 35);
   real beta = normal_rng(0.5, 0.15);
   // real sigma = exponential_rng(0.004);
   real sigma = exponential_rng(0.02); //bo 1/50
   real prior[N];
   for (i in 1:N) {
        prior[i] = normal_rng( dane[i]*beta+alpha, sigma);
   }
}