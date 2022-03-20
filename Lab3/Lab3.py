
from cmdstanpy import CmdStanModel
import pandas as pd
import arviz as az 
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats
import csv 

"""-----------------------Exercise 1-----------------------""" 
#1 1 sample
model1 = CmdStanModel(stan_file='stan1.stan')
resultA = model1.sample(data={'N':1, 'y':[1]}, seed = 15032022, chains = 4)
print(resultA.diagnose())

#Convertion to arviz InferenceData
arviz_resultA = az.from_cmdstanpy(posterior=resultA)

#Calculate log sigma
post = arviz_resultA.posterior
post["log_sigma"] = np.log(post["sigma"])
arviz_resultA

#Arviz plot
az.plot_pair(arviz_resultA, var_names=['mu', 'log_sigma'], divergences=True)


#2 6 samples
resultB = model1.sample(data={'N':6, 'y':[-309, -1.84, 0.48, 1.14, 2.45, 6.7]}, seed = 15032022, chains = 4)
print(resultB.diagnose())

#Convertion to arviz InferenceData
arviz_resultB = az.from_cmdstanpy(posterior=resultA)

#Calculate log sigma
post = arviz_resultB.posterior
post["log_sigma"] = np.log(post["sigma"])
arviz_resultB

#Arviz plot
az.plot_pair(arviz_resultB, var_names=['mu', 'log_sigma'], divergences=True)


"""-----------------------Exercise 2-----------------------""" 
#Data read fromm coin.csv
#y = 
#N = 

my_csv1 = pd.read_csv('coin.csv')
y = my_csv1.Experiment_Id
N = my_csv1.Toss_Result

model2 = CmdStanModel(stan_file='stan2.stan')
result2 = model2.sample(data={"N" : N, "y" : y}, seed = 15032022, chains = 4)
result2.summary()

#Convertion to arviz InferenceData
arviz_result2 = az.from_cmdstanpy(posterior=result2)
arviz_result2

az.plot_density(arviz_result2, shade=0.1)



"""-----------------------Exercise 3-----------------------""" 
#Data read fromm normal.csv
#y = 
#N = 
my_csv2 = pd.read_csv('normal.csv')
y = my_csv2(column=0)
N = my_csv2.value

#1 posterior predictive
model3A = CmdStanModel(stan_file='stan3.stan')
result3A = model3A.sample(data={'N':N, 'y':y}, seed = 9012022, chains = 4)
result3A.summary()

#Convertion to arviz InferenceData
arviz_result3A = az.from_cmdstanpy(posterior=result3A, posterior_predictive=["y_rep"], observed_data={"y": y})
arviz_result3A

#Arviz plot
az.plot_ppc(arviz_result3A,data_pairs={"y": "y_rep"})

#2 prior predictive
model3B = CmdStanModel(stan_file='stan4.stan')
result3B = model3B.sample(data={'N':100}, chains = 1,fixed_param=True,seed = 523833)
result3B.summary()

#Convertion to arviz InferenceData
arviz_result3B = az.from_cmdstanpy(prior=result3B,prior_predictive=["y_prior"],observed_data={"y": y})
arviz_result3B
az.plot_ppc(arviz_result3B, group="prior", data_pairs={"y": "y_prior"}, num_pp_samples=30)

#y_prior histogram
plt.dra.hist('y_prior')