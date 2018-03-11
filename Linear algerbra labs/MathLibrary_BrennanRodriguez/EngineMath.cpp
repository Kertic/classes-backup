/**
* @file EngineMath.cpp
*
*/

#include "EngineMath.h"

//////////////////////////////////////////////////////////////////////////
// Common math functions
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// General Utility functions
//////////////////////////////////////////////////////////////////////////

// Are two floating point numbers equal to each other
// Floating Point Error Safe
//
// IN:		a		The first number
//			b		The second number
//
// RETURN: TRUE iff |a-b| < Tolerance
//
// NOTE:	EPSILON is tolerance
bool IsEqual(float a, float b)
{
	// NOTE: Do not modify.
	return fabs(a - b) < EPSILON;
}

// Is a floating point value equal to zero
// Floating Point Error Safe
//
// IN:		a		The number to check
//
// RETURN:	TRUE iff |a| < Tolerance
//
// NOTE:	Tolerance set by EPSILON
bool IsZero(float a)
{
	// NOTE: Do not modify
	return (fabs(a)) < EPSILON;
}

// RETURN: MAX of two numbers
float Max(float a, float b)
{
	// NOTE: Do not modify.
	return (a > b) ? a : b;
}

// RETURN: MIN of two numbers
float Min(float a, float b)
{
	// NOTE: Do not modify.
	return (a < b) ? a : b;
}

// RETURN: Converts input to radian measure
float Degrees_To_Radians(float Deg)
{
	// NOTE: Do not modify.
	return Deg * PI / 180.0f;
}

// RETURN: Converts input to degree measure
float Radians_To_Degrees(float Rad)
{
	// NOTE: Do not modify.
	return Rad * 180.0f / PI;
}
////////////////////////////////////////////////////////////////////////
// Linear Algebra Functions Day 1
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Vector Functions
//////////////////////////////////////////////////////////////////////////

// Check if two TVECTOR's are equal to each other
//
// IN:		v		First Vector
//			w		Second Vector
//
// RETURN:  True if v==w, False otherwise
//
// NOTE:	Use's all four components
//			Should be floating point error safe.
bool Vector_IsEqual(TVECTOR v, TVECTOR w)
{

	if (IsEqual(v.x, w.x))
	{
		if (IsEqual(v.y, w.y))
		{
			if (IsEqual(v.z, w.z))
			{
				if (IsEqual(v.w, w.w))
				{
					return true;
				}
			}
		}
	}


	return false;
}

// ADD two TVECTOR's togother
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v + w
//
// NOTE:	Use's all four components
TVECTOR Vector_Add(TVECTOR v, TVECTOR w)
{
	v.x = v.x + w.x;
	v.y = v.y + w.y;
	v.z = v.z + w.z;
	v.w = v.w + w.w;


	return v;
}

// SUBTRACT one TVECTOR from another
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v - w
//
// NOTE:	Use's all four components
TVECTOR Vector_Sub(TVECTOR v, TVECTOR w)
{
	v.x = v.x - w.x;
	v.y = v.y - w.y;
	v.z = v.z - w.z;
	v.w = v.w - w.w;
	return v;
}

// MULTIPLY all four components of a TVECTOR by a scalar
//
// IN:		v		The vector to scale
//			s		The value to scale by
//
// RETURN:  s * v
TVECTOR Vector_Scalar_Multiply(TVECTOR v, float s)
{
	v.x = v.x * s;
	v.y = v.y * s;
	v.z = v.z * s;
	v.w = v.w * s;
	return v;
}

// NEGATE all the components of a TVECTOR
//
// IN:		v		The vector to negate
//
// RETURN:	-1 * v
//
// NOTE:	Use's all four components
TVECTOR Vector_Negate(TVECTOR v)
{
	v.x = v.x * -1;
	v.y = v.y * -1;
	v.z = v.z * -1;
	v.w = v.w * -1;
	return v;
}

// Perform a Dot Product on two TVECTOR's
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v (DOT) w
//
// NOTE:	Use's all four components
float Vector_Dot(TVECTOR v, TVECTOR w)
{
	float total = 0.0f;
	total += (v.x * w.x);
	total += (v.y * w.y);
	total += (v.z * w.z);
	total += (v.w * w.w);

	// TODO LAB 1: Replace with your implementation.
	return total;
}

