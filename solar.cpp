#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415

//tatkal
void circle(float R,float red,float green,float blue,float X ,float Y )
	{
		glColor3f(red,green,blue);
		double p,x=0,y=R;
		p=(5/4)-R;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2d(X,Y);
		while(x<=y)
		{
			glVertex2d(X+x,Y+y);
			glVertex2d(X+y,Y+x);
			glVertex2d(X-x,Y+y);
			glVertex2d(X+y,Y-x);
			glVertex2d(X-x,Y-y);
			glVertex2d(X-y,Y-x);
			glVertex2d(X+x,Y-y);
			glVertex2d(X-y,Y+x);
			if(p < 0)
			{
				x++;
				p += 2*x + 1;
			}
			else
			{
				x++;
				y--;
				p+= 2*x + 1 - 2*y;
			}
		}
		glEnd();
	}



	void ellipse(float rx, float ry,float red,float green,float blue,float cx ,float cy)
	{
		glColor3f(red,green,blue);
		glBegin(GL_POINTS);
		float x,y;
		x=0;
		y=ry;
		float p=ry*ry -rx*rx*ry +ry*ry*0.25;
		while(ry*ry*x<rx*rx*y)
		{
			x++;
			if(p<0)
			{
				p+= 2*ry*ry*x +ry*ry;
			}
			else
			{
				y--;
				p+=2*ry*ry*x-2*rx*rx*y+ry*ry;
			}
			glVertex2d(x+cx,y+cy);
			glVertex2d(x+cx,-y+cy);
			glVertex2d(-x+cx,y+cy);
			glVertex2d(-x+cx,-y+cy);
		}

		p=ry*ry*(x+0.5)*(x+0.5) + rx*rx*(y-1)*(y-1) -rx*rx*ry*ry;
		while(y>0){
			y--;
			if(p>0){
				p=p-2*rx*rx*y +rx*rx;
			}
			else{
				x++;
				p=p-2*rx*rx*y+2*ry*ry*x+rx*rx;
			}
			glVertex2d(x+cx,y+cy);
			glVertex2d(x+cx,-y+cy);
			glVertex2d(-x+cx,y+cy);
			glVertex2d(-x+cx,-y+cy);
		}

		glEnd();
	}


class glFunctions
{
public:
	void circle(float R,float red,float green,float blue,float X ,float Y )
	{
		glColor3f(red,green,blue);
		double p,x=0,y=R;
		p=(5/4)-R;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2d(X,Y);
		while(x<=y)
		{
			glVertex2d(X+x,Y+y);
			glVertex2d(X+y,Y+x);
			glVertex2d(X-x,Y+y);
			glVertex2d(X+y,Y-x);
			glVertex2d(X-x,Y-y);
			glVertex2d(X-y,Y-x);
			glVertex2d(X+x,Y-y);
			glVertex2d(X-y,Y+x);
			if(p < 0)
			{
				x++;
				p += 2*x + 1;
			}
			else
			{
				x++;
				y--;
				p+= 2*x + 1 - 2*y;
			}
		}
		glEnd();
	}



	void ellipse(float rx, float ry,float red,float green,float blue,float cx ,float cy)
	{
		glColor3f(red,green,blue);
		glBegin(GL_POINTS);
		float x,y;
		x=0;
		y=ry;
		float p=ry*ry -rx*rx*ry +ry*ry*0.25;
		while(ry*ry*x<rx*rx*y)
		{
			x++;
			if(p<0)
			{
				p+= 2*ry*ry*x +ry*ry;
			}
			else
			{
				y--;
				p+=2*ry*ry*x-2*rx*rx*y+ry*ry;
			}
			glVertex2d(x+cx,y+cy);
			glVertex2d(x+cx,-y+cy);
			glVertex2d(-x+cx,y+cy);
			glVertex2d(-x+cx,-y+cy);
		}

		p=ry*ry*(x+0.5)*(x+0.5) + rx*rx*(y-1)*(y-1) -rx*rx*ry*ry;
		while(y>0){
			y--;
			if(p>0){
				p=p-2*rx*rx*y +rx*rx;
			}
			else{
				x++;
				p=p-2*rx*rx*y+2*ry*ry*x+rx*rx;
			}
			glVertex2d(x+cx,y+cy);
			glVertex2d(x+cx,-y+cy);
			glVertex2d(-x+cx,y+cy);
			glVertex2d(-x+cx,-y+cy);
		}

		glEnd();
	}
};


class orbit
{
public:
	float x;
	float y;
};

class planet
{
private:
	float x;
	float y;
	float ang;
	float red ,green ,blue;
	float size;
	float rate;
	orbit orb;
	glFunctions gl;
public:
	planet ( float majorAxis , float minorAxis, float x , float y ,float rate , float size ,float red = 0 , float green = 0 , float blue = 0 ,float ang = 0)
	{
		this->x = x;
		this->y = y;
		this->ang  = ang;
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->rate = rate;
		this->size = size;
		this->orb.x = majorAxis;
		this->orb.y = minorAxis;
	}

