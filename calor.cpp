#include <iostream>
#include <fstream>
#include "sparselib/sparselib/sparselib.hh"


using namespace ::std;
using namespace ::sparselib_load;
using ::sparselib::index_type ;
using ::sparselib_fun::maxval ;
using ::sparselib_fun::minval ;
using ::sparselib_fun::absval ;


//resolver A x = b, em que A é uma matriz e x e b vetores

// GLOBAL VARS
double deltaX = 0.01;
int dim = 10/deltaX - 1;


void experiencia1(){

	// ---------- DEFINIÇAO VETORES E MATRIZ ---------- //
	Vector<double> x,b; // definicao dos vetores x e b
	CCoorMatrix<double> A; // definicao da matriz A
	
	x.new_dim(dim);// vetor com dim = 9
	b.new_dim(dim);// vetor com dim = 9
	A.new_dim(dim,dim,dim*3-2); //matriz dimxdim, dim*3 -2 elementos n nulos -> diagonal principal e vizinhos left/right
		
	// insercao de valores na matriz A
	for(int i =0; i < dim; i++){
	A.insert(i,i) = double(-6-2*pow(deltaX, 2))/double(3*deltaX);
	}
	A.insert(0,1) = double(6-pow(deltaX, 2))/double(6*deltaX);
	A.insert(dim-1,dim-2) = double(6-pow(deltaX, 2))/double(6*deltaX);
	
	for(int i = 1; i < dim - 1; i++){
	A.insert(i,i+1) = double(6-pow(deltaX, 2))/double(6*deltaX);
	A.insert(i,i-1) = double(6-pow(deltaX, 2))/double(6*deltaX);
	}
	
	// insercao de valores no vetor b
	b[0] = double(pow(deltaX,2) - 6)/ double(6*deltaX);
	x=0;



	// ---------- SPARCELIB++ MAGIC ---------- //
	
	
    IdPreco<int> P;  // preconditioner, used for solver
    P.build(A); //  used for solver
    int iter, max_iter=pow(10,6); // number of iterations for iterative solver
    double epsi=pow(10,-6);  // tolerance
  	x=0;
    double res=bicgstab(A,b,x, P, epsi, max_iter, iter); //solver



	// ---------- FILES SHENANIGANS ---------- //

	// escrever a solucao numerica para ficheiro
	ofstream numSol("SolucaoNumerica.txt");
	numSol.is_open();
	double k = 0;
	for(int i = 0; i<dim; i++){
		k += deltaX;
		numSol << k << "\t" << x[i] << endl;
	}
	
	// escrever a solucao analitica para ficheiro
	ofstream anaSol("SolucaoAnalitica.txt");
	anaSol.is_open();
	double u;
	for(double x = 0; x < 10 ; x += 0.001){
		u = (exp(-x) * ( exp(20) - exp(2*x))) / (exp(20)-1);
		anaSol << x << "\t" << u << endl;
	}
	
	numSol.close();
	anaSol.close();

}


int main(){
	experiencia1();
	return 0;
}