// Perform a Cross Product on two TVECTOR's
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v (CROSS) w
//
// NOTE:	The w-component of each vector is not used.
//			The resultant vector will have a w-component of zero.
TVECTOR Vector_Cross(TVECTOR v, TVECTOR w)
{
	TVECTOR ans = { (v.y * w.z - v.z * w.y), -(v.x * w.z - v.z * w.x), (v.x * w.y - v.y * w.x), 0 };

	// TODO LAB 1: Replace with your implementation.
	return ans;
}

// Find the squared length of a TVECTOR
//
// IN:		v		The vector to find the squared length of
//
// RETURN:	Squared Length of TVECTOR
//
// NOTE:	Use's all four components
float Vector_LengthSq(TVECTOR v)
{
	float ans = (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w);
	// TODO LAB 1: Replace with your implementation.
	return ans;
}

// Find the length of a TVECTOR
//
// IN:		v		The vector to find the length of
//
// RETURN:	Length of TVECTOR
//
// NOTE:	Use's all four components
float Vector_Length(TVECTOR v)
{
	float ans = sqrt(Vector_LengthSq(v));
	// TODO LAB 1: Replace with your implementation.
	return ans;
}

// Normalize a TVECTOR
//
// IN:		v		The vector to normalize
//
// RETURN:	Normalized version of v
//
// NOTE:	Use's all four components
TVECTOR Vector_Normalize(TVECTOR v)
{
	float Length = Vector_Length(v);

	TVECTOR ans = { (v.x / Length), (v.y / Length), (v.z / Length), (v.w / Length) };
	// TODO LAB 1: Replace with your implementation.
	return ans;
}

// Makes a TVECTOR's w-component normalized
//
// IN:		v		The vector (point object) to homogenise
//
// RETURN:	The homogenised vector (point)
//
// NOTE:	If the w-component of the vector is 0 then the
//			function will return a zero vector with a w-component
//			of 0.
TVECTOR Vector_Homogenise(TVECTOR v)
{
	if (v.w == 0)
		return{ 0,0,0,0 };
	else
	{
		return{ v.x / v.w, v.y / v.w, v.z / v.w, v.w / v.w };
	}
	// TODO LAB 1: Replace with your implementation.
	return v;//If we return this, we messed up real bads

}

// Get a TVECTOR made from the maximun components of two TVECTORs
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:	A maximized vector
//
// NOTE:	Use's all four components
TVECTOR Vector_Maximize(TVECTOR v, TVECTOR w)
{
	float _x, _y, _z, _w;

	if (v.x > w.x)
		_x = v.x;
	else
		_x = w.x;

	if (v.y > w.y)
		_y = v.y;
	else
		_y = w.y;

	if (v.z > w.z)
		_z = v.z;
	else
		_z = w.z;

	if (v.w > w.w)
		_w = v.w;
	else
		_w = w.w;

	TVECTOR ans = { _x,_y,_z,_w };

	return ans;
	// TODO LAB 1: Replace with your implementation.

}

// Get a TVECTOR made from the minimum components of two TVECTOR's
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:	A minimum vector
//
// NOTE:	Use's all four components
TVECTOR Vector_Minimize(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	float _x, _y, _z, _w = 0;

	if (v.x < w.x)
		_x = v.x;
	else
		_x = w.x;

	if (v.y < w.y)
		_y = v.y;
	else
		_y = w.y;

	if (v.z < w.z)
		_z = v.z;
	else
		_z = w.z;

	if (v.w < w.w)
		_w = v.w;
	else
		_w = w.w;

	TVECTOR R = { _x,_y,_z,_w };

	return R;
	return v;
}

// Get a TVECTOR made from the average of two TVECTORs
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:	A vector made from the average of two vectors
//
// NOTE:	Use's all four components

TVECTOR Vector_Average(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	float _x = (v.x + w.x) / 2;
	float _y = (v.y + w.y) / 2;
	float _z = (v.z + w.z) / 2;
	float _w = (v.w + w.w) / 2;

	TVECTOR ans = { _x,_y,_z,_w };

	return ans;
	return v;
}

// Find the angle between two TVECTORs
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:  The angle in degrees between the two vectors
//
// NOTE:	If either vector is a zero vector then the return
//			value will be 0.
float Vector_AngleBetween(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	if ((v.x == 0 && v.y == 0 && v.z == 0 && v.w == 0) || (w.x == 0 && w.y == 0 && w.z == 0 && w.w == 0))
		return 0;
	else
	{
		float _d = v.x * w.x + v.y * w.y + v.z * w.z + v.w * w.w;
		float _l = sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w) * sqrt(w.x * w.x + w.y * w.y + w.z * w.z + w.w * w.w);

		float _angle = acos(_d / _l);
		_angle = Radians_To_Degrees(_angle);
		return _angle;
	}
	return 0;
}

