
#include "TetraPacker.h"


Tetra::Tetra(Point p1, Point p2, Point p3, Point p4)
{
	this->norms[0] = computeNorm(p1, p2, p3);
	this->norms[1] = computeNorm(p1, p3, p4);
	this->norms[2] = computeNorm(p1, p4, p2);
	this->norms[3] = computeNorm(p2, p4, p3);

	this->references[0] = dot(p1, norms[0]);
	this->references[1] = dot(p1, norms[1]);
	this->references[2] = dot(p1, norms[2]);
	this->references[3] = dot(p2, norms[3]);

	this->refPoints[0] = p1;
	this->refPoints[1] = p2;

	this->valid = true;
}





bool Tetra::contains(Point p) {
	if (!this->valid) {
		return false;
	}
	Point p_ = subtract(p, refPoints[1]);
	double res = dot(norms[3], p_);
	if (res > 0){
		bool valid = true;
		p_ = subtract(p, refPoints[0]);
		for (int i = 0; i < 3; i++) {
			valid &= (dot(norms[i], p) >= 0);
		}
		if (valid) {
			return true;
		}
	}
	return false;
}

TetraPacker::TetraPacker(Point edges[]) 
{
	Point start = edges[0];
	Point end = edges[7];
	Point last = edges[5];
	for (int i = 0; i < 6; i++) {
		Point next = edges[this->edgeOrder[i]];
		this->tetras[i] = Tetra({ start, end, last, next });
		last = next;
	}
}

bool TetraPacker::contains(Point p)
{
	for (int i = 0; i < 6; i++) {
		Tetra tetra = this->tetras[i];
		if (tetra.contains(p)) {
			return true;
		}
	}
	return false;
}
