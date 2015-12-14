#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 100.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void CreateSphere(int quantity, int pos);

public:

	PhysVehicle3D* front_truck;
	PhysVehicle3D* trailer;
	PhysBody3D* vehicle_sphere;
	float turn;
	float acceleration;
	float brake;
};