// Get the distance one TVECTOR points in the direction of another
// TVECTOR
//
// IN:		v		The first vector
//			w		The direction of the component
//
// RETURN:	The distance that v points in the direction of w.
//
// NOTE:	If w or v is a zero vector then the return value is zero.
float Vector_Component(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.

	if ((v.x == 0 && v.y == 0 && v.z == 0 && v.w == 0) || (w.x == 0 && w.y == 0 && w.z == 0 && w.w == 0))
		return 0;
	else
	{
		float _distance = Vector_Dot(v, Vector_Normalize(w));
		return _distance;
	}
	return 0;
}

// Get the TVECTOR that represents v projected on w.
//
// IN:		v		The first vector
//			w		The direction of the projection
//
// RETURN:	The projection of v onto w
//
// NOTE:	If w or v is a zero vector then the return value is zero.
TVECTOR Vector_Project(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	if ((v.x == 0 && v.y == 0 && v.z == 0 && v.w == 0) || (w.x == 0 && w.y == 0 && w.z == 0 && w.w == 0))
		return{ 0,0,0,0 };
	else
	{
		TVECTOR _normal = Vector_Normalize(w);
		float _component = Vector_Component(v, w);

		TVECTOR _Projection = { _normal.x * _component, _normal.y * _component, _normal.z * _component, _normal.w * _component };

		return _Projection;
	}
	return v;//Dis be bad if do
}

////////////////////////////////////////////////////////////////////////
// Functions Lab  #2
///////////////////////////////////////////////////////////////////////


// Get the reflection of v across w
//
// IN:		v		The vector to reflect
//			w		The "axis" to reflect across
//
// RETURN:	v reflected across w
//
// NOTE:	If w is a zero vector then return -v.
TVECTOR Vector_Reflect(TVECTOR v, TVECTOR w)
{
	// TODO LAB 2: Replace with your implementation.
	if (w.x == 0 && w.y == 0 && w.z == 0 && w.w == 0)
		return{ v.x * -1, v.y * -1, v.z * -1, v.w * -1 };


	float temp = Vector_Dot(v, Vector_Normalize(w));
	temp = 2 * temp;
	TVECTOR _normalized = Vector_Normalize(w);
	TVECTOR _reflected = { temp * _normalized.x, temp * _normalized.y, temp * _normalized.z, temp * _normalized.w };
	_reflected = Vector_Sub(_reflected, v);


	return _reflected;
	return v;
}

//////////////////////////////////////////////////////////////////////////
// Matrix Functions
//////////////////////////////////////////////////////////////////////////

// Get a [0] matrix
//
// RETURN: A 0 4x4 matrix
TMATRIX Matrix_Zero(void)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 0,0,0,0,
				0,0,0,0,
				0,0,0,0,
				0,0,0,0 };

	return m;
}

// Get a [I] matrix
//
// RETURN: A 4x4 Identity matrix
TMATRIX Matrix_Identity(void)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 1, 0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1 };
	return m;
}

// Get a translation matrix
//
// IN:		x		Amount of translation in the x direction
//			y		Amount of translation in the y direction
//			z		Amount of translation in the z direction
//
// RETURN:	The translation matrix
TMATRIX Matrix_Create_Translation(float x, float y, float z)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 1, 0,0,x,
				0,1,0,y,
				0,0,1,z,
				0,0,0,1 };
	return m;
}

// Create a scale matrix
//
// IN:		x		Amount to scale in the x direction
//			y		Amount to scale in the y direction
//			z		Amount to scale in the z direction
//
// RETURN:	The scale matrix
TMATRIX Matrix_Create_Scale(float x, float y, float z)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { x, 0, 0, 0,
				0, y, 0, 0,
				0, 0, z, 0,
				0, 0, 0, 1 };
	return m;
}

// Get a rotation matrix for rotation about the x-axis
//
// IN:		Deg		Angle to rotate ( Degree measure)
//
// RETURN:	A X-Rotation Matrix
TMATRIX Matrix_Create_Rotation_X(float Deg)
{
	// TODO LAB 2: Replace with your implementation.
	float _angle = Degrees_To_Radians(Deg);
	TMATRIX m = { 1, 0, 0, 0,
			0, cos(_angle), -sin(_angle), 0,
			0, sin(_angle), cos(_angle), 0,
			0, 0, 0, 1 };
	return m;
}

