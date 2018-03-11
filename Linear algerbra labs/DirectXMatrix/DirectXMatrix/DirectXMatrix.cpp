

#include <d3dx9.h>
#include <iostream>
using namespace std;


void Menu()
{   
	cout<<"==================DirectX Math Library==================="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=            Linear Algebra: Matrices Algebra           ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=            This is a small program to get you         ="<<endl;
	cout<<"=            used to DirectX Matrix Math Library        ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"========================================================="<<endl;
    cout<<"\n\n";
}


// Overload the  "<<" operators so that we can use cout to 
// output D3DXVECTOR3 and D3DXMATRIX objects.

ostream& operator<<(ostream& os, D3DXVECTOR4& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ","<<v.w<<")";
	return os;
}

ostream& operator<<(ostream& os, D3DXMATRIX& m)
{
	for(int i = 0; i <4; ++i)
	{
		for(int j = 0; j <4; ++j)
			os <<"\t"<< m(i, j) << "  ";
		os << endl;
	}
	return os;
}


int main()
{
	Menu();


	/* DirectX uses matrices of order 4X4
	 so a 3X3 matrix H=(  2  3  4  
	                      0  5  7
						 1  7  9)
	  wiil be defined in DirectX by calling the constructor D3DXMATRIX() in the following way:
	   
	   H=D3DXMATRIX(2.0F,3.0F,4.0F,0.0F,
		            0.0F,5.0F,7.0F,0.0F,
				    1.0F,7.0F,9.0F,0.0F,
				    0.0F,0.0F,0.0F,1.0F);

   */

	D3DXMATRIX I;      
	 D3DXMatrixIdentity(&I);
		            
	// create the identity matrix I using D3DXMatrixIdentity()

	// define 2 matrices A and B  of type D3DXMATRIX
     D3DXMATRIX A, B, C,D,M,S;

	// create a matrix A with entry values: 1,2,3,
	//                                      2,0,5
	//										1,1,3
A =  D3DXMATRIX(1.0F, 2.0F, 3.0F, 0.0F,
				 2.0F, 0.0F, 5.0F, 0.0F,
				 1.0F, 1.0F, 3.0F, 0.0F,
				 0.0F, 0.0F, 0.0F, 1.0F);
	
     
	  

	// create a matrix B with entry values: 2,3,1,
	//                                      5,1,2
	//										1,0,-3
    
B = D3DXMATRIX(2.0f, 3.0f, 1.0f, 0.0f, 
			   5.0f, 1.0f, 2.0f, 0.0f,
			   1.0f, 0.0f, -3.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);

	// add A and B ; S=A+B;
S = A + B;

	// Subtract A and B : D=A-B
D = A - B;
     
	 // Multiply A and B: M=A*B
M = A*B;
   

	 // Find the transpose of A that is transpose_A using D3DXMatrixTranspose();

	    D3DXMATRIX transpose_A ;
		D3DXMatrixTranspose(&transpose_A, &A);
	 // find the determinant of A that is det, using D3DXMatrixDeterminant().
		float det=0;
		det = D3DXMatrixDeterminant(&A);
	 D3DXMATRIX InvA;
	 // Compute the inverse of A that is InvA, 
	D3DXMatrixInverse(&InvA, &det, &A);

	 D3DXVECTOR4  V,P;
	 V=D3DXVECTOR4(1,2,3,1);
	 // Compute the image of the vector V(1,2,3,1) by the matrix A, that  is P=A*V
	 D3DXVec4Transform(&P, &V, &transpose_A);

	cout << "I = "               << endl << I << endl;
	cout << "A = "               << endl << A << endl;
	cout << "B = "               << endl << B << endl;
	cout << "A+B = "             << endl <<S << endl;
	cout << "A-B = "             << endl << D << endl;
	cout << "A*B = "             << endl << M << endl;
	cout << "Transpose(A)= "     << endl << transpose_A << endl;
	cout << "Determinant of A  :"<< endl <<det <<endl;
	cout << "Inverse of A  is "  << endl << InvA << endl;
    cout << "P=A*V	  is       " << P<<endl;


	getchar();
	
	return 0;
}
