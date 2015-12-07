#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	floor = new Cube();
	floor->Scale(300, 0.5, 300);
	floor->color = Green;
	//App->physics->AddBody(*floor);

	Road1.color = Black;
	Road1.Scale(10, 1, 40);
	Road1.SetPos(0, 0.2, 0);
	App->physics->AddBody(Road1, 0);

	Road2.color = Black;
	//Road2.SetRotation(15, vec3(0, 1, 0));
	Road2.Scale(40, 1, 10);
	
	Road2.SetPos(15, 0.2, 25);
	App->physics->AddBody(Road2, 0);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	delete floor;

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	floor->Render();

	Road1.Render();
	Road2.Render();
	
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

