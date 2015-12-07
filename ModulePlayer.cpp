#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), front_truck(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo front_car;
	VehicleInfo trailer_car;

	// Car properties ----------------------------------------
	front_car.chassis_size.Set(3, 2, 2);
	front_car.chassis_offset.Set(0, 1.5, 0);
	front_car.mass = 500.0f;
	front_car.suspensionStiffness = 15.88f;
	front_car.suspensionCompression = 0.83f;
	front_car.suspensionDamping = 0.88f;
	front_car.maxSuspensionTravelCm = 1000.0f;
	front_car.frictionSlip = 50.5;
	front_car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = front_car.chassis_size.x*0.5f;
	float half_length = front_car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	front_car.num_wheels = 2;
	front_car.wheels = new Wheel[2];

	// FRONT-LEFT ------------------------
	front_car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius-0.5);
	front_car.wheels[0].direction = direction;
	front_car.wheels[0].axis = axis;
	front_car.wheels[0].suspensionRestLength = suspensionRestLength;
	front_car.wheels[0].radius = wheel_radius;
	front_car.wheels[0].width = wheel_width;
	front_car.wheels[0].front = true;
	front_car.wheels[0].drive = true;
	front_car.wheels[0].brake = true;
	front_car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	front_car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius - 0.5);
	front_car.wheels[1].direction = direction;
	front_car.wheels[1].axis = axis;
	front_car.wheels[1].suspensionRestLength = suspensionRestLength;
	front_car.wheels[1].radius = wheel_radius;
	front_car.wheels[1].width = wheel_width;
	front_car.wheels[1].front = true;
	front_car.wheels[1].drive = true;
	front_car.wheels[1].brake = true;
	front_car.wheels[1].steering = true;

	front_truck = App->physics->AddVehicle(front_car);
	front_truck->SetPos(0, 0, 0);

	// trailer properties ----------------------------------------
	trailer_car.chassis_size.Set(3, 3, 6);
	trailer_car.chassis_offset.Set(0, 2, 0);
	trailer_car.mass = 500.0f;
	trailer_car.suspensionStiffness = 15.88f;
	trailer_car.suspensionCompression = 0.83f;
	trailer_car.suspensionDamping = 0.88f;
	trailer_car.maxSuspensionTravelCm = 1000.0f;
	trailer_car.frictionSlip = 50.5;
	trailer_car.maxSuspensionForce = 6000.0f;

	// Don't change anything below this line ------------------

	half_width = trailer_car.chassis_size.x*0.5f;
	half_length = trailer_car.chassis_size.z*0.5f;

	trailer_car.num_wheels = 6;
	trailer_car.wheels = new Wheel[6];

	// FRONT-LEFT ------------------------
	trailer_car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius + 1.5);
	trailer_car.wheels[0].direction = direction;
	trailer_car.wheels[0].axis = axis;
	trailer_car.wheels[0].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[0].radius = wheel_radius;
	trailer_car.wheels[0].width = wheel_width;
	trailer_car.wheels[0].front = false;
	trailer_car.wheels[0].drive = false;
	trailer_car.wheels[0].brake = false;
	trailer_car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	trailer_car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius + 1.5);
	trailer_car.wheels[1].direction = direction;
	trailer_car.wheels[1].axis = axis;
	trailer_car.wheels[1].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[1].radius = wheel_radius;
	trailer_car.wheels[1].width = wheel_width;
	trailer_car.wheels[1].front = false;
	trailer_car.wheels[1].drive = false;
	trailer_car.wheels[1].brake = false;
	trailer_car.wheels[1].steering = true;

	trailer_car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius - 2);
	trailer_car.wheels[2].direction = direction;
	trailer_car.wheels[2].axis = axis;
	trailer_car.wheels[2].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[2].radius = wheel_radius;
	trailer_car.wheels[2].width = wheel_width;
	trailer_car.wheels[2].front = false;
	trailer_car.wheels[2].drive = false;
	trailer_car.wheels[2].brake = false;
	trailer_car.wheels[2].steering = false;

	trailer_car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius - 2);
	trailer_car.wheels[3].direction = direction;
	trailer_car.wheels[3].axis = axis;
	trailer_car.wheels[3].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[3].radius = wheel_radius;
	trailer_car.wheels[3].width = wheel_width;
	trailer_car.wheels[3].front = false;
	trailer_car.wheels[3].drive = false;
	trailer_car.wheels[3].brake = false;
	trailer_car.wheels[3].steering = false;

	trailer_car.wheels[4].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius - 3);
	trailer_car.wheels[4].direction = direction;
	trailer_car.wheels[4].axis = axis;
	trailer_car.wheels[4].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[4].radius = wheel_radius;
	trailer_car.wheels[4].width = wheel_width;
	trailer_car.wheels[4].front = false;
	trailer_car.wheels[4].drive = false;
	trailer_car.wheels[4].brake = false;
	trailer_car.wheels[4].steering = false;

	trailer_car.wheels[5].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius - 3);
	trailer_car.wheels[5].direction = direction;
	trailer_car.wheels[5].axis = axis;
	trailer_car.wheels[5].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[5].radius = wheel_radius;
	trailer_car.wheels[5].width = wheel_width;
	trailer_car.wheels[5].front = false;
	trailer_car.wheels[5].drive = false;
	trailer_car.wheels[5].brake = false;
	trailer_car.wheels[5].steering = false;

	trailer = App->physics->AddVehicle(trailer_car);
	trailer->SetPos(0, 0, -5);


	Sphere s1(1);
	vehicle_sphere = App->physics->AddBody(s1);
	vehicle_sphere->SetPos(0, 3, 0);
	App->physics->AddConstraintHinge(*front_truck, *trailer, vec3(0, 2, -1), vec3(0, 2, 3), vec3(0,1,0), vec3(0,1,0), false);

	//App->physics->AddConstraintP2P(*vehicle_sphere, *front_truck, vec3(0, 4, 0), vec3(0, 4, 0));

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
	}

	front_truck->ApplyEngineForce(acceleration);
	front_truck->Turn(turn);
	front_truck->Brake(brake);

	front_truck->Render();
	char title[80];
	sprintf_s(title, "%.1f Km/h", front_truck->GetKmh());
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}