	void getNextValue()
	{
		if(ang < 0 ) ang = 2 * PI;
		ang-=rate;
		x = orb.x * cos(ang) ;
		y =  orb.y * sin(ang);
	}

	void drawMe()
	{
		gl.ellipse(orb.x,orb.y,red,green,blue,0,0); 
		gl.circle(size,red,green,blue,x,y);
	}
};

planet mercury(400, 130 , -400 , 0 , 0.002, 45,1,0,0) , venus(500, 230 , - 500 , 0 , 0.0009, 70);
float venOrbX= 500 , venusX = -500, venOrbY =230 , venusY = 0 , venDx = 0.9;
float earthOrbX= 700 , earthX = -700, earthOrbY =400 , earthY = 0 , earthDx = 0.6;
float moonOrbX= 180 , moonOrbY =100  , moonDx = 5,moonX=-earthX-180,moonY=0;
float marsOrbX= 1000 , marsX = -1000, marsOrbY =580 , marsY = 0 , marsDx = 0.3;
float jupiterOrbX= 1400 , jupiterX = -1400, jupiterOrbY =750 , jupiterY = 0 , jupiterDx = 0.1;
float saturnOrbX= 1900 , saturnX = -1900, saturnOrbY =900 , saturnY = 0 , saturnDx = 0.09;
float uraOrbX= 2500 , uraX = -2500, uraOrbY =1100 , uraY = 0 , uraDx = 0.08;
float nepOrbX= 3200 , nepX = -3200, nepOrbY =1300 , nepY = 0 , nepDx = 0.06;





//getMoonValue(moonOrbX, moonOrbY , moonDx ,moonX, moonY, earthX , earthY);
void getMoonValue(float rx , float ry , float &th , float &currentX , float &currentY , float earthX , float earthY){
	if(th < 0) th = 2 * PI;
	th -= 0.001;
	currentX = rx * cos(th) + earthX;
	currentY = ry * sin(th) + earthY;

}

void getNextValue(float a , float b , float &dx , float &currentX , float &currentY, float rate)
{
	if(dx < 0 ) dx= 2 * PI;
	dx-=rate;
	currentX =a * cos(dx) ;
	currentY = b * sin(dx);
}



