#include "utils/vecmat.h"

/*
 * Vector
 */

nd::Vector* nd::Vector::storage = NULL;

nd::Vector::Vector(const nd::Vector &v) : n(v.length()){
	val = new double[n];
	for (int i = 0; i < n; i++)
		val[i] = v(i);
}

nd::Vector::Vector(int n) : n(n){
	val = new double[n];
	for (int i = 0; i < n; i++)
		val[i] = 0;
}

nd::Vector::Vector(double val0, double val1, double val2) : n(3){
		val = new double[3];

		val[0] = val0;
		val[1] = val1;
		val[2] = val2;						
}

nd::Vector::~Vector(){
	delete[] val;
}

int nd::Vector::length() const{
	return n;
}

double nd::Vector::operator()(int i) const {
	return val[i];
}

double& nd::Vector::operator()(int i) {
	return val[i];
}

nd::Vector& nd::Vector::operator=(const nd::Vector &rhs){
	if (this != &rhs){
		if(n != rhs.n){
			delete[] val;

			n = rhs.n;
			val = new double[n];
		}

		for (int i = 0; i < n; i++){
			val[i] = rhs.val[i];
		}
	}

	return *this;
}

nd::Vector& nd::Vector::operator+=(const nd::Vector &rhs) {
	if (n != rhs.n){
		fprintf(stderr, "Vector dimensions conflict!\n");
	}

	for (int i = 0; i < n;i++)
		val[i] += rhs.val[i];
	
	return *this;
}

const nd::Vector nd::Vector::operator+(const nd::Vector &rhs) const{
	formStorage(*this);
	*storage += rhs;
	return *storage;
}

nd::Vector& nd::Vector::operator-=(const nd::Vector &rhs) {
	if (n != rhs.n){
		fprintf(stderr, "Vector dimensions conflict!\n");
	}

	for (int i = 0; i < n;i++)
		val[i] -= rhs.val[i];

	return *this;
}

nd::Vector nd::Vector::operator-(const nd::Vector &rhs) const{
	formStorage(n);

	*storage = *this;
	*storage -= rhs;

	return *storage;
}


nd::Vector& nd::Vector::operator*=(const double &rhs){
	for (int i = 0; i < n;i++)
		val[i] *= rhs;
	return *this;
}

const nd::Vector nd::Vector::operator*(const double &rhs) const{
	formStorage(*this);
	*storage = *this;
	*storage *= rhs;
	return *storage;
}

nd::Vector& nd::Vector::operator/=(const double &rhs){
	for (int i = 0; i < n;i++)
		val[i] /= rhs;
	return *this;
}

const nd::Vector nd::Vector::operator/(const double &rhs) const{
	formStorage(*this);
	*storage /= rhs;
	return *storage;
}


nd::Vector nd::Vector::normalize(const nd::Vector &v){
	formStorage(v);
	double norm = sqrt(v(0)*v(0) + v(1)*v(1) + v(2)*v(2));
	*storage /= norm;

	return *storage;
}

nd::Vector nd::Vector::cross(const nd::Vector &v1, const nd::Vector &v2){
	if(v1.length() != v2.length()){
		fprintf(stderr, "nd::Vector::cross : The numbers of dimensions do not match.\n");
		throw "nd::Vector::cross : The numbers of dimensions do not match";
	}

	formStorage(v1.length());

	if(v1.length() == 3){
		(*storage)(0) = v1(1)*v2(2) - v1(2)*v2(1);
		(*storage)(1) = v1(2)*v2(0) - v1(0)*v2(2);
		(*storage)(2) = v1(0)*v2(1) - v1(1)*v2(0);
	}else{
		fprintf(stderr, "nd::Vector::cross : Not implement\n");
	}

	return (*storage);
}

void nd::Vector::formStorage(int length){
	if(storage != NULL){
		if(storage->length() == length){
			return;
		}

		delete[] storage;
	}

	storage = new Vector(length);
}
void nd::Vector::formStorage(const nd::Vector &v){
	if(storage != NULL){
		if(storage->length() == v.length()){
			*storage = v;
			return;
		}

		delete[] storage;
	}

	storage = new nd::Vector(v);
}

/*
 * Quaternion
 */

nd::Quaternion::Quaternion(double v0, double v1, double v2, double v3) {
	val[0] = v0;
	val[1] = v1;
	val[2] = v2;
	val[3] = v3;
}

double nd::Quaternion::operator()(int i) const {
	return val[i];
}

double& nd::Quaternion::operator()(int i) {
	return val[i];
}

nd::Quaternion& nd::Quaternion::operator=(const nd::Quaternion &rhs){
	if (this != &rhs){
		val[0] = rhs.val[0];
		val[1] = rhs.val[1];
		val[2] = rhs.val[2];
		val[3] = rhs.val[3];
	}

	return *this;
}

nd::Quaternion& nd::Quaternion::operator*=(const nd::Quaternion &rhs) {
	double t0 = (val[0] * rhs.val[0] - val[1] * rhs.val[1] - val[2] * rhs.val[2] - val[3] * rhs.val[3]);
	double t1 = (val[0] * rhs.val[1] + val[1] * rhs.val[0] + val[2] * rhs.val[3] - val[3] * rhs.val[2]);
	double t2 = (val[0] * rhs.val[2] - val[1] * rhs.val[3] + val[2] * rhs.val[0] + val[3] * rhs.val[1]);
	double t3 = (val[0] * rhs.val[3] + val[1] * rhs.val[2] - val[2] * rhs.val[1] + val[3] * rhs.val[0]);

	val[0] = t0;
	val[1] = t1;
	val[2] = t2;
	val[3] = t3;

	return *this;
}

const nd::Quaternion nd::Quaternion::operator*(const nd::Quaternion &rhs) const{
	nd::Quaternion result = *this;
	result *= rhs;
	return result;
}	


nd::Vector nd::Quaternion::toEulerAngle() const{
	nd::Vector result(3);
	
	result(0) = atan2(2*(val[0]*val[1] + val[2]*val[3]), 1-2*(val[1]*val[1] + val[2]*val[2]));
	result(1) = asin(2*(val[0]*val[2] - val[3]*val[1]));
	result(2) = atan2(2*(val[0]*val[3] + val[1]*val[2]), 1-2*(val[2]*val[2] + val[3]*val[3]));
	
	return result;
}

nd::Quaternion nd::Quaternion::convertFromAxisRotation(double angle, double ux, double uy, double uz){
	double norm = sqrt(ux*ux + uy*uy + uz*uz);
	return Quaternion(cos(angle / 2), ux/norm*sin(angle / 2), uy/norm*sin(angle / 2), uz/norm*sin(angle / 2));
}

nd::Quaternion nd::Quaternion::convertFromEulerAngle(double ax, double ay, double az){
	return convertFromAxisRotation(az, 0, 0, 1) * (convertFromAxisRotation(ay, 0, 1, 0) * convertFromAxisRotation(ax, 1, 0, 0));
}