#include <array>

struct vec3d
{
	float f1(0.0);
	float f2(0.0);
	float f3(0.0);
};

class tetraPack {
	vec3d testVector;
  public:
	tetraPack(vec3d v) {
		testVector = v;
	};
	bool contains(vec3d point) {
		if (point.f1 < 0) {
			return false;
		}
		return true;
	};
};

int main() {
	vec3d test(2.0, 1, 1);
	tetraPack tetra(test);

	std::cout << tetra.contains(test);
}