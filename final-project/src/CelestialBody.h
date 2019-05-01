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
    double real_radius;
    double orbital_speed;
    double orbital_period;
    ofQuaternion rotation;
    double distance_from_sun;
    ofVec3f center;
    ofVec3f position;
    
public:
    CelestialBody(const string _name, const double _scaled_radius, const double _real_radius, const string _image, const double _orbital_speed, const double _orbital_period, const double _distance_from_sun);
    
//    void SetTexture(string set_image);
//    void SetPosition(ofVec3f set_position);
    void draw(bool show_labels, bool show_radiuses);
    void ShowNames();
    void ShowRadiuses();
    
    string GetName() {
        return name;
    }
    
    ofQuaternion GetRotations() {
        return rotation;
    }
    
    double GetRadius() {
        return planet_body.getRadius();
    }
    
    ofSpherePrimitive GetObject() {
        return planet_body;
    }
    
    ofTexture GetTexture() {
        return texture;
    }

};

#endif /* CelestialBody_h */