// Get a rotation matrix for rotation about the y-axis
//
// IN:		Deg		Angle to rotate ( Degree measure)
//
// RETURN:	A Y-Rotation Matrix
TMATRIX Matrix_Create_Rotation_Y(float Deg)
{
	// TODO LAB 2: Replace with your implementation.

	float _angle = Degrees_To_Radians(Deg);
	TMATRIX m = { cos(_angle), 0, sin(_angle), 0,
				0, 1, 0, 0,
				-sin(_angle), 0, cos(_angle), 0,
				0, 0, 0, 1 };
	return m;
}

// Get a rotation matrix for rotation about the z-axis
//
// IN:		Deg		Angle to rotate ( Degree measure)
//
// RETURN:	A Z-Rotation Matrix
TMATRIX Matrix_Create_Rotation_Z(float Deg)
{
	float _angle = Degrees_To_Radians(Deg);
	// TODO LAB 2: Replace with your implementation.

	TMATRIX m = { cos(_angle), -sin(_angle), 0, 0,
				sin(_angle), cos(_angle), 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1 };
	return m;
}

// ADD two matrices together
//
// IN:		m		The first matrix
//			n		The second matrix
//
// RETURN: m + n
TMATRIX Matrix_Matrix_Add(TMATRIX m, TMATRIX n)
{

	TMATRIX ans = { (m._e11 + n._e11), (m._e12 + n._e12), (m._e13 + n._e13), (m._e14 + n._e14),
		(m._e21 + n._e21), (m._e22 + n._e22), (m._e23 + n._e23), (m._e24 + n._e24),
		(m._e31 + n._e31), (m._e32 + n._e32), (m._e33 + n._e33), (m._e34 + n._e34),
		(m._e41 + n._e41), (m._e42 + n._e42), (m._e43 + n._e43), (m._e44 + n._e44) };
	// TODO LAB 2: Replace with your implementation.
	return ans;
}

// SUBTRACT two matrices
//
// IN:		m		The first matrix (left hand side)
//			n		The second matrix (right hand side)
//
// RETURN: m - n
TMATRIX Matrix_Matrix_Sub(TMATRIX m, TMATRIX n)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX ans = { m._e11 - n._e11, m._e12 - n._e12, m._e13 - n._e13, m._e14 - n._e14,
		m._e21 - n._e21, m._e22 - n._e22, m._e23 - n._e23, m._e24 - n._e24,
		m._e31 - n._e31, m._e32 - n._e32, m._e33 - n._e33, m._e34 - n._e34,
		m._e41 - n._e41, m._e42 - n._e42, m._e43 - n._e43, m._e44 - n._e44 };
	return ans;
}

// Multiply a matrix by a scalar
//
// IN:		m		The matrix to be scaled (right hand side)
//			s		The value to scale by   (left hand side)
//
// RETURN:	The matrix formed by s*[m]
TMATRIX Matrix_Scalar_Multiply(TMATRIX m, float s)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX ans = { s * m._e11, s * m._e12, s * m._e13, s * m._e14,
					s * m._e21, s * m._e22, s * m._e23, s * m._e24,
					s * m._e31, s * m._e32, s * m._e33, s * m._e34,
					s * m._e41, s * m._e42, s * m._e43, s * m._e44 };
	return ans;
}

// Negate a matrix
//
// IN:		m		The matrix to negate
//
// RETURN:  The negation of m
TMATRIX Matrix_Negate(TMATRIX m)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX ans = { -1 * m._e11, -1 * m._e12, -1 * m._e13, -1 * m._e14,
		-1 * m._e21, -1 * m._e22, -1 * m._e23, -1 * m._e24,
		-1 * m._e31, -1 * m._e32, -1 * m._e33, -1 * m._e34,
		-1 * m._e41, -1 * m._e42, -1 * m._e43, -1 * m._e44 };
	return ans;
}

// Transpose a matrix
//
// IN:		m		The matrix to transpose
//
// RETURN:	The transpose of m
TMATRIX Matrix_Transpose(TMATRIX m)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX ans = { m._e11, m._e21, m._e31, m._e41,
		m._e12, m._e22, m._e32, m._e42,
		m._e13, m._e23, m._e33, m._e43,
		m._e14, m._e24, m._e34, m._e44 };

	return ans;
}

