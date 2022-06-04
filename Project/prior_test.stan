data {
   int N;
   real dane[N];
   int std;
   int mean;
}

generated quantities {
   real alpha = normal_rng(mean, std);
   real beta = normal_rng(0,10);
   real sigma = exponential_rng(0.067);
   real prior[N];
   for (i in 1:N) {
       prior[i] = normal_rng(dane[i]*beta+alpha, sigma);
   }
}