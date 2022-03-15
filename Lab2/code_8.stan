data {
	int<lower=1> N; //number of ys
}

parameters {
	real y[N]; // probabilistic variables y
	real theta; // probabilistic variable theta
}

model {
	//add conditional probability density for the ys
	//given theta to the joint log probability density
	//using the vectorized log probability density
	target += normal_lpdf(theta | 0,1);
	
	//Add marginal probability density for theta
	//to the joint log probability density
	target += normal_lpdf(theta | 0,1);
}