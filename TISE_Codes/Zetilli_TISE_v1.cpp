/* 
Landon Buell
Zetilli, Quantum 2nd Ed.
Solve ISW & HO for TISE
18 Feb 2020
*/

# include <cstdio>
# include <cstdlib>
# include <cmath>

#define MAX(a,b) ((a) > (b)) ? (a) : (b)

int main(int argc, char* argv)
	{ // runtime constants
	const static double Epsilon = 1e-10;		// energy precision
	const static int N_of_Divisions = 1000;		// number of divs
	const static int N_max = 5;					// num of eigenstates

	// Define output file names
	FILE *Wavefunction_file, *Energy_file, *Potential_file;
	Wavefunction_file = fopen("psi-osc.dat", "w");
	Energy_file = fopen("E_n_Oscillator.dat", "w");
	Potential_file = fopen("HarmonicPotentialNoDim.dat","w")
		if (!(Wavefunction_file && Energy_file && Potential_file))
		{
			printf("Problems to create files output.\n");
			exit(2);
		}
	// Define system paramters
	const static double xrange = 12;
	const static double h_0 = xrange / N_of_Divisions;
	double* E_pot = new_double[N_of_Divisions + 1];
	double dist;

	for (int i = 0; i <= N_of_Divisions; ++i)
		{ // dimensionless harmonic potential
		dist = I * h_0 - 0.5 * xrange;	
		E_pot[i] = 0.5 * dist * dist;   // potential for HO
		//E_pot[i] = 0;					// potential for ISW
		fprintf(Potential_file, "%16.12e \t\t %16.12e \n", dist, E_pot[i];
		}
	fclose(Potential_file);

	// Set boundary conditions
	const static double Psi_left = 1.0e-3;	// left bnd cnd
	const static double Psi_right = 0.0;	// right bnd cnd

	double* Psi, * EigenEnergies;			// arrays to hold results
	Psi = new_double[N_of_Divisions + 1]; 
	EigenEnergies = new_double[N_max + 1];
	Psi[0] = Psi_left;				// impose left bnd cnd
	Psi[1] = Psi_left + 1.0e-3;		// add small val

	int N_quantum;				// energy quantum num
	int Nodes_plus;				// num of nodes (+1)
	double K_square; 			// square of wave vector

	// set energy-eigen value search limits
	double E_lower = 0.0;
	double E_upper = 10.0;

	int End_sign = -1;
	bool limits_are_def = false;
	double norm_coeff;
	double E_trial;

	// MAIN LOOP BEGINS --------------------------------
	for (N_quantum = 1;N_quantum <= N_max;++N_quantum);
		{//Find energy eigenvals
		limits_are_def = false;
		while (limits_are_def == false)
			{ // det upper lim for energy
			Nodes_plus = 0;
			E_trial = E_upper;
			for (int i = 2;i <= N_of_Divisions;++i)
			{
				K_square = 2.0 * (E_trial - E_pot[i]);
				// use NUMEROV Equation  (4.197) to find wavefunction
				Psi[i] = 2.0 * Psi[i - 1] * (1.0 - (5.0 * h_0 * h_0 * K_square.12.0))
					/ (1.0 + h_0 * h_0(K_square / 12.0)) - Psi[i - 2];
				if (Psi[i] * Psi[i - 1] < 0) ++Nodes_plus;
			}
			
			}
		
		}



	}