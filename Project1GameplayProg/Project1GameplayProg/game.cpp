#include "Game.h"

static bool flip;

game::game() : window(sf::VideoMode(800, 600), "Cube Game")
{
}

game::~game() {}

void game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
		window.clear();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[72];
GLubyte triangles[72];
//GLubyte triangles2[36];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;




void game::initialize()
{
	glewInit();
	isRunning = true;
	vertex[0].coordinate[0] = m_player1.v1.x;
	vertex[0].coordinate[1] = m_player1.v1.y;
	vertex[0].coordinate[2] = m_player1.v1.z;
							  
	vertex[1].coordinate[0] = m_player1.v2.x;
	vertex[1].coordinate[1] = m_player1.v2.y;
	vertex[1].coordinate[2] = m_player1.v2.z;
							  
	vertex[2].coordinate[0] = m_player1.v3.x;
	vertex[2].coordinate[1] = m_player1.v3.y;
	vertex[2].coordinate[2] = m_player1.v3.z;
							  
	vertex[3].coordinate[0] = m_player1.v4.x;
	vertex[3].coordinate[1] = m_player1.v4.y;
	vertex[3].coordinate[2] = m_player1.v4.z;
								
	vertex[4].coordinate[0] = m_player1.v5.x;
	vertex[4].coordinate[1] = m_player1.v5.y;
	vertex[4].coordinate[2] = m_player1.v5.z;
								 
	vertex[5].coordinate[0] = m_player1.v6.x;
	vertex[5].coordinate[1] = m_player1.v6.y;
	vertex[5].coordinate[2] = m_player1.v6.z;
								 
	vertex[6].coordinate[0] = m_player1.v7.x;
	vertex[6].coordinate[1] = m_player1.v7.y;
	vertex[6].coordinate[2] = m_player1.v7.z;
								 
	vertex[7].coordinate[0] = m_player1.v8.x;
	vertex[7].coordinate[1] = m_player1.v8.y;
	vertex[7].coordinate[2] = m_player1.v8.z;






	//second cube
	vertex[8].coordinate[0] = m_obstacle.v1.x;
	vertex[8].coordinate[1] = m_obstacle.v1.y;
	vertex[8].coordinate[2] = m_obstacle.v1.z;

	vertex[9].coordinate[0] = m_obstacle.v2.x;
	vertex[9].coordinate[1] = m_obstacle.v2.y;
	vertex[9].coordinate[2] = m_obstacle.v2.z;

	vertex[10].coordinate[0] = m_obstacle.v3.x;
	vertex[10].coordinate[1] = m_obstacle.v3.y;
	vertex[10].coordinate[2] = m_obstacle.v3.z;

	vertex[11].coordinate[0] = m_obstacle.v4.x;
	vertex[11].coordinate[1] = m_obstacle.v4.y;
	vertex[11].coordinate[2] = m_obstacle.v4.z;

	vertex[12].coordinate[0] = m_obstacle.v5.x;
	vertex[12].coordinate[1] = m_obstacle.v5.y;
	vertex[12].coordinate[2] = m_obstacle.v5.z;

	vertex[13].coordinate[0] = m_obstacle.v6.x;
	vertex[13].coordinate[1] = m_obstacle.v6.y;
	vertex[13].coordinate[2] = m_obstacle.v6.z;

	vertex[14].coordinate[0] = m_obstacle.v7.x;
	vertex[14].coordinate[1] = m_obstacle.v7.y;
	vertex[14].coordinate[2] = m_obstacle.v7.z;

	vertex[15].coordinate[0] = m_obstacle.v8.x;
	vertex[15].coordinate[1] = m_obstacle.v8.y;
	vertex[15].coordinate[2] = m_obstacle.v8.z;


	
	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 1.0f;
	vertex[6].color[1] = 0.0f;
	vertex[6].color[2] = 0.0f;

	vertex[7].color[0] = 0.0f;
	vertex[7].color[1] = 0.0f;
	vertex[7].color[2] = 1.0f;







	//second cube
	vertex[8].color[0] = 1.0f;
	vertex[8].color[1] = 1.0f;
	vertex[8].color[2] = 1.0f;
						 
	vertex[9].color[0] = 1.0f;
	vertex[9].color[1] = 1.0f;
	vertex[9].color[2] = 1.0f;
						 
	vertex[10].color[0] =1.0f;
	vertex[10].color[1] =1.0f;
	vertex[10].color[2] =1.0f;
						 
	vertex[11].color[0] =1.0f;
	vertex[11].color[1] =1.0f;
	vertex[11].color[2] =1.0f;
						 
	vertex[12].color[0] =1.0f;
	vertex[12].color[1] =1.0f;
	vertex[12].color[2] =1.0f;
						 
	vertex[13].color[0] =1.0f;
	vertex[13].color[1] =1.0f;
	vertex[13].color[2] =1.0f;
						 
	vertex[14].color[0] =1.0f;
	vertex[14].color[1] =1.0f;
	vertex[14].color[2] =1.0f;
						 
	vertex[15].color[0] =1.0f;
	vertex[15].color[1] =1.0f;
	vertex[15].color[2] =1.0f;

	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;

	triangles[3] = 0;   triangles[4] = 2;   triangles[5] = 3;

	triangles[6] = 1;   triangles[7] = 5;   triangles[8] = 6;

	triangles[9] = 1;   triangles[10] = 2;   triangles[11] = 6;

	triangles[12] = 3;   triangles[13] = 2;   triangles[14] = 6;

	triangles[15] = 3;   triangles[16] = 7;   triangles[17] = 6;

	triangles[18] = 0;   triangles[19] = 1;   triangles[20] = 5;

	triangles[21] = 0;   triangles[22] = 4;   triangles[23] = 5;

	triangles[24] = 4;   triangles[25] = 7;   triangles[26] = 6;

	triangles[27] = 4;   triangles[28] = 5;   triangles[29] = 6;

	triangles[30] = 0;   triangles[31] = 4;   triangles[32] = 7;

	triangles[33] = 0;   triangles[34] = 3;   triangles[35] = 7;


	//cube2
	triangles[36] = 8;   triangles[37] = 9;   triangles[38] = 10;

	triangles[39] = 8;   triangles[40] = 10;   triangles[41] = 11;

	triangles[42] = 9;   triangles[43] = 13;   triangles[44] = 14;

	triangles[45] = 9;   triangles[46] = 10;   triangles[47] = 14;

	triangles[48] = 11;   triangles[49] = 10;   triangles[50] = 14;

	triangles[51] = 11;   triangles[52] = 15;   triangles[53] = 14;

	triangles[54] = 8;   triangles[55] = 9;   triangles[56] = 13;

	triangles[57] = 8;   triangles[58] = 12;   triangles[59] = 13;

	triangles[60] = 12;   triangles[61] = 15;   triangles[62] = 14;

	triangles[63] = 12;   triangles[64] = 13;   triangles[65] = 14;

	triangles[66] = 8;   triangles[67] = 12;   triangles[68] = 15;

	triangles[69] = 8;   triangles[70] = 11;   triangles[71] = 15;




	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 72, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles2, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 72, triangles, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void game::update()
{
	m_player1.move();

	vertex[0].coordinate[0] = m_player1.v1.x;
	vertex[0].coordinate[1] = m_player1.v1.y;
	vertex[0].coordinate[2] = m_player1.v1.z;

	vertex[1].coordinate[0] = m_player1.v2.x;
	vertex[1].coordinate[1] = m_player1.v2.y;
	vertex[1].coordinate[2] = m_player1.v2.z;

	vertex[2].coordinate[0] = m_player1.v3.x;
	vertex[2].coordinate[1] = m_player1.v3.y;
	vertex[2].coordinate[2] = m_player1.v3.z;

	vertex[3].coordinate[0] = m_player1.v4.x;
	vertex[3].coordinate[1] = m_player1.v4.y;
	vertex[3].coordinate[2] = m_player1.v4.z;

	vertex[4].coordinate[0] = m_player1.v5.x;
	vertex[4].coordinate[1] = m_player1.v5.y;
	vertex[4].coordinate[2] = m_player1.v5.z;

	vertex[5].coordinate[0] = m_player1.v6.x;
	vertex[5].coordinate[1] = m_player1.v6.y;
	vertex[5].coordinate[2] = m_player1.v6.z;

	vertex[6].coordinate[0] = m_player1.v7.x;
	vertex[6].coordinate[1] = m_player1.v7.y;
	vertex[6].coordinate[2] = m_player1.v7.z;

	vertex[7].coordinate[0] = m_player1.v8.x;
	vertex[7].coordinate[1] = m_player1.v8.y;
	vertex[7].coordinate[2] = m_player1.v8.z;

}
	

void game::render()
{
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
	CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 72, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain
	model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	window.display();
	

}

void game::unload()
{
}
