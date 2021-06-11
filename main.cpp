#include "Particle_IC_Constructor.h"

#define Newton_G  1.0
#define box_size 0
#define PI 3.14159265

Particle_IC_Constructor   constructor_Models; 
//Parameters
double Rho0          =  1.0;     // peak density [unit: M mass of sun/kpc^3]
double R0            =  1.0 ;                 // scale radius [unit: kpc]
double MaxR          =  2.0;                    // maximum radius for particles [unit: kpc]
int MassProfNBin   = 1000    ;             // number of radial bins in the mass profile table [1000]
double Alpha         =1     ;               // alpha parameter for Eiasto model [1]
int r_col         = 0         ;           // number of the column of the radius of density profile, when model is "UNKNOWN"  [0]
int rho_col        =1          ;          // number of the column of the density of density profile, when model is "UNKNOWN"  [1]
double truncation    = 0       ;             // whether to turn on a smoothy truncation function of density near MaxR [0]

int main(){

    constructor_Models.init("UNKNOWN",Alpha,Newton_G,Rho0,R0,MassProfNBin,MaxR,truncation,0.7,r_col,rho_col,"halo_profile.txt");

    //Example Code for Constructing Particle ICs (May be modified in your present code)
    const int N = 1000;
    double par_r [N];
    double par_vel[N];
    int count = 0;
    for (int p=0;p<N;p++){
        par_r[p] = constructor_Models.set_radius();
        //cout<<par_r[p]<<endl;
        par_vel[p] = constructor_Models.set_vel(par_r[p]);//par_r[p]/R0
        //cout<<par_vel[p]<<endl;
        //cout<<p<<endl;
        cout<<par_r[p]<<endl;
        if (par_r[p]>MaxR){
            
            count++;
        }
    }
    cout<<count<<endl;
}