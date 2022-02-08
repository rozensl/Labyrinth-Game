// include libraries
#include "colour.h"
#include "material.h"

Material::Material()
{
    // default values
    this->ambient = Colour(0.2f, 0.2f, 0.2f, 1.0f);
    this->diffuse = Colour(0.8f, 0.8f, 0.8f, 1.0f);
    this->specular = Colour(0.0f, 0.0f, 0.0f, 1.0f);
    this->shininess = 0.0f;
}

Material::Material(Colour ambient, Colour diffuse, Colour specular, float shininess)
{
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
}

Material::Material(char colour){
    if (colour == 'r'){
        this->ambient = Colour(0.1, 0.05, 0.05, 1.0); //Reddish-green ambient colour
        this->diffuse = Colour(0.5, 0.25, 0.15, 1.0); //Reddish-green diffuse
        this->specular = Colour(0.5, 0.35, 0.25, 1.0); //Weak white highlights
        this->shininess = 10; }
    else if (colour == 'g') {
        this->ambient = Colour(0.15, 0.15, 0.05, 1.0); //Reddish-green ambient colour
        this->diffuse = Colour(0.45, 0.45, 0.25, 1.0); //Reddish-green diffuse
        this->specular = Colour(0.35, 0.5, 0.20, 1.0); //Weak white highlights
        this->shininess = 10; }
    else if (colour == 'b'){
        this->ambient = Colour(0.05, 0.05, 0.15, 1.0); //Reddish-green ambient colour
        this->diffuse = Colour(0.25, 0.25, 0.45, 1.0); //Reddish-green diffuse
        this->specular = Colour(0.2, 0.30, 0.50, 1.0); //Weak white highlights
        this->shininess = 10;         
    }
    else if (colour == 'w'){
        this->ambient = Colour(1, 0.95, 0.80, 1.0); //Reddish-green ambient colour
        this->diffuse = Colour(1, 1, 1, 1.0); //Reddish-green diffuse
        this->specular = Colour(1, 1, 1, 1.0); //Weak white highlights
        this->shininess = 0;
    }
    else {
        this->ambient = Colour(0.05, 0.05, 0.05, 1.0); //Reddish-green ambient colour
        this->diffuse = Colour(0.5, 0.5, 0.5, 1.0); //Reddish-green diffuse
        this->specular = Colour(1, 1, 1, 1.0); //Weak white highlights
        this->shininess = 10.0;
    }
}