void display()
{
	float rj;

	glClear(GL_COLOR_BUFFER_BIT);

	circle(100,1,0.2,0,0,0); //sun
	mercury.drawMe();

	ellipse(venOrbX,venOrbY,1,0.4,0,0,0); //mecury orbit
	circle(70,1,0.4,0,venusX,venusY);//mercury

	ellipse(earthOrbX,earthOrbY,0.4,0.1,0.8,0,0); //earth orbit
	circle(80,0.4,0.1,1,earthX,earthY);//earth
    ellipse(moonOrbX,moonOrbY,0.2,1,1,earthX,earthY); //moon orbit
	circle(40,0.9,0.9,0.9,moonX,moonY);//moon

	ellipse(marsOrbX,marsOrbY,0.7,0.1,0,0,0); //mars orbit
	circle(60,0.7,0.1,0,marsX,marsY);//mars

    // if(marsY>0 && marsX>= -1000 && marsX<0){
    //     rj = -(marsX/15);
    //     if(rj<=30){
    //         rj=30;
    //     }
    //     circle(rj,0.7,0.1,0,marsX,marsY);//mars
    // }

    // else if(marsY>0 && marsX<= 1000 && marsX>=0){
    //     rj = (marsX/15);
    //     if(rj<=30){
    //         rj=30;
    //     }

    //    circle(rj,0.7,0.1,0,marsX,marsY);//mars
    // }

    // else if(marsY<0 && marsX<1400 && marsX>0){

    //     rj = marsY/5;
    //     rj=-rj;
    //     if(rj<=67){
    //         rj = 67;
    //     }

    //      circle(rj,0.7,0.1,0,marsX,marsY);//mars
    // }

    // else if(marsY<0 && marsX>-1400 && marsX<=0){
    //     rj = marsY/5;
    //     rj=-rj;
    //     if(rj<=67){
    //         rj=67;
    //     }

    //     circle(rj,0.7,0.1,0,marsX,marsY);//mars
    // }


	ellipse(jupiterOrbX,jupiterOrbY,1,1,0.2,0,0); //jupiter orbit
	circle(100,1,1,0.2,jupiterX,jupiterY);

    // if(jupiterY>0 && jupiterX>= -1400 && jupiterX<0){
    //     rj = -(jupiterX/7);
    //     if(rj<=30){
    //         rj=30;
    //     }
    //             if(rj>=200){
    //         rj=200;
    //     }

    //     circle(rj,1,1,0.2,jupiterX,jupiterY);//jupiter
    // }

    // else if(jupiterY>0 && jupiterX<= 1400 && jupiterX>=0){
    //     rj = (jupiterX/7);
    //     if(rj<=30){
    //         rj=30;
    //     }
    //     if(rj>=200){
    //         rj=200;
    //     }
    //     circle(rj,1,1,0.2,jupiterX,jupiterY);//jupiter
    // }

    // else if(jupiterY<0 && jupiterX<1400 && jupiterX>0){

    //     rj = jupiterY/5;
    //     rj=-rj;
    //     if(rj<=200){
    //         rj = 200;
    //     }
    //     circle(rj,1,1,0.2,jupiterX,jupiterY);//jupiter
    // }

    // else if(jupiterY<0 && jupiterX>-1400 && jupiterX<=0){
    //     rj = jupiterY/5;
    //     rj=-rj;
    //     if(rj<=t){
    //         rj=200;
    //     }
    //     circle(rj,1,1,0.2,jupiterX,jupiterY);//jupiter
    // }


	ellipse(saturnOrbX,saturnOrbY,0.9,0.8,0.3,0,0); //saturn orbit
	circle(70,0.9,0.8,0.4,saturnX,saturnY);//saturn
	ellipse(70+100,70/3,0.9,0.8,0.5,saturnX,saturnY);
	ellipse(70+150,70/2,0.9,0.8,0.5,saturnX,saturnY);
	   //  if(saturnY>0 && saturnX>= -1900 && saturnX<0){
    //     rj = -(saturnX/15);
    //     if(rj<=30){
    //         rj=30;
    //     }


    //     circle(rj,0.9,0.8,0.4,saturnX,saturnY);//saturn
    //     ellipse(rj+100,rj/3,0.9,0.8,0.5,saturnX,saturnY);
    //     ellipse(rj+150,rj/2,0.9,0.8,0.5,saturnX,saturnY);
    // }

    // else if(saturnY>0 && saturnX<= 1900 && saturnX>=0){
    //     rj = (saturnX/15);
    //     if(rj<=30){
    //         rj=30;
    //     }

    //     circle(rj,0.9,0.8,0.4,saturnX,saturnY);//saturn
    //     ellipse(rj+100,rj/3,0.9,0.8,0.5,saturnX,saturnY);
    //     ellipse(rj+150,rj/2,0.9,0.8,0.5,saturnX,saturnY);
    // }

    // else if(saturnY<0 && saturnX<1900 && saturnX>0){

    //     rj = saturnY/4;
    //     rj=-rj;
    //     if(rj<=127){
    //         rj = 127;
    //     }
    //     if(rj>=190){
    //         rj=190;
    //     }
    //     circle(rj,0.9,0.8,0.4,saturnX,saturnY);//saturn
    //     ellipse(rj+100,rj/3,0.9,0.8,0.5,saturnX,saturnY);
    //     ellipse(rj+150,rj/2,0.9,0.8,0.5,saturnX,saturnY);
    // }
    // else if(saturnY<0 && saturnX>=-1900 && saturnX<=0){
    //     rj = saturnY/4;
    //     rj=-rj;
    //     if(rj<=127){
    //         rj=127;
    //     }
    //     if(rj>=190){
    //         rj=190;
    //     }

    //     circle(rj,0.9,0.8,0.4,saturnX,saturnY);//saturn
    //     ellipse(rj+100,rj/3,0.9,0.8,0.5,saturnX,saturnY);
    //     ellipse(rj+150,rj/2,0.9,0.8,0.5,saturnX,saturnY);
    // }




	ellipse(uraOrbX,uraOrbY,0.5,0.9,0.4,0,0); //ura orbit
	circle(100,0.5,0.9,0.3,uraX,uraY);//mars

	ellipse(nepOrbX,nepOrbY,0.5,0.1,1,0,0); //nep orbit
	circle(75,0.6,0.1,1,nepX,nepY);//nep




	glFlush();

}

void animation()
{
	mercury.getNextValue();
	getNextValue(venOrbX, venOrbY , venDx , venusX , venusY,-0.0009);
	getNextValue(earthOrbX, earthOrbY , earthDx , earthX , earthY,0.0005);
	getNextValue(marsOrbX, marsOrbY , marsDx , marsX , marsY,0.0008);
	getNextValue(jupiterOrbX, jupiterOrbY , jupiterDx , jupiterX , jupiterY,0.0009);
	getNextValue(saturnOrbX, saturnOrbY , saturnDx , saturnX , saturnY,0.0008);
	getNextValue(uraOrbX, uraOrbY , uraDx , uraX , uraY,0.0004);
	getNextValue(nepOrbX, nepOrbY , nepDx , nepX , nepY,0.0001);
	getMoonValue(moonOrbX, moonOrbY , moonDx ,moonX, moonY, earthX , earthY);
	display();
}
void init(void)
{
	glClearColor (0.1, 0, 0.1, 0.0);
	
	gluOrtho2D(-3300,3300,-4000,4000);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Solar System ");
	init ();
	glutDisplayFunc(display);
	glutIdleFunc(animation);
	glutMainLoop();
	return 0;
}
