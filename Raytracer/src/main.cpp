#include <iostream>
#include <vector>
#include <time.h>

#include <FreeImage.h>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

#include "geometry/primitives/Ray.h"
#include "geometry/primitives/Primitive.h"
#include "geometry/primitives/Plane.h"
#include "geometry/primitives/Rectangle.h"
#include "geometry/primitives/Sphere.h"
#include "geometry/primitives/Triangle.h"
#include "geometry/Material.h"
#include "core/Light/Light.h"
#include "core/Light/PointLight.h"
#include "core/Light/DirectionalLight.h"
#include "core/Film.h"
#include "core/Camera.h"
#include "core/World.h"
#include "core/Scene.h"
#include "utils/Parser.h"
#include "utils/Direction.h"
#include "utils/Point.h"

using namespace raytracer;
using namespace std;


int main()
{
	string inputFile = "C:\\Dropbox\\Code\\Cpp\\Raytracer\\Raytracer\\res\\test_scenes\\CornellBox.test";
	World::setActiveScene(Parser::parseFile(inputFile));

	clock_t start = clock();
	World::renderActiveScene();
	cout << "\n\nRender time: " << (clock() - start) / (double) (CLOCKS_PER_SEC / 1000) << " ms\n";

	getchar();
	return 0;
}
