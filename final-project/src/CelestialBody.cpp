//
//  CelestialBody.cpp
//  final-project
//
//  Created by Fiza Goyal on 4/16/19.
//

#include <CelestialBody.h>

CelestialBody::CelestialBody(const string set_name, const double set_radius, const string set_image, const ofVec3f set_position) {
    name = set_name;
    radius = set_radius;
    image = set_image;
    position = set_position;
    
    ofLoadImage(texture, image);
    planet_body.setRadius(radius);
    planet_body.setPosition(set_position);
    
}

//void CelestialBody::SetTexture(string set_image) {
//    texture.loadImage(set_image);
//}
//
//void CelestialBody::SetPosition(ofVec3f set_position) {
//    planet_body.setPosition(set_position);
//}