// Multipy a matrix and a vector
//
// IN:		m		The matrix (left hand side)
//			v		The vector (right hand side)
//
// RETURN:	[m]*v
TVECTOR Matrix_Vector_Multiply(TMATRIX m, TVECTOR v)
{
	// TODO LAB 2: Replace with your implementation.

	TVECTOR ans = { (v.x * m._e11 + v.y * m._e12 + v.z * m._e13 + v.w * m._e14),
		(v.x * m._e21 + v.y * m._e22 + v.z * m._e23 + v.w * m._e24),
		(v.x * m._e31 + v.y * m._e32 + v.z * m._e33 + v.w * m._e34),
		(v.x * m._e41 + v.y * m._e42 + v.z * m._e43 + v.w * m._e44) };

	return ans;
}

// Multipy a vector and a matrix
//
// IN:		v		The vector ( left hand side)
//			m		The matrix (right hand side)
//
// RETURN:	v*[m]
TVECTOR Vector_Matrix_Multiply(TVECTOR v, TMATRIX m)
{
	TVECTOR ans = { (v.x * m._e11 + v.y * m._e21 + v.z * m._e31 + v.w * m._e41), 
		(v.x * m._e12 + v.y * m._e22 + v.z * m._e32 + v.w * m._e42),
		(v.x * m._e13 + v.y * m._e23 + v.z * m._e33 + v.w * m._e43),
		(v.x * m._e14 + v.y * m._e24 + v.z * m._e34 + v.w * m._e44) };

	// TODO LAB 2: Replace with your implementation.
	return ans;
}
// Multiply a matrix by a matrix
//
// IN:		m		First Matrix (left hand side)
//			n		Second Matrix (right hand side)
//
// RETURN:	[m]*[n]
TMATRIX Matrix_Matrix_Multiply(TMATRIX m, TMATRIX n)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX ans = { (m._e11 * n._e11 + m._e12 * n._e21 + m._e13 * n._e31 + m._e14 * n._e41), (m._e11 * n._e12 + m._e12 * n._e22 + m._e13 * n._e32 + m._e14 * n._e42), (m._e11 * n._e13 + m._e12 * n._e23 + m._e13 * n._e33 + m._e14 * n._e43), (m._e11 * n._e14 + m._e12 * n._e24 + m._e13 * n._e34 + m._e14 * n._e44),
		(m._e21 * n._e11 + m._e22 * n._e21 + m._e23 * n._e31 + m._e24 * n._e41), (m._e21 * n._e12 + m._e22 * n._e22 + m._e23 * n._e32 + m._e24 * n._e42), (m._e21 * n._e13 + m._e22 * n._e23 + m._e23 * n._e33 + m._e24 * n._e43), (m._e21 * n._e14 + m._e22 * n._e24 + m._e23 * n._e34 + m._e24 * n._e44),
		(m._e31 * n._e11 + m._e32 * n._e21 + m._e33 * n._e31 + m._e34 * n._e41), (m._e31 * n._e12 + m._e32 * n._e22 + m._e33 * n._e32 + m._e34 * n._e42), (m._e31 * n._e13 + m._e32 * n._e23 + m._e33 * n._e33 + m._e34 * n._e43), (m._e31 * n._e14 + m._e32 * n._e24 + m._e33 * n._e34 + m._e34 * n._e44),
		(m._e41 * n._e11 + m._e42 * n._e21 + m._e43 * n._e31 + m._e44 * n._e41), (m._e41 * n._e12 + m._e42 * n._e22 + m._e43 * n._e32 + m._e44 * n._e42), (m._e41 * n._e13 + m._e42 * n._e23 + m._e43 * n._e33 + m._e44 * n._e43), (m._e41 * n._e14 + m._e42 * n._e24 + m._e43 * n._e34 + m._e44 * n._e44) };
	return ans;
}

////////////////////////////////////////////////////////////////////////
// Matrix Functions Lab # 3
///////////////////////////////////////////////////////////////////////

// HELPER FUNCTION  *** NOT GRADED, ONLY SUGGESTED ***
// USE THIS FUNCTION TO FIND THE DETERMINANT OF A 3*3
// MATRIX. IT CAN BE USED IN THE MATRIX DETERMINANT
// AND MATRIX INVERSE FUNCTIONS BELOW
// 
// RETURN:	The determinant of a 3x3 matrix
float Matrix_Determinant(float e_11, float e_12, float e_13,
	float e_21, float e_22, float e_23,
	float e_31, float e_32, float e_33)
{
	float determinant = e_11 * (e_22 * e_33 - e_32 * e_23) - e_12 * (e_21 * e_33 - e_31 * e_23) + e_13 * (e_21 * e_32 - e_31 * e_22);
	return determinant;
}

