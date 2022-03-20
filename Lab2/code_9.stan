data {
	int<lower=1> N; //Number of ys
}

parameters {
	real y[N]; //probbilistic variables ys
	real theta; //probabilistic variable theta
}

model {
	//add conditional probability density for the ys
	//given theta to the joint log probability density
	//with increamental contributions in a loop
	
	for (n in 1:N)
		target += normal_lpdf(y[n] |theta, 1);
		
	//add marginal probability density for theta
	// to the joint log probability density
	target += normal_lpdf(theta | 0, 1);
}
