// Give a coordinate in world coordinate system.
// As we kown, we can easly transform the point coordinate from WCS to CMCS by the external parameters,
// then transform it to ICS by internal parameters.
// INPUT:
// homogenous coordinate in WCS : (X, Y, Z, 1)
// internal parameters : f_x, f_y, x_0, y_0.
// external parameters : sita_x, sita_y, sita_z, t_x, t_y, t_z.
// OUTPUT:
// homogenous coordinate in ICS : (u, v, 1)
// For exercise, we just use standard lib, like the people living in middle ages.
// BTW,it has been long time since i last used C++ and i need to review it all
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef  vector <vector<double>  >  matrix;

//need to input the data
double X = 1, Y = 1, Z = 2;
double f_x = 0.05, f_y = 0.05, x_0 = 0.5, y_0 = 0.3;
double sita_x = 0, sita_y = 0, sita_z = 0, t_x = 100, t_y = 0, t_z = 0;

// no need
matrix add_mat (matrix m1, matrix m2)
{
	int m1_row = m1.size ();
	int m1_col = m1[0].size ();
	int m2_row = m2.size ();
	int m2_col = m2[0].size ();
	matrix m3 ( m1_row, vector<double> ( m1_col, 0 ) );
	if ( m1_row != m2_row || m1_col != m2_col )
	{
		cout << "Can't add because of format!" << endl;
		exit (1);
	}
	else
	{
		for ( int i = 0; i < m1_row; i++ )
			for ( int j = 0; j < m1_col; j++ )
				m3[i][j] = m1[i][j] + m2[i][j];
	}
	return m3;
}

// no need
matrix scalar_mat ( double k, matrix m )
{
	for ( int i = 0; i < m.size (); i++ )
		for ( int j = 0; j < m[0].size (); j++ )
			m[i][j] = k * m[i][j];
	return m;
}

matrix mult_mat ( matrix m1, matrix m2 )
{
	int m1_row = m1.size();
	int m1_col = m1[0].size();
	int m2_row = m2.size();
	int m2_col = m2[0].size();
	matrix m3 ( m1_row, vector<double> ( m2_col, 0 ) );

	if ( m1_col != m2_row )
	{
		cout << "Can't multiply because of format!" << endl;
		exit (1);
	}
	else
	{
		for ( int i = 0; i < m1_row; i++ )
			for ( int j = 0; j < m2_col; j++ )
				for ( int k = 0; k < m1_col; k++ )
					m3[i][j] += m1[i][k] * m2[k][j];
	}
	return m3;
}

matrix internal_matrix ()
{
	matrix IPM ( 3, vector<double> ( 4, 0 ) );
	IPM[0][0] = f_x;
	IPM[1][1] = f_y;
	IPM[0][2] = x_0;
	IPM[1][2] = y_0;
	IPM[2][2] = 1;
	return IPM;
}

matrix external_matrix ()
{
	matrix R_x = {
		{1,			0,			0,  		 0 },
		{0, cos ( sita_x ), -sin ( sita_x ), 0 },
		{0, sin ( sita_x ),  cos ( sita_x ), 0 },
		{0,			0,			0,  		 1 }
	};
	matrix R_y = {
		{cos ( sita_y ), 0, -sin ( sita_y ), 0 },
		{0,			1,			0,  		 0 },
		{sin ( sita_y ), 0,  cos ( sita_y ), 0 },
		{0,			0,			0,  		 1 }
	};
	matrix R_z = {
		{cos ( sita_z ), -sin ( sita_z ), 0, 0 },
		{sin ( sita_z ),  cos ( sita_z ), 0, 0 },
		{0,			0,			1,  		 0 },
		{0,			0,			0,  		 1 }
	};
	matrix EPM ( R_x.size () , vector<double> ( R_x.size(), 0 ) );
	EPM = mult_mat ( R_z, ( mult_mat ( R_y, R_x) ) );
	EPM[0][3] = t_x;
	EPM[1][3] = t_y;
	EPM[2][3] = t_z;
	return EPM;
}

int main ()
{
	//need to input the data
	matrix p_wcs = {
		{X},
		{Y},
		{Z},
		{1}
	};

	matrix epm = external_matrix ();
	matrix ipm = internal_matrix ();
	matrix p_ims = mult_mat (mult_mat ( ipm, epm ), p_wcs);
	p_ims = scalar_mat ( 1 / Z, p_ims);
	cout << p_ims[0][0] << endl;
	cout << p_ims[1][0] << endl;
	cout << p_ims[2][0] << endl;
	return 0;
}
