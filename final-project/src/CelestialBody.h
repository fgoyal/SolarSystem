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
    ofSpherePrimitive object;
    double radius;
    double orbit;
    double orbit_radius;
    vector<ofQuaternion> rotations;
    
public:
    CelestialBody(string set_name, double set_radius, string set_image);
    ~CelestialBody();
    
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
        return object.getRadius();
    }
    
    ofSpherePrimitive GetObject() {
        return object;
    }
    
    ofTexture GetTexture() {
        return texture;
    }

};

#endif /* CelestialBody_h */