// Get the determinant of a matrix
//
// IN:		m		The ONE!
//
// RETURN:	It's deterinant
float Matrix_Determinant(TMATRIX m)
{
	float _first = m._e14 * Matrix_Determinant(m._e21, m._e22, m._e23, m._e31, m._e32, m._e33, m._e41, m._e42, m._e43);
	float _second = m._e24 * Matrix_Determinant(m._e11, m._e12, m._e13, m._e31, m._e32, m._e33, m._e41, m._e42, m._e43);
	float _third = m._e34 * Matrix_Determinant(m._e11, m._e12, m._e13, m._e21, m._e22, m._e23, m._e41, m._e42, m._e43);
	float _fourth = m._e44 * Matrix_Determinant(m._e11, m._e12, m._e13, m._e21, m._e22, m._e23, m._e31, m._e32, m._e33);

	float ans = -_first + _second - _third + _fourth;
	// TODO LAB 3: Replace with your implementation.
	return ans;
}

// Get the inverse of a matrix
//
// IN:		m		The matrix to inverse
//
// RETURN:	The Inverse of [m]
//
// NOTE: Returns the matrix itself if m is not invertable.
TMATRIX Matrix_Inverse(TMATRIX m)
{
	float det = Matrix_Determinant(m);

	if (det == 0)
		return m;

	float pos11 = Matrix_Determinant(m._e22, m._e23, m._e24, m._e32, m._e33, m._e34, m._e42, m._e43, m._e44);
	float pos12 = -1 * Matrix_Determinant(m._e21, m._e23, m._e24, m._e31, m._e33, m._e34, m._e41, m._e43, m._e44);
	float pos13 = Matrix_Determinant(m._e21, m._e22, m._e24, m._e31, m._e32, m._e34, m._e41, m._e42, m._e44);
	float pos14 = -1 * Matrix_Determinant(m._e21, m._e22, m._e23, m._e31, m._e32, m._e33, m._e41, m._e42, m._e43);

	float pos21 = -1 * Matrix_Determinant(m._e12, m._e13, m._e14, m._e32, m._e33, m._e34, m._e42, m._e43, m._e44);
	float pos22 = Matrix_Determinant(m._e11, m._e13, m._e14, m._e31, m._e33, m._e34, m._e41, m._e43, m._e44);
	float pos23 = -1 * Matrix_Determinant(m._e11, m._e12, m._e14, m._e31, m._e32, m._e34, m._e41, m._e42, m._e44);
	float pos24 = Matrix_Determinant(m._e11, m._e12, m._e13, m._e31, m._e32, m._e33, m._e41, m._e42, m._e43);

	float pos31 = Matrix_Determinant(m._e12, m._e13, m._e14, m._e22, m._e23, m._e24, m._e42, m._e43, m._e44);
	float pos32 = -1 * Matrix_Determinant(m._e11, m._e13, m._e14, m._e21, m._e23, m._e24, m._e41, m._e43, m._e44);
	float pos33 = Matrix_Determinant(m._e11, m._e12, m._e14, m._e21, m._e22, m._e24, m._e41, m._e42, m._e44);
	float pos34 = -1 * Matrix_Determinant(m._e11, m._e12, m._e13, m._e21, m._e22, m._e23, m._e41, m._e42, m._e43);

	float pos41 = -1 * Matrix_Determinant(m._e12, m._e13, m._e14, m._e22, m._e23, m._e24, m._e32, m._e33, m._e34);
	float pos42 = Matrix_Determinant(m._e11, m._e13, m._e14, m._e21, m._e23, m._e24, m._e31, m._e33, m._e34);
	float pos43 = -1 * Matrix_Determinant(m._e11, m._e12, m._e14, m._e21, m._e22, m._e24, m._e31, m._e32, m._e34);
	float pos44 = Matrix_Determinant(m._e11, m._e12, m._e13, m._e21, m._e22, m._e23, m._e31, m._e32, m._e33);

	TMATRIX toTranspose = { pos11 / det, pos12 / det, pos13 / det, pos14 / det, pos21 / det, pos22 / det, pos23 / det, pos24 / det, pos31 / det, pos32 / det, pos33 / det, pos34 / det, pos41 / det, pos42 / det, pos43 / det, pos44 / det };
	TMATRIX postTranspose = Matrix_Transpose(toTranspose);
	// TODO LAB 3: Replace with your implementation.
	return postTranspose;
}

