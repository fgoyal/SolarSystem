//
//  CelestialBody.h
//  final-project
//
//  Created by Fiza Goyal on 4/16/19.
//

#ifndef CelestialBody_h
#define CelestialBody_h

#include "ofMain.h"

class CelestialBody {
private:
    constexpr const static double kPi = 3.1415;
    const static int kAngles = 360;
    
    string name;
    ofTexture texture;
    string image;
    ofSpherePrimitive planet_body;
    double scaled_radius;
    double orbital_speed;
    double orbital_period;
    ofQuaternion rotation;
    double distance_from_sun;
    ofVec3f center;
    ofVec3f position;
    
public:
    /**
     * Constructor for Celestial Body
     * @param _name - name of planet
     * @param _scaled_radius - scaled radius of planet in km
     * @param _image - path of planet texture
     * @param _orbital_speed - orbital speed of planet in km/s
     * @param _orbital_period - orbital period of planet in days
     * @param _distance_from_sun - distance from the sun
     */
    CelestialBody(const string _name, const double _scaled_radius, const string _image, const double _orbital_speed, const double _orbital_period, const double _distance_from_sun);
    
    /**
     * Create the planet with the texture wrapped around it
     * @param show_labels - true if planet names are displayed with planet
     * @param animate_orbits - true if animation is shown
     */
    void draw(bool show_labels, bool animate_orbits);
    
    /**
     * Returns position of planets.
     * If animated, uses ofQuaternion to move planet around sun
     * If not animated, returns distance from sun
     * @param animate_orbits - true if animation is shown
     */
    ofVec3f GetPosition(bool animate_orbits);
    
    /**
     * Displays planet names above planet object
     */
    void ShowNames();

};

#endif /* CelestialBody_h */
