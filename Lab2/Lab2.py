from cmdstanpy import CmdStanModel
import pandas as pd
import arviz as az 
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats

"""-----------------------Exercise 1-----------------------""" 
#F=9, N=8
F = len('Katarzyna')
N = len('Wątorska')
L = len('Wątorska')

#1 complie stan model and sample it
my_stan_model = CmdStanModel('code_1.stan')
samples = my_stan_model.sample(data = {'M' : 'F'})

#2 dataframe
samples_dataframe = samples.draws_pd()

#3 histograms of y_sim and lambda
samples_lambda = samples_dataframe['lambda']
samples_lambda.plot.hist(bins = 20)
plt.show()

samples_dataframe2 = samples_dataframe.drop(samples_dataframe.columns[0:3],axis=1)
samples_dataframe2.plot.hist(subplots=True, bins=30)
plt.show()


"""-----------------------Exercise 2-----------------------""" 
bern1 = CmdStanModel(stan_file='code_2.stan')
samples_bern1 = bern1.sample(data={'N':2, 'y':[0,2]})
bern2 = CmdStanModel(stan_file='code_3.stan')
samples_bern2 = bern2.sample(data={'N':2, 'y':[0,2]})

theta1 = samples_bern1.stan_variable(name='theta')
theta2 = samples_bern2.stan_variable(name='theta')
df = pd.DataFrame({'theta1': theta1, 'theta2': theta2})
df.plot.hist(subplots=True, bins=30)
plt.show()


"""-----------------------Exercise 3-----------------------""" 
#1 unconstrained parameteres
model_gm1 = CmdStanModel(stan_file='code_4.stan')
out_gamma1 = model_gm1.sample(output_dir='samples',iter_sampling=6000,iter_warmup=1000, seed=4838282)
out_gamma1.diagnose()
N=500
xs = np.linspace(0,8,N)
pdfs = stats.gamma.pdf(xs, 1.25, scale = 1 / 1.25) 

plt.plot(xs, pdfs, linewidth=2)

theta_gm1 = model_gm1.stan_variable(name='theta')
df_gm1 = pd.DataFrame({'theta': theta_gm1})
df_gm1.plot.hist(bins=160)
plt.show()

plt.gca().set_xlabel("theta")
plt.gca().set_

#2 constrained parameters
model_gm2 = CmdStanModel(stan_file='code_5.stan')
out_gamma2 = model_gm2.sample(output_dir='samples',iter_sampling=6000,iter_warmup=1000, seed=4838282)
out_gamma2.diagnose()
N=500
xs = np.linspace(0,8,N)
pdfs = stats.gamma.pdf(xs, 1.25, scale = 1 / 1.25) 

plt.plot(xs, pdfs, linewidth=2)

theta_gm2 = model_gm2.stan_variable(name='theta')
df_gm2 = pd.DataFrame({'theta': theta_gm2})
df_gm2.plot.hist(bins=160)
plt.show()


plt.gca().set_xlabel("theta")
plt.gca().set_ylabel("Probability Density Function")
plt.show()


"""-----------------------Exercise 4-----------------------""" 
model_tune = CmdStanModel(stan_file='code_6.stan')

y0 = 6 # initial guess for the equation solving

data={'y_guess':[y0],
        'theta':[(F+L)/2]}
tunes = model_tune.sample(data=data, fixed_param=True, iter_sampling=1, iter_warmup=0, chains = 1)
tunes.draws_pd()


"""-----------------------Exercise 5-----------------------""" 
model_samp_st = CmdStanModel(stan_file='code_7.stan')
model_log_target = CmdStanModel(stan_file='code_8.stan')
model_log_target_ind = CmdStanModel(stan_file='code_9.stan')
data = {'N': F}
seed = 5051998 #integer, your date of birth in the DDMMYYYY format without leading zero (or if you are GPRD weary, use any other date you wish)
result_1 = model_samp_st.sample(data=data,seed=seed)
result_2 = model_log_target(data=data,seed=seed)
result_3 = model_log_target_ind(data=data,seed=seed)
az.plot_density([result_1,result_2,result_3])
plt.show()

"""-----------------------Exercise 6-----------------------""" 
model_gq = CmdStanModel(stan_file='code_10.stan')
# fill in with chosen result from previous excercise
mean_of_y = model_gq.generate_quantities(data=data,
                                        mcmc_sample = result_3 )
# investigate the output and plot histogram of mean_y variable
df_gq = mean_of_y.generated_quantities_pd

df_gq.plot.hist(bins=50)
