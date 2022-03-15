data {
  int<lower=1> N;  //number of ys, supplied by the interface
}

parameters {
   real y[N];  //probabilistic variabls ys
   real theta;	//probabilistic variable theta
}

model {	
	//add conventional probability density for the ys
	//given theta to the joint log probability density 
	//using equivalent sampling statement
  y ~ normal(theta, 1);
  
  	//add mariginal probability density for the ys
	//given theta to the joint log probability density 
	//using equivalent sampling statement
  theta ~ normal(0, 1);
}
generated quantities {
   real mean_y = mean(y);
}