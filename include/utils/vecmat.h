#ifndef _ND_DATATYPE_H_
#define _ND_DATATYPE_H_

#include <math.h>
#include <stdio.h>
#include <iostream>

namespace nd {

class Vector{
public:
	Vector(const Vector &v);
	Vector(int n);
	Vector(double val0, double val1, double val2);
	~Vector();

	int length() const;

	// access element
	double operator()(int i) const;
	double& operator()(int i);

	// mathematics operators
	Vector& operator=(const Vector &rhs);
	Vector& operator+=(const Vector &rhs);
	const Vector operator+(const Vector &rhs) const;
	Vector& operator-=(const Vector &rhs);
	Vector operator-(const Vector &rhs) const;
	Vector& operator*=(const double &rhs);
	const Vector operator*(const double &rhs) const;
	Vector& operator/=(const double &rhs);
	const Vector operator/(const double &rhs) const;

	// vector operators
	static Vector normalize(const Vector &v);
	static Vector cross(const Vector &v1, const Vector &v2);

	// print to stream
	friend std::ostream& operator << (std::ostream& os, const Vector& v){
		for(int i=0;i<v.length();i++){
			os << v(i);

			if(i < v.length()-1){
				os << " ";
			}
		}

		return os;
	}

private:
	int n; //number of dimensions
	double *val;

	static Vector* storage;
	static void formStorage(int length);
	static void formStorage(const Vector &v);

}; // end of class vector



class Quaternion {
public:
	// constructor
	Quaternion(double v0 = 0, double v1 = 0, double v2 = 0, double v3 = 0);

	// functions for conversion
	Vector toEulerAngle() const;
	static Quaternion convertFromAxisRotation(double angle, double ux, double uy, double uz);
	static Quaternion convertFromEulerAngle(double ax, double ay, double az);

	// functions for operators
	double operator()(int i) const;
	double& operator()(int i);
	inline Quaternion& operator=(const Quaternion &rhs);
	inline Quaternion& operator*=(const Quaternion &rhs);
	inline const Quaternion operator*(const Quaternion &rhs) const;	

private:
	double val[4];
}; // end of class quaternion


}

#endif
