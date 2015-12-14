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
	

	DrawMap();


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
	

	floor->Render();

	Road1.Render();
	Road2.Render();
	Road3.Render();
	Road4.Render();
	Road5.Render();
	Road6.Render();
	Road7.Render();
	Road8.Render();
	Road9.Render();
	Road10.Render();
	Road11.Render();
	Road12.Render();
	Road13.Render();
	Road14.Render();
	Road15.Render();
	Road16.Render();
	Road17.Render();
	Road18.Render();
	Road19.Render();
	Road20.Render();

	trailer_wall1.Render();

	Cylinder_1.Render();
	
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::DrawMap()
{
	floor = new Cube();
	floor->Scale(3000, 0.01, 3000);
	floor->color = Red;
	//App->physics->AddBody(*floor);

	Road1.color = Black;
	Road1.size.x = 20;
	Road1.size.y = 1;
	Road1.size.z = 100;
	Road1.SetPos(0, 19, 40);
	App->physics->AddBody(Road1, 0);

	Road2.color = Black;
	Road2.size.x = 20;
	Road2.size.y = 1;
	Road2.size.z = 40;
	Road2.SetRotation(-20, vec3(1.f, 0.f, 0.f));
	Road2.SetPos(0, 26, 109);
	App->physics->AddBody(Road2, 0);

	Road3.color = Black;
	Road3.size.x = 20;
	Road3.size.y = 1;
	Road3.size.z = 40;
	//Road3.SetRotation(-20, vec3(1.f, 0.f, 0.f));
	Road3.SetPos(0, 32, 180);
	App->physics->AddBody(Road3, 0);


	Road4.color = Black;
	Road4.size.x = 20;
	Road4.size.y = 1;
	Road4.size.z = 40;
	Road4.SetRotation(-20, vec3(0.f, 1.f, 0.f));
	Road4.SetPos(-6, 32, 215);
	App->physics->AddBody(Road4, 0);

	Road5.color = Black;
	Road5.size.x = 20;
	Road5.size.y = 1;
	Road5.size.z = 40;
	Road5.SetRotation(-30, vec3(0.f, 1.f, 0.f));
	Road5.SetPos(-22, 32, 248);
	App->physics->AddBody(Road5, 0);

	Road6.color = Black;
	Road6.size.x = 20;
	Road6.size.y = 1;
	Road6.size.z = 40;
	Road6.SetRotation(-50, vec3(0.f, 1.f, 0.f));
	Road6.SetPos(-45, 32, 276);
	App->physics->AddBody(Road6, 0);

	Road7.color = Black;
	Road7.size.x = 20;
	Road7.size.y = 1;
	Road7.size.z = 40;
	Road7.SetRotation(-70, vec3(0.f, 1.f, 0.f));
	Road7.SetPos(-75, 32, 294);
	App->physics->AddBody(Road7, 0);

	Road8.color = Black;
	Road8.size.x = 40;
	Road8.size.y = 1;
	Road8.size.z = 20;
	//Road8.SetRotation(-90, vec3(0.f, 1.f, 0.f));
	Road8.SetPos(-110, 32, 300);
	App->physics->AddBody(Road8, 0);
		
	Road9.color = Black;
	Road9.size.x = 40;
	Road9.size.y = 1;
	Road9.size.z = 20;
	Road9.SetRotation(-20, vec3(0.f, 0.f, 1.f));
	Road9.SetPos(-150, 39, 300);
	App->physics->AddBody(Road9, 0);


	Road10.color = Black;
	Road10.Scale(120, 1, 20);
	Road10.SetPos(50, 0.2, 290);
	App->physics->AddBody(Road10, 0);

	Road11.color = Black;
	Road11.Scale(20, 1, 40);
	Road11.SetPos(0, 0.2, 260);
	App->physics->AddBody(Road11, 0);

	Road12.color = Black;
	Road12.Scale(40, 1, 20);
	Road12.SetPos(-10, 0.2, 230);
	App->physics->AddBody(Road12, 0);

	Road13.color = Black;
	Road13.Scale(20, 1, 40);
	Road13.SetPos(-40, 0.2, 220);
	App->physics->AddBody(Road13, 0);

	Road14.color = Black;
	Road14.Scale(40, 1, 20);
	Road14.SetPos(-70, 0.2, 210);
	App->physics->AddBody(Road14, 0);

	Road15.color = Black;
	Road15.Scale(20, 1, 40);
	Road15.SetPos(-100, 0.2, 200);
	App->physics->AddBody(Road15, 0);

	Road16.color = Black;
	Road16.Scale(40, 1, 20);
	Road16.SetPos(-90, 0.2, 170);
	App->physics->AddBody(Road16, 0);

	Road17.color = Black;
	Road17.Scale(20, 1, 80);
	Road17.SetPos(-80, 0.2, 120);
	App->physics->AddBody(Road17, 0);

	Road18.color = Black;
	Road18.Scale(40, 1, 20);
	Road18.SetPos(-90, 0.2, 70);
	App->physics->AddBody(Road18, 0);

	Road19.color = Black;
	Road19.Scale(20, 1, 80);
	Road19.SetPos(-100, 0.2, 20);
	App->physics->AddBody(Road19, 0);

	Road20.color = Black;
	Road20.size = (3,2,5);
	Road20.SetPos(-50, 2.3f, -10);
	App->physics->AddBody(Road20, 0);

	Cylinder_1.color = Green;
	Cylinder_1.Scale(5, 1, 1);
	Cylinder_1.SetPos(-50, 0.5, 20);
	App->physics->AddBody(Cylinder_1, 0.f);
	
	s.size = vec3(5, 3, 1);
	s.SetPos(0, 2.5f, 20);

	sensor = App->physics->AddBody(s, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);
	App->player->Start();

	
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("HIT!");
	
}

