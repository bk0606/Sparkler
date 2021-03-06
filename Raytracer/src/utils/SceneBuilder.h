#pragma once 

#include <glm/glm.hpp>
#include <deque>
#include <stack>
#include <vector>
#include "../core/materials/SimpleMaterial.h"
#include "../core/materials/DiffuseMaterial.h"
#include "../core/Scene.h"

using namespace glm;

namespace raytracer 
{
	class SceneBuilder
	{
		Camera *camera;
		vector<Light*> lights;

		Attenuation attenuation;
		bool isAttenuationSet = false;
		stack<mat4> transformStack;
		bool isAnyTrsnform = false;
		
		string outputFile = "";
		string textureFile = "";

	public:
		vector<DisplayObject*> dObjects;

		Color bgColor;
		int recursionDepth = 3;
		int fragmentsPerPixel = 2;
		short bitsPerPixel = 24;

		Scene*			buildScene();
		void			setupCamera(int width, int heght, float fovXDeg, 
							Position lookFrom, Position lookTo, Direction up);

		void			addObject(Shape* dObject, MaterialProperties mProps);
		DisplayObject*	getObject(int index);
		void			addLight(Light* light);

		void			setOutputFile(string pathAndName);
		void			setAttenuation(float constant, float linear, float quad);
		void			setTexture(string pathAndName);


		void			addTransform(const mat4& transform);
		void			pushTransform();
		void			popTransform();

						SceneBuilder(int approxPrimitivesCnt = 20, int approxLightCnt = 5);
	};
}