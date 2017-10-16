#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	//m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";

	////Alberto needed this at this position for software recording.
	//m_pWindow->setPosition(sf::Vector2i(710, 0));
	
	//Set the position and target of the camera
	//(I'm at [0,0,10], looking at [0,0,0] and up is the positive Y axis)
	m_pCameraMngr->SetPositionTargetAndUp(AXIS_Z * 20.0f, ZERO_V3, AXIS_Y);

//if the light position is zero move it
if (m_pLightMngr->GetPosition(1) == ZERO_V3)
m_pLightMngr->SetPosition(vector3(0.0f, 0.0f, 3.0f));

//if the background is cornflowerblue change it to black (its easier to see)
if (vector3(m_v4ClearColor) == C_BLUE_CORNFLOWER)
{
	m_v4ClearColor = vector4(ZERO_V3, 1.0f);
}

//if there are no segments create 7
if (m_uOrbits < 1)
	m_uOrbits = 7;

float fSize = 1.0f; //initial size of orbits

//creating a color using the spectrum 
uint uColor = 650; //650 is Red
//prevent division by 0
float decrements = 250.0f / (m_uOrbits > 1 ? static_cast<float>(m_uOrbits - 1) : 1.0f); //decrement until you get to 400 (which is violet)
/*
	This part will create the orbits, it start at 3 because that is the minimum subdivisions a torus can have
*/
uint uSides = 3; //start with the minimal 3 sides

float rad = 0.95f; //first orbit radius

for (uint i = uSides; i < m_uOrbits + uSides; i++) //iterate through the orbits
{
	float theta = 0;
	//New stoplist with initial theta of 0
	std::vector<vector3> stops = std::vector<vector3>();

	//generate coords of stops using theta and the current radius (Z always const)
	for (int k = 0; k < i; k++) {
		float z = 0.0f; //const var

		float x = cos(theta) * rad;
		float y = sin(theta) * rad;

		//create new vec3 w points and add to stop list
		vector3 vec = vector3(x, y, z);
		stops.push_back(vec);

		//increment theta using radians and iterator
		theta += radians / (float)i;
	}

	//Add new list to overall list of stops
	orbitStops.push_back(stops);
	currentOrbitStop.push_back(0);
	vector3 v3Color = WaveLengthToRGB(uColor); //calculate color based on wavelength
	m_shapeList.push_back(m_pMeshMngr->GenerateTorus(fSize, fSize - 0.1f, 3, i, v3Color)); //generate a custom torus and add it to the meshmanager
	fSize += 0.5f; //increment the size for the next orbit
	rad += 0.5f; //Increment radius for next orbit
	uColor -= static_cast<uint>(decrements); //decrease the wavelength
}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix(); //view Matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix(); //Projection Matrix
	matrix4 m4Offset = IDENTITY_M4; //offset of the orbits, starts as the global coordinate system
	m4Offset = glm::rotate(IDENTITY_M4, 90.0f, AXIS_Z);

	/*
		 ____.____ ___.____    .___   _____    _______                ____.  _____    _______   ____ ___  _______________________  __.  _____
	|    |    |   \    |   |   | /  _  \   \      \              |    | /  _  \   \      \ |    |   \/   _____/\____    /    |/ _| /  _  \
	|    |    |   /    |   |   |/  /_\  \  /   |   \             |    |/  /_\  \  /   |   \|    |   /\_____  \   /     /|      <  /  /_\  \
/\__|    |    |  /|    |___|   /    |    \/    |    \        /\__|    /    |    \/    |    \    |  / /        \ /     /_|    |  \/    |    \
\________|______/ |_______ \___\____|__  /\____|__  /        \________\____|__  /\____|__  /______/ /_______  //_______ \____|__ \____|__  /
						  \/           \/         \/                          \/         \/                 \/         \/       \/       \/
	*/

	// draw a shapes
	for (uint i = 0; i < m_uOrbits; ++i)
	{
		m_pMeshMngr->AddMeshToRenderList(m_shapeList[i], glm::rotate(m4Offset, 90.0f, AXIS_X));
		int stop = currentOrbitStop[i];
		int nextStop = (stop + 1) % orbitStops[i].size(); //calculate next stop using the current stop

		//use lerp to calc position from the orbits current stop and the next stop
		vector3 v3CurrentPos = glm::lerp(orbitStops[i][stop], orbitStops[i][nextStop], lerpVal);
		matrix4 m4Model = glm::translate(m4Offset, v3CurrentPos);

		//draw spheres
		m_pMeshMngr->AddSphereToRenderList(m4Model * glm::scale(vector3(0.1)), C_WHITE);
	}
	lerpVal += 0.02f; //increment lerp progress
	//if lerp val is over or equal to 1, set it to 0 
	if (lerpVal >= 1.0f) {

		lerpVal = 0.0f;
		//iterate through current stops and advance them by 1
		for (int i = 0; i < currentOrbitStop.size(); i++){
			currentOrbitStop[i] = (currentOrbitStop[i] + 1) % orbitStops[i].size();
		}
	}
		
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}