This repository is for the analysis of stochastic resetting.

Files:

1. 'reset.C': This simulates the trajectory of overdamped brownian motion under stochastic resetting with constant resetting rate. Trajectory gets saved as 'reset.dat'.

2. 'avgres.C': It generates 3 files.
	a) <x(t)> calculated over 1000 trajectories and saved in 'mean.dat'.
	b) <x(t)^2> calculated over 1000 trajectories and saved in 'avg2.dat'.
	c) stores {x(t)} when motion becomes stationary in 'stdist.dat'.


