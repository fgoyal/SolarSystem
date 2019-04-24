#pragma once

#include "ofMain.h"
#include "CelestialBody.h"
#include <vector>

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
    
    private:
        const static int kNumCelestialBodies = 10;
        constexpr const static double kRadiusScaler = 0.001;
        constexpr const static double kDistanceScaler = 0.086;
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
        ofTexture mTexEarth;
        ofTexture mTex;
        ofEasyCam cam;
    
        string names[kNumCelestialBodies] = {"Sun", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
        double diameters[kNumCelestialBodies] = {1391000/5, 4879, 12104, 12756, 6792, 142984, 120536, 51118, 49528, 2370};
        double distance_from_sun[kNumCelestialBodies] = {0, 57.9, 108.2, 149.6, 227.9, 778.6, 1433.5, 2872.5, 4495.1, 5906.4};
        string textures[kNumCelestialBodies] = {"sun.jpg", "mercury.jpg", "venus.gif", "earth.jpg", "mars.png", "jupiter.jpg", "saturn.jpg", "uranus.jpg", "neptune.jpg", "pluto.jpg"};
    //    ofSpherePrimitive celestial_bodies[10] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
        vector<CelestialBody> celestial_bodies;
		
};
