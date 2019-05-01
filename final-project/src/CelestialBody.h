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
    string name;
    ofTexture texture;
    string image;
    ofSpherePrimitive planet_body;
    double scaled_radius;
    double real_radius;
    double orbit;
    double orbit_radius;
    double rotation_period;
    ofQuaternion rotations;
    double position;
    
public:
    CelestialBody(const string _name, const double _scaled_radius, const double _real_radius, const string _image, const double _rotation_period, const double _position, const ofQuaternion _rotation);
    
//    void SetTexture(string set_image);
//    void SetPosition(ofVec3f set_position);
    void draw(bool show_labels, bool show_radiuses);
    void ShowNames();
    void ShowRadiuses();
    
    string GetName() {
        return name;
    }
    
    double GetOrbit() {
        return orbit;
    }
    
    double GetOrbitRadius() {
        return orbit_radius;
    }
    
    ofQuaternion GetRotations() {
        return rotations;
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
