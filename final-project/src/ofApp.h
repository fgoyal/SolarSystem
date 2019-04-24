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
        constexpr const static double kDampeningScalerRadius = 0.85;
        constexpr const static double kRadiusScaler = 0.0001;
        const static int kAvgRadius = 89703;
        constexpr const static double kDampeningScalerDistance = 0.75;
        constexpr const static double kDistanceScaler = 0.088;
        constexpr const static double kAvgDistance = 590.64;
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
        double distance[kNumCelestialBodies] = {0, 57.9, 50.3, 41.4, 78.3, 550.7, 654.9, 1439, 1622.6, 1411.3};
        string textures[kNumCelestialBodies] = {"sun.jpg", "mercury.jpg", "venus.gif", "earth.jpg", "mars.png", "jupiter.jpg", "saturn.jpg", "uranus.jpg", "neptune.jpg", "pluto.jpg"};
    //    ofSpherePrimitive celestial_bodies[10] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
        vector<CelestialBody> celestial_bodies;
		
};
