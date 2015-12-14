#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void DrawMap();

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	Cube* floor;

	Cube Road1;
	Cube Road2;
	Cube Road3;
	Cube Road4;
	Cube Road5;
	Cube Road6;
	Cube Road7;
	Cube Road8;
	Cube Road9;
	Cube Road10;
	Cube Road11;
	Cube Road12;
	Cube Road13;
	Cube Road14;
	Cube Road15;
	Cube Road16;
	Cube Road17;
	Cube Road18;
	Cube Road19;
	Cube Road20;

	Cylinder Cylinder_1;

	Cube trailer_wall1;
	Cube trailer_wall2;
	Cube trailer_wall3;
	Cube trailer_wall4;
	
	Cube s;
	PhysBody3D* sensor;


	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
};
