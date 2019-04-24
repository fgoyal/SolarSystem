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
    ofImage texture;
    string image;
    ofSpherePrimitive planet_body;
    double radius;
    double orbit;
    double orbit_radius;
    vector<ofQuaternion> rotations;
    ofVec3f position;
    
public:
    CelestialBody(const string set_name, const double set_radius, const string set_image, ofVec3f set_position);
    
    void SetTexture(string set_image);
    void SetPosition(ofVec3f set_position);
    
    string GetName() {
        return name;
    }
    
    double GetOrbit() {
        return orbit;
    }
    
    double GetOrbitRadius() {
        return orbit_radius;
    }
    
    vector<ofQuaternion> GetRotations() {
        return rotations;
    }
    
    double GetRadius() {
        return planet_body.getRadius();
    }
    
    ofSpherePrimitive GetObject() {
        return planet_body;
    }
    
    ofImage GetTexture() {
        return texture;
    }

};

#endif /* CelestialBody_h */
