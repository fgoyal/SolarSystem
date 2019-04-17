#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSpherePrimitive sun;
    ofSpherePrimitive mercury;
    ofSpherePrimitive venus;
    ofSpherePrimitive earth;
    ofSpherePrimitive mars;
    ofSpherePrimitive saturn;
    ofSpherePrimitive jupiter;
    ofSpherePrimitive neptune;
    ofSpherePrimitive uranus;
    ofSpherePrimitive pluto;
    ofLight light;
    ofTexture mTexSun;
    ofTexture mTexMercury;
    ofTexture mTexVenus;
    ofTexture mTexEarth;
    ofTexture mTexMars;
    ofTexture mTexSaturn;
    ofTexture mTexJupiter;
    ofTexture mTexNeptune;
    ofTexture mTexUranus;
    ofTexture mTexPluto;
    ofTexture mTex;
    ofEasyCam cam;
    string textures[10] = {"sun.jpg", "mercury.jpg", "venus.gif", "earth.jpg", "mars.png", "jupiter.jpg", "saturn.jpg", "uranus.jpg", "neptune.jpg", "pluto.jpg"};
    ofSpherePrimitive celestial_bodies[10] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
		
};
