#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	//m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";

	////Alberto needed this at this position for software recording.
	//m_pWindow->setPosition(sf::Vector2i(710, 0));

	//Make MyMesh object
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(2.0f, C_BROWN);

	//Make MyMesh object
	m_pMesh1 = new MyMesh();
	m_pMesh1->GenerateCube(1.0f, C_WHITE);

	for (int i = 0; i < 46; i++) {
		cubeArr[i] = new MyMesh();
		cubeArr[i]->GenerateCube(1.0f, C_BROWN);
	}
	cube0 = glm::translate(IDENTITY_M4, vector3(1.0f, 0.0f, 0.0f));
	cube1 = glm::translate(IDENTITY_M4, vector3(0.0f, 0.0f, 0.0f));
	cube2 = glm::translate(IDENTITY_M4, vector3(-1.0f, 1.0f, 0.0f));
	cube3 = glm::translate(IDENTITY_M4, vector3(-1.0f, 2.0f, 0.0f));
	cube4 = glm::translate(IDENTITY_M4, vector3(0.0f, 2.0f, 0.0f));
	cube5 = glm::translate(IDENTITY_M4, vector3(1.0f, 2.0f, 0.0f));
	cube6 = glm::translate(IDENTITY_M4, vector3(2.0f, 2.0f, 0.0f));
	cube7 = glm::translate(IDENTITY_M4, vector3(3.0f, 2.0f, 0.0f));
	cube8 = glm::translate(IDENTITY_M4, vector3(3.0f, 0.0f, 0.0f));
	cube9 = glm::translate(IDENTITY_M4, vector3(4.0f, 0.0f, 0.0f));
	cube10 = glm::translate(IDENTITY_M4, vector3(5.0f, 1.0f, 0.0f));
	cube11 = glm::translate(IDENTITY_M4, vector3(5.0f, 2.0f, 0.0f));
	cube12 = glm::translate(IDENTITY_M4, vector3(4.0f, 2.0f, 0.0f));
	cube13 = glm::translate(IDENTITY_M4, vector3(-3.0f, 3.0f, 0.0f));
	cube14 = glm::translate(IDENTITY_M4, vector3(-2.0f, 3.0f, 0.0f));
	cube15 = glm::translate(IDENTITY_M4, vector3(-1.0f, 3.0f, 0.0f));
	cube16 = glm::translate(IDENTITY_M4, vector3(0.0f, 3.0f, 0.0f));
	cube17 = glm::translate(IDENTITY_M4, vector3(1.0f, 3.0f, 0.0f));
	cube18 = glm::translate(IDENTITY_M4, vector3(2.0f, 3.0f, 0.0f));
	cube19 = glm::translate(IDENTITY_M4, vector3(3.0f, 3.0f, 0.0f));
	cube20 = glm::translate(IDENTITY_M4, vector3(4.0f, 3.0f, 0.0f));
	cube21 = glm::translate(IDENTITY_M4, vector3(5.0f, 3.0f, 0.0f));
	cube22 = glm::translate(IDENTITY_M4, vector3(6.0f, 3.0f, 0.0f));
	cube23 = glm::translate(IDENTITY_M4, vector3(7.0f, 3.0f, 0.0f));
	cube24 = glm::translate(IDENTITY_M4, vector3(-3.0f, 2.0f, 0.0f));
	cube25 = glm::translate(IDENTITY_M4, vector3(-3.0f, 1.0f, 0.0f));
	cube26 = glm::translate(IDENTITY_M4, vector3(7.0f, 2.0f, 0.0f));
	cube27 = glm::translate(IDENTITY_M4, vector3(7.0f, 1.0f, 0.0f));
	cube28 = glm::translate(IDENTITY_M4, vector3(-2.0f, 4.0f, 0.0f));
	cube29 = glm::translate(IDENTITY_M4, vector3(-1.0f, 4.0f, 0.0f));
	cube30 = glm::translate(IDENTITY_M4, vector3(1.0f, 4.0f, 0.0f));
	cube31 = glm::translate(IDENTITY_M4, vector3(2.0f, 4.0f, 0.0f));
	cube32 = glm::translate(IDENTITY_M4, vector3(3.0f, 4.0f, 0.0f));
	cube33 = glm::translate(IDENTITY_M4, vector3(5.0f, 4.0f, 0.0f));
	cube34 = glm::translate(IDENTITY_M4, vector3(6.0f, 4.0f, 0.0f));
	cube35 = glm::translate(IDENTITY_M4, vector3(-1.0f, 5.0f, 0.0f));
	cube36 = glm::translate(IDENTITY_M4, vector3(0.0f, 5.0f, 0.0f));
	cube37 = glm::translate(IDENTITY_M4, vector3(1.0f, 5.0f, 0.0f));
	cube38 = glm::translate(IDENTITY_M4, vector3(2.0f, 5.0f, 0.0f));
	cube39 = glm::translate(IDENTITY_M4, vector3(3.0f, 5.0f, 0.0f));
	cube40 = glm::translate(IDENTITY_M4, vector3(4.0f, 5.0f, 0.0f));
	cube41 = glm::translate(IDENTITY_M4, vector3(5.0f, 5.0f, 0.0f));
	cube42 = glm::translate(IDENTITY_M4, vector3(-1.0f, 7.0f, 0.0f));
	cube43 = glm::translate(IDENTITY_M4, vector3(0.0f, 6.0f, 0.0f));
	cube44 = glm::translate(IDENTITY_M4, vector3(4.0f, 6.0f, 0.0f));
	cube45 = glm::translate(IDENTITY_M4, vector3(5.0f, 7.0f, 0.0f));
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

	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	
	static matrix4 m4Model;
	m4Model = glm::translate(m4Model, vector3(0.05f, 0.0f, 0.0f));
	
	cubeArr[0]->Render(m4Projection, m4View, cube0 * m4Model);
	cubeArr[1]->Render(m4Projection, m4View, cube1* m4Model );
	cubeArr[2]->Render(m4Projection, m4View, cube2* m4Model );
	cubeArr[3]->Render(m4Projection, m4View, cube3* m4Model );
	cubeArr[4]->Render(m4Projection, m4View, cube4* m4Model );
	cubeArr[5]->Render(m4Projection, m4View, cube5* m4Model );
	cubeArr[6]->Render(m4Projection, m4View, cube6* m4Model );
	cubeArr[7]->Render(m4Projection, m4View, cube7* m4Model );
	cubeArr[8]->Render(m4Projection, m4View, cube8* m4Model );
	cubeArr[9]->Render(m4Projection, m4View, cube9* m4Model );
	cubeArr[10]->Render(m4Projection, m4View, cube10* m4Model);
	cubeArr[11]->Render(m4Projection, m4View, cube11* m4Model);
	cubeArr[12]->Render(m4Projection, m4View, cube12* m4Model);
	cubeArr[13]->Render(m4Projection, m4View, cube13* m4Model);
	cubeArr[14]->Render(m4Projection, m4View, cube14* m4Model);
	cubeArr[15]->Render(m4Projection, m4View, cube15* m4Model);
	cubeArr[16]->Render(m4Projection, m4View, cube16* m4Model);
	cubeArr[17]->Render(m4Projection, m4View, cube17* m4Model);
	cubeArr[18]->Render(m4Projection, m4View, cube18* m4Model);
	cubeArr[19]->Render(m4Projection, m4View, cube19* m4Model);
	cubeArr[20]->Render(m4Projection, m4View, cube20* m4Model);
	cubeArr[21]->Render(m4Projection, m4View, cube21* m4Model);
	cubeArr[22]->Render(m4Projection, m4View, cube22* m4Model);
	cubeArr[23]->Render(m4Projection, m4View, cube23* m4Model);
	cubeArr[24]->Render(m4Projection, m4View, cube24* m4Model);
	cubeArr[25]->Render(m4Projection, m4View, cube25* m4Model);
	cubeArr[26]->Render(m4Projection, m4View, cube26* m4Model);
	cubeArr[27]->Render(m4Projection, m4View, cube27* m4Model);
	cubeArr[28]->Render(m4Projection, m4View, cube28* m4Model);
	cubeArr[29]->Render(m4Projection, m4View, cube29* m4Model);
	cubeArr[30]->Render(m4Projection, m4View, cube30* m4Model);
	cubeArr[31]->Render(m4Projection, m4View, cube31* m4Model);
	cubeArr[32]->Render(m4Projection, m4View, cube32* m4Model);
	cubeArr[33]->Render(m4Projection, m4View, cube33* m4Model);
	cubeArr[34]->Render(m4Projection, m4View, cube34* m4Model);
	cubeArr[35]->Render(m4Projection, m4View, cube35* m4Model);
	cubeArr[36]->Render(m4Projection, m4View, cube36* m4Model);
	cubeArr[37]->Render(m4Projection, m4View, cube37* m4Model);
	cubeArr[38]->Render(m4Projection, m4View, cube38* m4Model);
	cubeArr[39]->Render(m4Projection, m4View, cube39* m4Model);
	cubeArr[40]->Render(m4Projection, m4View, cube40* m4Model);
	cubeArr[41]->Render(m4Projection, m4View, cube41* m4Model);
	cubeArr[42]->Render(m4Projection, m4View, cube42* m4Model);
	cubeArr[43]->Render(m4Projection, m4View, cube43* m4Model);
	cubeArr[44]->Render(m4Projection, m4View, cube44* m4Model);
	cubeArr[45]->Render(m4Projection, m4View, cube45* m4Model);
	/*m_pMesh->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), ToMatrix4(m_qArcBall));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3( 3.0f, 0.0f, 0.0f)));*/
		
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
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
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}
	SafeDelete(m_pMesh1);
	//release GUI
	ShutdownGUI();
}