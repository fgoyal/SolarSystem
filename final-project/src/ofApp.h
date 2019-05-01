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
    constexpr const static double kDampeningScalerRadius = 0.95;
    constexpr const static double kRadiusScaler = 0.0002;
    const static int kAvgRadius = 89703;
    constexpr const static double kDampeningScalerDistance = 0.75;
    constexpr const static double kDistanceScaler = 0.05;
    constexpr const static double kAvgDistance = 590.64;
    const static int kHelpPosition = 10;
    const static int kInfoPosition = 150;
    const static int kInfoLength = 180;
    ofLight light;
    ofEasyCam cam;
    ofImage background;

    string names[kNumCelestialBodies] = {"Sun", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    double diameters[kNumCelestialBodies] = {1391000, 4879, 12104, 12756, 6792, 142984, 120536, 51118, 49528, 2370};
    double distance[kNumCelestialBodies] = {0, 57.9, 50.3, 41.4, 78.3, 550.7, 654.9, 1439, 1622.6, 1411.3};
    double orbital_speed[kNumCelestialBodies] = {0, 47.87, 35.02, 29.78, 24.077, 13.07, 9.69, 6.81, 5.43, 4.67};
    double orbital_period[kNumCelestialBodies] = {0, 88, 224.7, 365.2, 687, 4331, 10747, 30589, 59800, 90560};
    string textures[kNumCelestialBodies] = {"sun.jpg", "mercury.jpg", "venus.gif", "earth.jpg", "mars.png", "jupiter.jpg", "saturn.jpg", "uranus.jpg", "neptune.jpg", "pluto.jpg"};
//    ofSpherePrimitive celestial_bodies[10] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
    vector<CelestialBody> celestial_bodies;
    
    
    bool show_help;
    bool show_names;
    bool show_radius;
    bool show_distances;
    bool show_speeds;
    bool show_periods;
    bool animate_orbits;
    void DrawHelp();
    void DrawInformationBox(int count, char type);

};
